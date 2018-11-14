#include "transactionlog.h"
#include <iostream>
#include <math.h> // fabs() needed for withdrawal to display properly

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

    for(int i=1; i < m_transactions.size(); i++)
    {
        double change = 0.0;
        change = m_transactions[i].get_balance() - m_transactions[i-1].get_balance();

        if(i < 9)
            std::cout << "0"; // keeps dates in XX format if they are single digits

        std::cout << i+1 << " " << m_transactions[i].get_balance() << " " << m_transactions[i].get_description() << fabs(change) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "The average balance of your account over the last 30 days was: " << average_daily_balance() << std::endl;
    std::cout << "The minimum balance of your account over the last 30 days was: " << min_daily_balance() << std::endl;
    std::cout << "The interest gained on your account is: " << get_interest() << std::endl;
    std::cout << "New balance: " << m_transactions[m_transactions.size()-1].get_balance() + get_interest() << std::endl;
}
