/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:02:39 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/09 13:31:48 by minsuki2         ###   ########.fr       */
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
#define		MSG_END			';'
#define		MSG_ENDL		'\n'

enum e_return { ERROR = -1, SUCCESS };

int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;

int	Account::getNbAccounts(void) { return (_nbAccounts); }
int	Account::getTotalAmount(void) { return (_totalAmount); }
int	Account::getNbDeposits(void) { return (_totalNbDeposits); }
int	Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

int		Account::checkAmount( void ) const {
	if (this->_amount < 0)
		return (ERROR);
	return (this->_amount);
}

static void	_msgExit(std::string msg) {
	std::cout << msg << std::endl;
	std::exit(1);
}

static void printRefused(void) {
	std::cout << MSG_REFUS << MSG_ENDL;
}

static bool checkError(const int target) {
	if (target < 0) {
		printRefused();
		return (false);
	}
	return (true);
}

Account::Account(int initial_deposit) {
	this->_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts++;
	if (Account::_nbAccounts < 1)
		Account::_nbAccounts = ERROR;
	this->_amount = initial_deposit;
	if (this->_amount > 0)
		this->_totalAmount += initial_deposit;

	std::cout << MSG_INDEX;
	if (checkError(this->_accountIndex) == false)
		return ;
	std::cout << this->_accountIndex << MSG_END;

	std::cout << MSG_AMOUN;
	if (checkError(this->_amount) == false)
		return ;
	std::cout << this->_amount << MSG_END;
	std::cout << MSG_CREATE << MSG_ENDL;
}

Account::~Account(void) {
	this->_displayTimestamp();

	std::cout << MSG_INDEX;
	if (checkError(this->_accountIndex) == false)
		return ;
	std::cout << this->_accountIndex << MSG_END;

	std::cout << MSG_AMOUN;
	if (checkError(this->_amount) == false)
		return ;
	std::cout << this->_amount << MSG_END;
	std::cout << MSG_CLOSE << MSG_ENDL;
}

void	Account::makeDeposit(int deposit) {
	this->_displayTimestamp();

	std::cout << MSG_INDEX;
	if (checkError(this->_accountIndex) == false)
		return ;
	std::cout << this->_accountIndex << MSG_END;

	std::cout << MSG_PREV << MSG_AMOUN;
	if (checkError(this->_amount) == false)
		return ;
	std::cout << this->_amount << MSG_END;

	std::cout << MSG_DEPOS;
	if (checkError(deposit) == false \
		|| checkError(this->_amount + deposit) == false)
		return ;
	std::cout << deposit << MSG_END;

	std::cout << MSG_AMOUN;
	if (checkError(Account::_totalAmount + deposit) == false)
		return ;
	std::cout << this->_amount + deposit << MSG_END;

	std::cout << MSG_NB_DEPOS;
	if (checkError(this->_nbDeposits + 1) == false
		|| checkError(Account::_totalNbDeposits + 1) == false)
		return ;
	std::cout << ++this->_nbDeposits << MSG_ENDL;

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	this->_displayTimestamp();

	std::cout << MSG_INDEX;
	if (checkError(this->_accountIndex) == false)
		return (false);
	std::cout << this->_accountIndex << MSG_END;

	std::cout << MSG_PREV << MSG_AMOUN;
	if (checkError(this->_amount) == false)
		return (false);
	std::cout << this->_amount << MSG_END;

	std::cout << MSG_WITHD;
	if (checkError(withdrawal) == false \
		|| checkError(this->_amount - withdrawal) == false)
		return (false);
	std::cout << withdrawal << MSG_END;

	std::cout << MSG_AMOUN;
	if (checkError(Account::_totalAmount - withdrawal) == false)
		return (false);
	std::cout << this->_amount - withdrawal << MSG_END;

	std::cout << MSG_NB_WITHD;
	if (checkError(this->_nbWithdrawals + 1) == false
		|| checkError(Account::_totalNbWithdrawals + 1) == false)
		return (false);
	std::cout << ++this->_nbWithdrawals << MSG_ENDL;

	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}


void	Account::displayStatus(void) const {
	this->_displayTimestamp();

	std::cout << MSG_INDEX;
	if (checkError(this->_accountIndex) == false)
		return ;
	std::cout << this->_accountIndex << MSG_END;

	std::cout << MSG_AMOUN;
	if (checkError(this->_amount) == false)
		return ;
	std::cout << this->_amount << MSG_END;

	std::cout << MSG_DEPOSS;
	if (checkError(this->_nbDeposits) == false)
		return ;
	std::cout << this->_nbDeposits << MSG_END;

	std::cout << MSG_WITHDS;
	if (checkError(this->_nbWithdrawals) == false)
		return ;
	std::cout << this->_nbWithdrawals << MSG_ENDL;
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();

	std::cout << MSG_NB_ACCOU;
	if (checkError(Account::_nbAccounts) == false)
		return ;
	std::cout << Account::_nbAccounts << MSG_END;

	std::cout << MSG_TOTAL;
	if (checkError(Account::_totalAmount) == false)
		return ;
	std::cout << Account::_totalAmount << MSG_END;

	std::cout << MSG_DEPOSS;
	if (checkError(Account::_totalNbDeposits) == false)
		return ;
	std::cout << Account::_totalNbDeposits << MSG_END;

	std::cout << MSG_WITHDS;
	if (checkError(Account::_totalNbWithdrawals) == false)
		return ;
	std::cout << Account::_totalNbWithdrawals << MSG_ENDL;
}

void	Account::_displayTimestamp(void) {
	const std::time_t now = std::time(NULL);
	char buf[18];

	if (!std::strftime(buf, BUFFER_SIZE, "[%Y%m%d_%H%M%S]", std::localtime(&now)))
		_msgExit("ERROR: strftime zero return");
#ifndef diff
	std::cout << std::setw(BUFFER_SIZE) << std::left << buf;
#else
	std::cout << std::setw(BUFFER_SIZE) << std::left << "[19920104_091532]";
#endif
}
