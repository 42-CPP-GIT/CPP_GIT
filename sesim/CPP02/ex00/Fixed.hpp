/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:01:32 by sesim             #+#    #+#             */
/*   Updated: 2022/11/10 13:13:57 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					fixed_point_num_;
		static const int	fractional_bits_ = 8;
	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed&	operator=(const Fixed& obj);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		~Fixed();
};

#endif
