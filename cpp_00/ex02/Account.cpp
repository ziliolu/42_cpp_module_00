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
    this->_displayTimestamp();

    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _nbWithdrawals = 0;
    _nbDeposits = 0;
    std::cout << " index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';' << "created" << std::endl;
}

Account::~Account(void)
{
    this->_displayTimestamp();
    std::cout << " index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';' << "closed" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();

    std::cout << " accounts:" << _nbAccounts << ';';
    std::cout << "total:" << _totalAmount << ';';
    std::cout << "deposits:" << _totalNbDeposits << ';';
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    this->_displayTimestamp();

    std::cout << " index:" << _accountIndex << ';';
    std::cout << "p_amount:" << _amount << ';';

    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;

    std::cout << "deposit:" << deposit << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    this->_displayTimestamp();

    std::cout << " index:" << _accountIndex << ';';
    std::cout << "p_amount:" << _amount << ';';
    if(withdrawal > checkAmount())
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    _amount -= withdrawal;
    std::cout << "withdrawal:" << withdrawal << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "nb_withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
    return(true);
}

int		Account::checkAmount(void) const
{
    return _amount; 
}

void	Account::displayStatus(void) const
{
    this->_displayTimestamp();

    std::cout << " index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "deposits:" << _nbDeposits << ';';
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
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

