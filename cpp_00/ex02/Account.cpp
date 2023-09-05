#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

//initializing static variables 
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account (int initial_deposit)
{
    this->_displayTimestamp();

    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _totalAmount = initial_deposit;
    _amount = initial_deposit;
    _nbWithdrawals = 0;
    _nbDeposits = 0;
}

Account::~Account(void)
{
    std::cout << "Account "<< this->_accountIndex << " destroyed!" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();

    std::cout << std::endl << "Number of accounts: " << _nbAccounts << std::endl;
    std::cout << "Total Amount: " << _totalAmount << std::endl;
    std::cout << "Number of deposits: " << _totalNbDeposits << std::endl;
    std::cout << "Number of withdrawals: " << _totalNbWithdrawals << std::endl;

}

void	Account::makeDeposit(int deposit)
{
    this->_displayTimestamp();
    
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    this->_displayTimestamp();

    if(withdrawal > checkAmount())
    {
        std::cout << std::endl << "Withdrawal refused. Your balance is low." << std::endl;
        return (false);
    }
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    _amount -= withdrawal;

    return(true);
}

int		Account::checkAmount(void) const
{
    return _amount; 
}

void	Account::displayStatus(void) const
{
    this->_displayTimestamp();

    std::cout << std::endl << "--- Account Status --- " << std::endl; 
    std::cout << "Account index: " << _accountIndex << std::endl;
    std::cout << "Amount: " << _amount << std::endl;
    std::cout << "Deposits: " << _nbDeposits << std::endl;
    std::cout << "Withdrawals: " << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t currentTime = std::time(NULL);
    std::tm *timeInfo = std::localtime(&currentTime);

    std::cout << "[" << timeInfo->tm_year + 1900
              << timeInfo->tm_mon
              << timeInfo->tm_mday << "_"
              << timeInfo->tm_hour
              << timeInfo->tm_min
              << timeInfo->tm_sec << "]";
}

// private attributes
int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
    return _totalAmount;
}

int	Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

