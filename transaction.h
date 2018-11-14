#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>

class Transaction
{
public:
    /*
        Each of these constructors allows for the creation of a Transaction with
        varying amounts of data given at creation
    */
    Transaction();
    Transaction(double balance);
    Transaction(double balance, std::string description);
    /*
        Allows the creation of a new Transaction
        @param t = the prior transaction (needed for determining the new balance)
        @param amount = the amount you are transferring
    */
    void make_transaction(Transaction t, double amount);
    /*
        Returns the Transaction's balance
    */
    double get_balance();
    /*
        Returns the description associated with the Transaction
    */
    std::string get_description();
private:
    double m_balance;
    std::string m_description;
};

#endif
