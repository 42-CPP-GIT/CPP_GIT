/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:02:39 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/02 17:01:12 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#define		MSG_INDEX		" index:"
#define		MSG_NB_ACCOU	" accounts:"
#define		MSG_AMOUN		";amount:"
#define		MSG_DEPOS		";deposits:"
#define		MSG_WITHD		";withdrawal:"
#define		MSG_NB_DEPOS	";nb_deposits:"
#define		MSG_TOTAL		";total:"
#define		MSG_CREATE		";created"
#define		MSG_CLOSE		";closed"

int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;


Account::Account(int initial_deposit) {
	const std::time_t now = std::time(nullptr);

	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;

	 if (strftime(buf, sizeof buf, "%a %b %e %H:%M:%S %Y\n", std::localtime(&now))) {
            std::cout << std::setw(40) << "    strftime %a %b %e %H:%M:%S %Y" << buf;
        }
	std::cout << 
				<< MSG_INDEX << this->_accountIndex \
				<< MSG_AMOUN << initial_deposit \
				<< MSG_CREATE << std::endl;
}

Account::~Account(void) {
	std::cout << MSG_INDEX << this->_accountIndex \
			  << MSG_AMOUN << this->_amount \
		 	  << MSG_CLOSE << std::endl;
}

void	makeDeposit(int deposit) {
	(void)deposit;
}

bool	makeWithdrawal(int withdrawal) {
	(void)withdrawal;
	return (false);
}

// int		checkAmount(void) const {
//
// }
//
// void	displayStatus(void) const {
//
// }
