#include "transactionlog.h"
#include <iostream>

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

void Transactionlog::print()
{
    for(int i=0; i < m_transactions.size(); i++)
    {
        double change = 0.0;
        if(i != 0)
            change = m_transactions[i].get_balance() - m_transactions[i-1].get_balance();
        else
            change = m_transactions[i].get_balance();

        if(i < 9)
            std::cout << "0";

        std::cout << i+1 << " " << change << " " << m_transactions[i].get_description() << std::endl;
    }
}
