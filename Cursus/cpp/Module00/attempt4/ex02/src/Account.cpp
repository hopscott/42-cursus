/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:32:55 by swillis           #+#    #+#             */
/*   Updated: 2022/10/16 23:04:58 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

Account::Account( int initial_deposit ) {
	
	_nbAccounts++;
	_amount = 0;
	makeDeposit(initial_deposit);
	return;
}

Account::~Account( void ) {
	
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

	for (int i=0; i<getNbAccounts(); i++) {
		_displayTimestamp();
		std::cout << " index:" << i \
					<< ";amount:" << checkAmount() \
					<< ";deposits:" << getNbDeposits() \
					<< ";withdrawals:" << getNbWithdrawals() \
					<< std::endl;
	}
}

void	Account::makeDeposit( int deposit ) {
	
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
}

int		Account::checkAmount( void ) const {

	return (_amount);
}

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() \
				<< ";total:" << getTotalAmount() \
				<< ";deposits:" << getNbDeposits() \
				<< ";withdrawals:" << getNbWithdrawals() \
				<< std::endl;
}

void	Account::_displayTimestamp( void ) {

    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
	std::cout << "[" << (now->tm_year + 1900) << (now->tm_mon + 1) << now->tm_mday << "]";
}
