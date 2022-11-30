/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:08:00 by hchang            #+#    #+#             */
/*   Updated: 2022/11/30 18:54:09 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# define RESET "\033[0m"
# define IT "\e[0;3m"
# define RED "\e[0;31m"
# define GRN "\e[0;33m"

class Base
{
	public:
		virtual ~Base();
};

#endif
