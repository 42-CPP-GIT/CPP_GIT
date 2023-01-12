/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:28:27 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/10 15:43:48 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <sstream>
#include <climits>

static int _countLeftBit(int raw_bit) {
	int cnt = 0;
	while (!(raw_bit & (1 << (31 - cnt))) && cnt++ < 32);
	return cnt;
}

static const Fixed	_checkTimes(const Fixed& a, const Fixed& b) {
	Fixed const res(a * b);
	if (a == 0 || a == 1 || b == 0 || b == 1)
		return res;
	std::stringstream equation;
	int a_bit = a > 0 ? a.getRawBits() : -a.getRawBits();
	int b_bit = b > 0 ? b.getRawBits() : -b.getRawBits();
	int left_space = _countLeftBit(a_bit);
	int max_b_bit = 31 - _countLeftBit(b_bit) - 8;
	if (left_space <= max_b_bit) {
		equation << "Error[1] : " << a << " * " << b << " = " << res;
		throw equation.str();
	}
	int res_bit = 0;
	for (int i = max_b_bit; i >= -8; --i) {
		if (!(b_bit & 1 << (i + 8)))
			continue ;
		const int add_val = bitShift(a_bit, i);
		if (res_bit > 0 && INT_MAX - res_bit < add_val) {
			equation << "Error[2] : " << a << " * " << b << " = " << res;
			throw equation.str();
		}
		b_bit &= ~(bitShift(0b100000000, i));
		res_bit += add_val;
	}
	const int compare_bit = res.getRawBits() > 0 \
								? res.getRawBits() : ~(res.getRawBits() - 1);
	if (_countLeftBit(res_bit) != _countLeftBit(compare_bit)) {
		equation << "Error[3] : " << a << " * " << b << " = |" << res << "| ≠ |" \
			<< (static_cast<float>(res_bit) / 256) << '|';
		throw equation.str();
	}
	return res;
}

static const Fixed	_checkMinus(const Fixed& a, const Fixed& b) {
	Fixed const res(a - b);
	std::stringstream equation;
	if ((a > 0 && b > 0 && (INT_MAX - a.getRawBits() < b.getRawBits()))
		|| (a < 0 && b > 0 && (a.getRawBits() - INT_MIN < b.getRawBits()))) {
		equation << "Error[4] : " << a << " - " << b << " = " << res;
		throw equation.str();
	}
	return res;
}

bool _isSameInequalityLine(Point const& point, Point const& start, \
							Point const& known, Point const& line) {
	Point const unknown(point.getX() - start.getX(), point.getY() - start.getY());
	try {
		Fixed const& val1(_checkMinus(_checkTimes(unknown.getY(), line.getX()) \
									, _checkTimes(unknown.getX(),  line.getY())));
		Fixed const& val2(_checkMinus(_checkTimes(known.getY(), line.getX()) \
									, _checkTimes(known.getX(),  line.getY())));
		// Another side || Point is on line || There is not triangle
		if (((val1.getRawBits() & BIT_SIGN) ^ (val2.getRawBits() & BIT_SIGN)) // XOR
			|| (-0.05f < val1.toFloat() && val1.toFloat() < 0.05f)
			|| (-0.05f < val2.toFloat() && val2.toFloat() < 0.05f))
			return false;
	}
	catch (const std::string& what) {
		std::cerr << what << " is overflow!" << std::endl;
		return false;
	}
	return true;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Point const a_b(a.getX() - b.getX(), a.getY() - b.getY());
	Point const b_c(b.getX() - c.getX(), b.getY() - c.getY());
	Point const c_a(c.getX() - a.getX(), c.getY() - a.getY());

	if (!_isSameInequalityLine(point, a, c_a, a_b)
		|| !_isSameInequalityLine(point, b, a_b, b_c)
		|| !_isSameInequalityLine(point, c, b_c, c_a))
		return false;
	return true;
}
