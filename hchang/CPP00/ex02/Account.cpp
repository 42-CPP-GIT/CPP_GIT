/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:18:04 by hchang            #+#    #+#             */
/*   Updated: 2022/11/03 12:01:34 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  this->_accountIndex = _nbAccounts;
  this->_amount = initial_deposit;
  _totalAmount += this->_amount;

  Account::_displayTimestamp();
  std::cout << " index:" << this->_accountIndex;
  std::cout << ";amount:" << this->_amount << ";created" << std::endl;

  _nbAccounts++;
}

Account::~Account(void) {
  Account::_displayTimestamp();
  std::cout << " index:" << this->_accountIndex;
  std::cout << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos() {
  Account::_displayTimestamp();

  std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
  Account::_displayTimestamp();

  this->_nbDeposits++;
  _totalNbDeposits++;
  this->_amount += deposit;
  _totalAmount += deposit;
  std::cout << " index:" << this->_accountIndex
            << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit
            << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();

  if (withdrawal > this->_amount) {
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << this->_amount << ";withdrawal:refused"
              << std::endl;
    return (false);
  } else {
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << this->_amount + withdrawal
              << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbDeposits << std::endl;
    return (true);
  }
}

int Account::checkAmount(void) const { return (_amount); }

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::getNbAccounts(void) { return (_nbAccounts); }

int Account::getTotalAmount(void) { return (_totalAmount); }

int Account::getNbDeposits(void) { return (_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void Account::_displayTimestamp(void) {
  char buffer[26];
  time_t timer = time(NULL);
  struct tm *t = localtime(&timer);

  std::strftime(buffer, 26, "[%Y%m%d_%H%M%S]", t);
  std::cout << buffer;
}
