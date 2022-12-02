/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:28:27 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/03 00:10:54 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <sstream>

int countLeftBit(int raw_bit) {
	int cnt = 0;
	while (!(raw_bit & (1 << (31 - cnt))) && cnt++ < 32);
	return cnt;
}

int bitShifting(int raw_bit, int cnt) {
	return cnt > 0 ? raw_bit << cnt : raw_bit >> -cnt;
}

const Fixed	checkTimes(const Fixed& a, const Fixed& b) {

	Fixed const res(a * b);
	if (a == 0 || b == 0)
		return res;
	int a_bit = a > 0 ? a.getRawBits() : -a.getRawBits();
	int b_bit = b > 0 ? b.getRawBits() : -b.getRawBits();

	std::cerr << "\n\na        : " << a << ' ' << static_cast<float>(a_bit)/256 << ' '<< std::bitset<32>(a_bit) << MSG_ENDL;
	std::cerr << "b        : " << b << ' ' << static_cast<float>(b_bit)/256 << ' ' << std::bitset<32>(b_bit) << MSG_ENDL;


	int left_space = countLeftBit(a_bit);
	int max_b_bit = 31 - countLeftBit(b_bit) - 8;
	std::cerr << "cnt_a : " << left_space << MSG_ENDL;
	std::cerr << "cnt_b : " << max_b_bit << MSG_ENDL;
	if (left_space < max_b_bit) {
		std::stringstream equation;
		equation << a << " * " << b << " = " << res;
		throw equation.str();
	}
	// b_bit = b > 0 ? b_bit : b.getRawBits() & INT_MAX;
	// b.getRawBits() & INT_MAX;
	int res_bit = 0;
	for (int i = 0; i < 32; ++i) {
		// std::cerr << "[inter " << i << ']'<< MSG_ENDL;
	std::cerr << "\nans       : " << std::bitset<32>(res.getRawBits()) << " => " << a << ' ' << b << ' ' << " = "<< res << MSG_ENDL;
		std::cerr << "res_bit   : " << std::bitset<32>(res_bit) << MSG_ENDL;
		std::cerr << "+         : " << std::bitset<32>(bitShifting(a_bit, max_b_bit)) << MSG_ENDL;
		std::cerr << "max_b_bit : " << max_b_bit << MSG_ENDL;
		std::cerr << "b_bit     : " << std::bitset<32>(b_bit) << MSG_ENDL;

		// INT_MIN - res_bit > INT_MIN + a.xx
		int tmp;
		if (INT_MAX - res_bit < (tmp = (max_b_bit) > 0 ? a.getRawBits() << max_b_bit : a.getRawBits() >> (max_b_bit))) {
			std::stringstream equation;
			equation << a << " * " << b << " = " << res;
			throw equation.str();
		}
		b_bit &= (max_b_bit - 1) >= 0 ? ~(0b100000000 << max_b_bit) : ~(0b100000000 >> max_b_bit);
		res_bit += a_bit << max_b_bit;
		max_b_bit = 31 - countLeftBit(b_bit) - 8;
	}
	// 234234 * 324234

	std::cerr << "res      : " << std::bitset<32>(res_bit) << " => " << res_bit << " => " << static_cast<float>(res_bit) / 256 << MSG_ENDL;
	std::cerr << "ans      : " << std::bitset<32>(res.getRawBits()) << " => " << a << ' ' << b << ' ' << " = "<< res << MSG_ENDL;
	return res;
}

bool _isSameInequalityLine(Point const& point, Point const& start, \
							Point const& known, Point const& line) {
	Point const unknown(point.getX() - start.getX(), point.getY() - start.getY());
	try {
		Fixed const& val1(checkTimes(unknown.getY(), line.getX()) - checkTimes(unknown.getX(),  line.getY()));
		Fixed const& val2(checkTimes(known.getY(), line.getX()) - checkTimes(known.getX(),  line.getY()));
		// Point is on line || There is not triangle || Another side
		if (val1 == 0 || val2 == 0
			|| ((val1.getRawBits() & BIT_SIGN) ^ (val2.getRawBits() & BIT_SIGN))) // XOR
			return false;
	}
	catch (std::string what) {
		std::cout << what << " is overflow!" << std::endl;
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
// # 1 그냥 나누기
	// if ((a != 0 && b != 0) && ((res.getRawBits() / b.getRawBits() != a.getRawBits()))) {
	//     std::cerr << a << " * " << b << " = " << a * b << " b != " << res << MSG_ENDL;
	//     std::stringstream equation;
	//     equation << a << " * " << b;
	//     std::string what(equation.str());
	//     throw what;
	// }

// # 2 범위에 나누기
	// if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
	//     if (b.getRawBits() > 0 ? b.getRawBits() : ~(b.getRawBits() - 1) > (INT_MAX / (a > 0 ? a.getRawBits() : ~(a.getRawBits() - 1)))) {
	// // std::cerr << a << " * " << b << " = " << a * b << " b != " << res << MSG_ENDL;
	//     }
	// }
	// else
	//     if (-b.getRawBits() > 0 ? b.getRawBits() : ~(b.getRawBits() - 1) < (INT_MIN / (a > 0 ? a.getRawBits() : ~(a.getRawBits() - 1)))) {
	//         equation << a << " * " << b << " = " << res;
	//         throw equation.str();
	//     }

	// INT_MAX >= a + b >= INT_MIN

	/*
	INT_MAX - a >= a :> INT_MAX - b < a
	INT_MIN - a <= a :> INT_MIN - b > a

	a + b > INT_MIN
	300 + 3234234234 < INT_MAX
	INT_MAX - 300 > 3234234234(양수)
	300 + -2147394023 > INT_MIN
	INT_MIN + 300 < 2147394023(음수)
	b > 0 ... INT_MAX - a < a

	b < 0 ... INT_MIN - a > a

	0b1111
	b & BIT_SIGN

	a + b <= INT_MAX + +
	a + b >= INT_MIN - -
	INT_MAX - a >= b 	 INT_MAX - a < b			a > only 0    b 모두 가능ㅗ ... 1
	a >= INT_MIN + b     a < INT_MIN + b			a 모두 가능   b > 0			... 2

	- a + b > INT_MIN


	내가 음수면
	INT_MAX + a < b

	쟤가 음수면
	a < INT_MIN - b

	부호 다르면 판단 필요 없음
	+를 판단 - 내가 음수면 판단 할 필요 X
			   내가 양수인데 쟤가 양수일때?




	(1 - 2 * (b_bit & BIT_SIGN)) * ;
	+

		*/

			// || (res_bit < 0 && -res_bit > (a.getRawBits() << max_b_bit))) {
