/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:06:50 by jinypark          #+#    #+#             */
/*   Updated: 2022/10/28 15:31:01 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 
	<< "accounts:" << getNbAccounts() 
	<< ";total:" << getTotalAmount() 
	<< ";deposits:" << getNbDeposits() 
	<< ";withdrawals:" << getNbWithdrawals() 
	<< std::endl;
}

Account::Account(void)
{

}


Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = getNbAccounts();
	++_nbAccounts;
	this->_amount = initial_deposit;
	this->_totalAmount += _amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout 
	<< "index:" << _accountIndex
	<< ";amount:" << checkAmount()
	<< ";created"
	<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout 
	<< "index:" << _accountIndex 
	<< ";amount:" << checkAmount() 
	<< ";closed" 
	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout 
	<< "index:" << _accountIndex 
	<< ";p_amount:" << checkAmount() 
	<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	std::cout 
	<< ";amount:" << checkAmount() 
	<< ";nb_deposits:" << _nbDeposits 
	<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout 
	<< "index:" << _accountIndex 
	<< ";p_amount:" << checkAmount();
	if (checkAmount() < withdrawal)
	{
		std::cout << ";withdrawal:refused" 
		<< std::endl;
		return (false);
	}
	std::cout 
	<< ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout 
	<< ";amount:" << checkAmount() 
	<< ";nb_withdrawals:" << _nbWithdrawals 
	<< std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout 
	<< "index:" << _accountIndex 
	<< ";amount:" << checkAmount() 
	<< ";deposits:" << _nbDeposits 
	<< ";withdrawals:" << _nbWithdrawals 
	<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t		temp;
	struct tm*	timeinfo;

    time(&temp);
    timeinfo = localtime(&temp);
    std::cout << "[" << 1900 + timeinfo->tm_year;
	std::cout << std::setfill('0') << std::setw(2) << 1 + timeinfo->tm_mon;
	std::cout << std::setfill('0') << std::setw(2) << 1 + timeinfo->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_sec << "]";
}
