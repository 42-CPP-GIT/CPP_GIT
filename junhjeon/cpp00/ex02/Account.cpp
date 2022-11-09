/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:56:40 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/03 17:57:40 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	time_t	timer;
	struct tm* t;
	char	buffer[18];

	timer = time(NULL);
	t = localtime(&timer);
	strftime(buffer, 15, "%Y%m%d_%H%M%S", t);
	std::cout << "[" << buffer << "] ";
}

void	Account::makeDeposit(int n)
{
	_nbDeposits ++;
	_totalNbDeposits ++;
	_totalAmount += n;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << n \
		<< ";amount:" << _amount + n << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += n;
}

bool	Account::makeWithdrawal(int n)
{
	if (_amount < n)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex <<";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_displayTimestamp();
		_nbWithdrawals ++;
		_totalAmount -= n;
		_totalNbWithdrawals ++;
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << n \
			<< ";amount:" << _amount - n << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_amount -= n;
		return (true);
	}
}

Account::Account(int n)
{
	_accountIndex = _nbAccounts;
	_amount	= n;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts ++;
	_totalAmount += n;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount" << _amount << ";closed" << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << \
		";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << \
		";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
