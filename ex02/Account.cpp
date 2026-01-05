/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:16:06 by marvin            #+#    #+#             */
/*   Updated: 2026/01/03 22:16:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	std::time_t	now;
	std::tm		*t;

	now = std::time(NULL);
	t = std::localtime(&now);
	std::cout << "["
		<< (t->tm_year + 1900)
		<< std::setw(2) << std::setfill('0') << (t->tm_mon + 1)
		<< std::setw(2) << std::setfill('0') << t->tm_mday
		<< "_"
		<< std::setw(2) << std::setfill('0') << t->tm_hour
		<< std::setw(2) << std::setfill('0') << t->tm_min
		<< std::setw(2) << std::setfill('0') << t->tm_sec
		<< "] ";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created\n";
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed\n";
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << "\n";
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << "\n";
}

void Account::makeDeposit(int deposit)
{
    int previous_amount;

    previous_amount = _amount;

    _amount += deposit;
    _nbDeposits++;

    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << previous_amount
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
    int previous_amount;

    previous_amount = _amount;

    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << previous_amount
                  << ";withdrawal:refused\n";
        return (false);
    }

    _amount -= withdrawal;
    _nbWithdrawals++;

    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << previous_amount
              << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << "\n";

    return (true);
}
