/*
    Name: Teke Byas
    File: transactionlog.cpp
    Date of Creation: Thursday, November 8, 2018
    Description: This file implements a transaction log that will hold a vector
        of transactions and track statistics on them as well as print them
*/
#include "transactionlog.h"
#include <iostream>
#include <math.h> // fabs() needed for withdrawals to display properly (non-negative)

void Transactionlog::add_transaction(const Transaction &t)
{
    m_transactions.push_back(t);
}

double Transactionlog::min_daily_balance()
{
    double min_balance = m_transactions[0].get_balance();
    for(int i = 0; i < m_transactions.size(); i++)
    {
        if(min_balance > m_transactions[i].get_balance())
        {
            min_balance = m_transactions[i].get_balance();
        }
    }
    return min_balance;
}

double Transactionlog::average_daily_balance()
{
    double sum = 0.0;
    for(int i = 0; i < m_transactions.size(); i++)
        sum += m_transactions[i].get_balance();
    return sum / m_transactions.size();
}

double Transactionlog::get_interest()
{
    const double INTEREST_RATE = 1.005;

    return min_daily_balance() * INTEREST_RATE - min_daily_balance();
}

void Transactionlog::print()
{
    // used to print the first day separate because it does not have a day preceding it
    // "01" is just to output the day, having a variable to do so seemed excessively simple (I will use a variable in the future if you'd prefer)
    int FIRST_DAY = 0;
    std::cout << "01" << " " << m_transactions[FIRST_DAY].get_balance() << " " << m_transactions[FIRST_DAY].get_description() << std::endl;

    // starts at 1 instead of 0 because the first day is a special case and was handled above ^^
    for(int i=1; i < m_transactions.size(); i++)
    {
        double change = 0.0;
        change = m_transactions[i].get_balance() - m_transactions[i-1].get_balance();

        if(i < 9)
            std::cout << "0"; // keeps dates in XX format if they are single digits

        std::cout << i+1 << " " << m_transactions[i].get_balance() << " " << m_transactions[i].get_description() << fabs(change) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Average balance: " << average_daily_balance() << std::endl;
    std::cout << "Minimum balance: " << min_daily_balance() << std::endl;
    std::cout << "Interest gained: " << get_interest() << std::endl;

    // Because get_interest() only returns the amount changed, this system was needed to get the final value
    // m_transactions.size()-1 is used to get the final day of the vector without using a magic number
    std::cout << "New balance: " << m_transactions[m_transactions.size()-1].get_balance() + get_interest() << std::endl;
}
