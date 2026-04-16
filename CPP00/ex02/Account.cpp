/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:07:57 by tseche            #+#    #+#             */
/*   Updated: 2026/04/01 18:45:30 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(){return _nbAccounts;}
int Account::getTotalAmount(){return _totalAmount;}
int Account::getNbDeposits(){return _totalNbDeposits;}
int Account::getNbWithdrawals(){return _totalNbWithdrawals;}
int Account::checkAmount() const {return this->_amount;}

Account::Account(int depo){
	this->_accountIndex = _nbAccounts;
	this->_amount = depo;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += depo;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << depo << ";created\n" << std::flush; 
}

Account::~Account(){
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl; 
}

bool	Account::makeWithdrawal(int withdrawal){
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (this->checkAmount() < withdrawal)
	{
		std::cout << ";withdrawal:refused\n" << std::flush;
		return (false);
	}
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

void Account::makeDeposit(int depo){
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";p_amount:" << this->_amount
				<< ";deposit:" << depo << std::flush;
	this->_amount += depo;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += depo;
	std::cout	<< ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

void Account::displayStatus() const {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl; 
}

void Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount 
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl; 
}

void Account::_displayTimestamp()
{
	time_t tv;
	char	buff[20];
	time(&tv);
	strftime(buff, 20, "%Y%m%d_%H%M%S", std::localtime(&tv));
	std::cout << "[" << buff << "] " << std::flush;
}
