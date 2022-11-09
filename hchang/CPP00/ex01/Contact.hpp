/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:29:13 by hchang            #+#    #+#             */
/*   Updated: 2022/10/31 18:35:47 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP_
# define CONTACT_HPP_

#include <string>

class Contact
{
private:
    std::string	_firstName;
    std::string	_lastName;
    std::string	_nickName;
    std::string	_phoneNumber;
    std::string	_darkestSecret;
public:
    void    setFirstName(std::string str);
    void    setLastName(std::string str);
    void    setNickName(std::string str);
    void    setPhoneNumber(std::string str);
    void    setDarketSecret(std::string str);
    std::string	getFirstName(void);
    std::string	getLastName(void);
    std::string	getNickName(void);
    std::string	getPhoneNumber(void);
    std::string	getDarketSecret(void);
};

# endif
