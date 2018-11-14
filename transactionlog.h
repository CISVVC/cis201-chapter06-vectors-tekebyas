#ifndef TRANSACTIONLOG_H
#define TRANSACTIONLOG_H

#include <vector>
#include "transaction.h"

class Transactionlog
{
public:

    // default constructor omitted because the only data used also has a default constructor
    // a default constructor would do nothing that isn't already done


    /*
        Add a Transaction to the Transactionlog
        @param t = an object of type Transaction to be added to the member vector of Transactions creating this log
    */
    void add_transaction(const Transaction &t);

    /*
        Finds the minimum daily balance
        @return the smallest value found
    */
    double min_daily_balance();

    /*
        Returns the average of each day's balance from the member vector
        @return the sum of each day's balance divided by the size of the vector
    */
    double average_daily_balance();

    /*
        Determines the interest gained based on the min_daily_value and an interest rate 0f 0.5%
        @return interest gained on the account's minimum balance
    */
    double get_interest();

    /*
        Iterates through the member vector printing the day, what amount was modified, and a description of what happened
    */
    void print();
private:
    std::vector<Transaction> m_transactions;
};

#endif
