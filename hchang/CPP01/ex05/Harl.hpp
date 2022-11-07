/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:00:33 by hchang            #+#    #+#             */
/*   Updated: 2022/11/05 16:24:54 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
#define HARL_HPP_

#include <iostream>

class Harl
{
  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

  public:
  	void (Harl::*f[4])(void);
    void complain(std::string level);
};

#endif