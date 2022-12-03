/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:53:44 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/23 13:45:11 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>

bool	is_inf(float f)
{
	if ((*(int32_t*)(&f) & 0x7f800000) == 0x7f800000)
		return (true);
	if ((*(int32_t*)(&f) & 0xff800000) == 0xff800000)
		return (true);
	return (false);
}

bool isOverflow(char *s)
{
	double d = std::atof(s);
	if (d > 2147483647.00000 || d < -2147483648.0000)
		return (true);
	return (false);
}

int main(int argc, char **argv)
{
	char	 c;
	float	 f;
	int	 	 i;
	double	 d;
	bool	nanFlag;
	bool	isinf;

	if ( argc < 2 )
		return (0);
	for (int k = 1; k < argc; k++)
	{
		nanFlag = false;
		isinf = false;

		i = std::atoi(argv[k]);
		if (std::strlen(argv[k]) == 1 && std::isdigit(argv[k][0]))
		{
			c = argv[k][0] - '0';
			i = static_cast<int> (c);
			f = static_cast<float> (i);
			d = static_cast<double> (i);
		}
		else if (std::strlen(argv[k]) == 1)
		{
			c = argv[k][0];
			i = static_cast<int> (c);
			f = static_cast<float> (i);
			d = static_cast<double> (i);
		}
		else
		{
			c = static_cast<char> (i);
			d = std::atof(argv[k]);
			f = static_cast<float>(d);
		}

		/*
		std::cout << c << std::endl;
		std::cout << i << std::endl;
		std::cout << f << std::endl;
		std::cout << d << std::endl;
		*/

		if (f != f)
			nanFlag = true;
		if (is_inf(f))
			isinf = true;
		
		//std::cout << "nanFlag : " << nanFlag << " isinf : " << isinf << std::endl;
		if (nanFlag || isinf)
			std::cout << "char : impossible" << std::endl;
		else if (i <= 255 && 20 <= i )
			std::cout << "char : " << "'" << c << "'" << std::endl;
		else
			std::cout << "char : Non displayable "<< std::endl;
		
		if (nanFlag || isinf || isOverflow(argv[k]))
			std::cout << "int : impossible" << std::endl;
		else
			std::cout << "int : " << i << std::endl;
		
		if (isinf)
			std::cout << "float : " << f << "f" << std::endl;
		else if (f - static_cast<float> (i) < std::numeric_limits<float>::epsilon())
			std::cout << "float : " << f << ".0f" << std::endl;
		else
			std::cout << "float : " << f << "f" << std::endl;

		if (isinf)
			std::cout << "double : " << d << std::endl;
		else if (d - static_cast<double> (i) < std::numeric_limits<double>::epsilon())
			std::cout << "double : " << d << ".0" << std::endl;
		else
			std::cout << "double : " << d << std::endl;
	}
	return (0);
}
