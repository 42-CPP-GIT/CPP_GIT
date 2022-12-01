/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:33:26 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/10 10:02:13 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
	int					numVal;
	static const int	fracBits = 8;
public:
	Fixed();
	Fixed(const Fixed &obj);
	~Fixed();
	Fixed	&operator=(Fixed const &obj);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

