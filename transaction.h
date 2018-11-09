#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>

class Transaction
{
public:
    Transaction();
    Transaction(double balance);
    Transaction(double balance, std::string description);
    void make_transaction(Transaction t, double amount);
    double get_balance();
    std::string get_description();
private:
    double m_balance;
    std::string m_description;
};

#endif
