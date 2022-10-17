/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:32:55 by swillis           #+#    #+#             */
/*   Updated: 2022/10/17 23:21:26 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
				<< ";amount:" << checkAmount() \
				<< ";created" << std::endl;
	_totalAmount += _amount;
	return;
}

Account::~Account( void ) {
	
	_nbAccounts--;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
				<< ";amount:" << checkAmount() \
				<< ";closed" << std::endl;
	return;
}

int	Account::getNbAccounts( void ) {
	
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {

	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	
	return (_totalNbDeposits);	
}

int	Account::getNbWithdrawals( void ) {
	
	return (_totalNbWithdrawals);		
}

void	Account::displayAccountsInfos( void ) {

	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() \
			<< ";total:" << getTotalAmount() \
			<< ";deposits:" << getNbDeposits() \
			<< ";withdrawals:" << getNbWithdrawals() \
			<< std::endl;
}

void	Account::makeDeposit( int deposit ) {
	
	int	p_amount = checkAmount();
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
				<< ";p_amount:" << p_amount \
				<< ";deposit:" << deposit \
				<< ";amount:" << checkAmount() \
				<< ";nb_deposits:" << _nbDeposits \
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	int	p_amount = checkAmount();

	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
				<< ";p_amount:" << p_amount;

	if (p_amount < withdrawal) {
		
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	
	std::cout << ";withdrawal:" << withdrawal \
				<< ";amount:" << checkAmount() \
				<< ";nb_withdrawals:" << _nbWithdrawals \
				<< std::endl;

	return (true);
}

int		Account::checkAmount( void ) const {

	return (_amount);
}

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
				<< ";amount:" << checkAmount() \
				<< ";deposits:" << _nbDeposits \
				<< ";withdrawals:" << _nbWithdrawals \
				<< std::endl;
}

void	Account::_displayTimestamp( void ) {

    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
	std::cout << "[" << (now->tm_year + 1900) << (now->tm_mon + 1) << now->tm_mday \
				<< "_" << now->tm_hour << now->tm_min << now->tm_sec << "]";
	// std::cout << "[19920104_091532]";
}
