/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:18:04 by hchang            #+#    #+#             */
/*   Updated: 2022/10/26 23:42:53 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;	
	this->_amount = initial_deposit;
	
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";created" << std::endl;

	_nbAccounts++;
}

Account::~Account( void )
{

}

void	Account::displayAccountsInfos()
{
	
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	char buffer[26];
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);

	std::strftime(buffer, 26, "[%Y%m%d_%H%M%S]", t);
    std::cout << buffer;

	//std::cout << "[" << t->tm_year + 1900 << t->tm_mon + 1 << t->tm_mday;
	//std::cout << "_" << t->tm_hour << t->tm_min << t->tm_sec << "]";
}