/*
    Name: Teke Byas
    File: transaction.cpp
    Date of Creation: Thursday, November 8, 2018
    Description: This file implements a class 'Transaction' that allows the creation
        of a single transaction to be used in a log
*/
#include "transaction.h"

Transaction::Transaction()
{
    m_balance = 0;
    m_description = "Initial balance";
}

Transaction::Transaction(double balance)
{
    m_balance = balance;
}

Transaction::Transaction(double balance, std::string description)
{
    m_balance = balance;
    m_description = description;
}

void Transaction::make_transaction(Transaction t, double amount)
{
    m_balance = t.get_balance() + amount;
    if(amount > 0)
        m_description = "Deposit of ";
    if(amount < 0)
        m_description = "Withdrawal of ";
}

double Transaction::get_balance()
{
    return m_balance;
}

std::string Transaction::get_description()
{
    return m_description;
}
