/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:42:27 by junoh             #+#    #+#             */
/*   Updated: 2022/11/11 15:08:50 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

static std::string _checkLength(std::string str){
    if (str.length() <= 10){
        return (str);
    }
    else{
        return (str.substr(0, 9) + '.');
    }
}

static void displayInfo(void){
    std::cout << std::setw(10);
    std::cout << "Index" << '|';
    std::cout << std::setw(10);
    std::cout << "FirstName" << '|';
    std::cout << std::setw(10);
    std::cout << "LastName" << '|';
    std::cout << std::setw(10);
    std::cout << "NickName" << '|';
    std::cout << std::endl;
}

void    PhoneBook::displayPhoneBook(void){
    displayInfo();
    for (int i = 0; i < this->getCnt(); i++){
        std::cout << std::setw(10);
        std::cout << i << '|';
        std::cout << std::setw(10);
        std::cout << _checkLength(this->contact_[i].getFirstName()) << '|';
        std::cout << std::setw(10);
        std::cout << _checkLength(this->contact_[i].getLastName()) << '|';
        std::cout << std::setw(10);
        std::cout << _checkLength(this->contact_[i].getNickName()) << '|';
        std::cout << std::endl;
    }
}

void    PhoneBook::addContact(const std::string *strs, int idx){
    this->contact_[idx].setFirstName(strs[F_NAME]);
    this->contact_[idx].setLastName(strs[L_NAME]);
    this->contact_[idx].setNickName(strs[N_NAME]);
    this->contact_[idx].setPhoneNumber(strs[P_NUM]);
    this->contact_[idx].setDarkestSecret(strs[D_SECRET]);
    return;
}

std::string    getlineWithNoEof(const std::string& msg){
    std::string str;
    
    do{
        std::cout << msg;
        if (!std::getline(std::cin, str)){
            std::cin.clear();
            std::clearerr(stdin);
            std::cout << "EOF : ERROR. Do it again" << std::endl;
        }
    } while(str.empty());
    return (str);
}

static int isStrDigit(std::string& str){
    for (size_t len = 0; len < str.length(); len++){
        if (!std::isdigit(str.at(len)))
        {
            std::cout << "Not a number. Do it again" << std::endl;
            return (1);
        }
    }
    return (0);
}

void PhoneBook::add(void){
    std::string strs[5];

    strs[F_NAME] = getlineWithNoEof("What is First_name : ");
    strs[L_NAME] = getlineWithNoEof("What is your last_name : ");
    strs[N_NAME] = getlineWithNoEof("What is your Nick_name : ");
    do{
        strs[P_NUM] = getlineWithNoEof("What is your phone_number : ");
    }while (isStrDigit(strs[P_NUM]));
    strs[D_SECRET] = getlineWithNoEof("What is your Darkest_secret : ");
    this->setIdx((this->getIdx() + 1) % 8);
    this->setCnt(this->getCnt() + (this->getCnt() < 8));
    addContact(strs, this->idx_);
}

int PhoneBook::searchByIndex(void){
    std::string strIdx;
    
    do{
        strIdx = getlineWithNoEof("Input index for search : ");
    }while(isStrDigit(strIdx));
    std::stringstream s(strIdx);
    int i = 0;
    s >> i;
    if (i >= this->getCnt() ){
        std::cout << "Wrong Index. Do it again" << std::endl;
        return (1);
    }
    std::cout << "Index: " << i << std::endl;
	std::cout << "First name: " << this->contact_[i].getFirstName() << std::endl;
	std::cout << "Last name: "  << this->contact_[i].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contact_[i].getNickName() << std::endl;
	std::cout << "Phone number: " << this->contact_[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contact_[i].getDarkestSecret() << std::endl;
    return (0);
}

void PhoneBook::search(void){
    if (!PhoneBook::getCnt()){
        std::cout << "You are not ready to search" << std::endl;
        return ;
    }
    displayPhoneBook();
    while(searchByIndex())
        ;
    return;        
}