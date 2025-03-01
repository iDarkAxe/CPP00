/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:26:51 by ppontet           #+#    #+#             */
/*   Updated: 2025/03/01 10:17:43 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

static void print_number_on_twodigit(int number);

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * @brief Construct a new Account:: Account object
 * It's a private constructor so it can't be called 'normally'
 * 
 */
Account::Account(void)
{
	this->_accountIndex = Account::_nbAccounts;
	
	Account::_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

/**
 * @brief Make a withdrawal from the account
 * 
 * @param withdrawal amount to withdraw
 * @return true if the withdrawal isn't possible
 * @return false if the withdrawal is possible
 */
bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amout:" << this->_amount << ";withdrawal:refused" << std::endl;
		return (0);
	}
	else
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		return (1);
	}
}

/**
 * @brief Display the timestamp
 * Uses the notation [YYYYMMDD_HHMMSS]
 * So it displays the current date and time
 * It add's a 0 if the number is less than 10
 */
void Account::_displayTimestamp(void)
{
	std::string str;
	std::time_t result;
	std::tm *time;

	result = std::time(NULL);
	time = std::localtime(&result);
	std::cout << "[";
	
	std::cout << time->tm_year  + 1900;
	print_number_on_twodigit(time->tm_mon + 1);
	print_number_on_twodigit(time->tm_mday);
	std::cout << "_";
	print_number_on_twodigit(time->tm_hour);
	print_number_on_twodigit(time->tm_min);
	print_number_on_twodigit(time->tm_sec);
	std::cout << "] ";
}

/**
 * @brief Simple functions that prints a number on two digits
 * 
 * @param number number to print
 */
static void print_number_on_twodigit(int number)
{
	if (number < 10)
		std::cout << "0";
	std::cout << number;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}
