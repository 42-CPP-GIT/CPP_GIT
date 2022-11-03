/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:02:39 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/03 20:11:30 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#define		BUFFER_SIZE		18
#define		MSG_INDEX		"index:"
#define		MSG_NB_ACCOU	"accounts:"
#define		MSG_PREV		"p_"
#define		MSG_AMOUN		"amount:"
#define		MSG_DEPOS		"deposit:"
#define		MSG_WITHD		"withdrawal:"
#define		MSG_DEPOSS		"deposits:"
#define		MSG_WITHDS		"withdrawals:"
#define		MSG_NB_DEPOS	"nb_deposits:"
#define		MSG_NB_WITHD	"nb_withdrawals:"
#define		MSG_TOTAL		"total:"
#define		MSG_CREATE		"created"
#define		MSG_CLOSE		"closed"
#define		MSG_REFUS		"refused"

int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;

int	Account::getNbAccounts(void) { return (_nbAccounts); }
int	Account::getTotalAmount(void) { return (_totalAmount); }
int	Account::getNbDeposits(void) { return (_totalNbDeposits); }
int	Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout << MSG_NB_ACCOU << Account::_nbAccounts << ';' \
				<< MSG_TOTAL << Account::_totalAmount << ';' \
				<< MSG_DEPOSS << Account::_totalNbDeposits << ';' \
				<< MSG_WITHDS << Account::_totalNbWithdrawals << std::endl;
}

static void	_msg_exit(std::string msg) {
	std::cout << msg << std::endl;
	std::exit(1);
}

Account::Account(int initial_deposit) {
	this->_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts++;
	this->_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	std::cout << MSG_INDEX << this->_accountIndex << ';' \
				<< MSG_AMOUN << initial_deposit << ';' \
				<< MSG_CREATE << std::endl;
}

Account::~Account(void) {
	this->_displayTimestamp();
	std::cout << MSG_INDEX << _accountIndex << ';'\
				<< MSG_AMOUN << _amount << ';'\
				<< MSG_CLOSE << std::endl;
}

void	Account::makeDeposit(int deposit) {
	this->_displayTimestamp();
	std::cout << MSG_INDEX << _accountIndex << ';' \
				<< MSG_PREV << MSG_AMOUN << _amount << ';' \
				<< MSG_DEPOS << deposit << ';';
	if (deposit <= 0) {
		std::cout << MSG_REFUS << '\n';
		return ;
	}
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << MSG_AMOUN << this->_amount << ';'\
				<< MSG_NB_DEPOS << ++this->_nbDeposits << '\n';
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {

	this->_displayTimestamp();
	std::cout << MSG_INDEX << _accountIndex << ';' \
				<< MSG_PREV << MSG_AMOUN << _amount << ';' \
				<< MSG_WITHD;
	if (withdrawal <= 0 || this->_amount < withdrawal) {
		std::cout << MSG_REFUS << '\n';
		return (false);
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << withdrawal << ';';
	std::cout << MSG_AMOUN << this->_amount << ';'\
				<< MSG_NB_WITHD << ++this->_nbWithdrawals << '\n';
	_totalNbWithdrawals++;
	return (true);
}



void	Account::displayStatus(void) const {
	this->_displayTimestamp();
	std::cout << MSG_INDEX << this->_accountIndex << ';' \
				<< MSG_AMOUN << this->_amount << ';'\
				<< MSG_DEPOSS << this->_nbDeposits << ';' \
				<< MSG_WITHDS << this->_nbWithdrawals << std::endl;
}

// void	Account::checkAmount(void) const {
// }

void	Account::_displayTimestamp(void) {
	const std::time_t now = std::time(nullptr);
	char buf[18];
	if (!std::strftime(buf, BUFFER_SIZE, "[%Y%m%d_%H%M%S]", std::localtime(&now)))
		_msg_exit("ERROR: strftime wront return");
#ifndef diff
	std::cout << std::setw(BUFFER_SIZE) << std::left << buf;
#else
	std::cout << std::setw(BUFFER_SIZE) << std::left << "[19920104_091532]";
#endif
}

