#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account (int initial_deposit)
{
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _totalAmount = initial_deposit;
    _amount = initial_deposit;
    _nbWithdrawals = 0;
    _nbDeposits = 0;

    this->_displayTimestamp();
}

Account::~Account(void)
{

}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();

    std::cout << "Number of accounts: " << _nbAccounts << std::endl;
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
        std::cout << "Withdrawal refused. Your balance is low. ";
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

}

void	Account::_displayTimestamp( void )
{
    std::time_t result = std::time(NULL);

    std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&result)->tm_year
                << std::setw(2) << 1 + std::localtime(&result)->tm_mon
                <<  std::setw(2) << std::localtime(&result)->tm_mday
                <<  "_"
                <<  std::setw(2) << std::localtime(&result)->tm_hour
                <<  std::setw(2) << std::localtime(&result)->tm_min
                <<  std::setw(2) << std::localtime(&result)->tm_sec 
                << "] " << std::flush;
    std::cout << std::endl;
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

