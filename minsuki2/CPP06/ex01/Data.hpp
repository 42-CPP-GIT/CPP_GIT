/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:57:47 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/20 22:22:57 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>
struct Data {
	std::string		name_;
	Data(const std::string& name_);
	Data(const Data& obj);
	Data&	operator=(const Data& obj);
	~Data(void);
};

#endif
