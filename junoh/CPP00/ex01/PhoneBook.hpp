/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:32:40 by junoh             #+#    #+#             */
/*   Updated: 2022/11/10 13:34:51 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "Contact.hpp"

enum dataInfo {
    F_NAME,
    L_NAME,
    N_NAME,
    P_NUM,
    D_SECRET
};

std::string getlineWithNoEof(const std::string& str);

class PhoneBook
{
    private :
        int cnt_;
        int idx_;
        Contact contact_[8];
         
    public :
        PhoneBook();
        void    setIdx(int idx);
        void    setCnt(int cnt);
        int     getIdx(void);
        int     getCnt(void);
        void    displayPhoneBook(void);
        void    addContact(const std::string *strs, int idx);
        void    add(void);
        void    search(void);
        int    searchByIndex(void);    
        ~PhoneBook();  
};

# endif