#include <iostream>
#include <iomanip>
#include <string>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);
	std::tm*	now = std::localtime(&t);

	std::cout << '[' << now->tm_year + 1900 
	<< std::setw(2) << std::setfill('0') << now->tm_mon + 1 
	<< std::setw(2) << std::setfill('0') <<	now->tm_mday << '_'
	<< std::setw(2) << std::setfill('0') << now->tm_hour
	<< std::setw(2) << std::setfill('0') << now->tm_min
	<< std::setw(2) << std::setfill('0') << now->tm_sec
	<< "] " << std::flush;
}

Account::Account( void )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout 
	<< "index:"		<< this->_accountIndex
	<< ";amount:"	<< this->_amount
	<< ";created"	<< std::endl;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout 
	<< "index:"		<< this->_accountIndex
	<< ";amount:"	<< this->_amount
	<< ";created"	<< std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout 
	<< "index:"	<< this->_accountIndex
	<< ";amount:"	<< this->_amount 
	<< ";closed"	<< std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos ( void )
{
	Account::_displayTimestamp();
	std::cout 
	<< "accounts:"		<< Account::getNbAccounts()
	<< ";total:"		<< Account::getTotalAmount()
	<< ";deposits:"		<< Account::getNbDeposits()
	<< ";withdrawals:"	<< Account::getNbWithdrawals()
	<< std::endl;
}

int Account::checkAmount( void ) const
{
	return(this->_amount);
}

void Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout
	<< "index:"		<< this->_accountIndex
	<< ";amount:"		<< this->_amount
	<< ";deposits"		<< this->_nbDeposits
	<< ";withdrawals"	<< this->_nbWithdrawals
	<< std::endl;
}

void Account::makeDeposit( int deposit )
{
	Account::_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout
	<< "index:"			<< this->_accountIndex
	<< ";p_amount:"		<< this->_amount
	<< ";deposit:"		<< deposit
	<< ";amount:"		<< this->_amount + deposit
	<< "nm_deposits:"	<< this->_nbDeposits++
	<< std::endl;
	this->_amount +=deposit;
}

bool Account::makeWithdrawal ( int withdrawal )
{
	bool resolution = false;

	if (withdrawal <= this->checkAmount())
		resolution = true;
	Account::_displayTimestamp();
	std::cout
	<< "index:"			<< this->_accountIndex
	<< ";p_amount;"		<< this->_amount
	<< ";withdrawal:"	<< std::flush;
	if (resolution)
	{
		std::cout << withdrawal
		<< ";amount:"			<< this->_amount - withdrawal
		<< ";nb_withdrawals:"	<< this->_nbWithdrawals++
		<< std::endl;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
	}
	else
		std::cout << "refused" << std::endl;
	return (resolution);
}