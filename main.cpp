#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "transactionlog.h"

void fill_vector(std::vector<Transaction> &v, Transactionlog &tlog);
double generate_number();

int main()
{
    std::vector<Transaction> vlog;
    Transactionlog tlog;

    fill_vector(vlog,tlog);

    tlog.print();

    return 0;
}

/*
    Fills a placeholder vector and the member vector of the Transactionlog class
    @param v = a vector used to create and store a number of Transactions
    @param tlog = an object of type Transactionlog that will hold a vector of Transactions and functions to modify them
*/
void fill_vector(std::vector<Transaction> &v, Transactionlog &tlog)
{
    const int MAX_SIZE = 30;
    // seed for random function must be done outside of loop else an error occurs where all numbers are the same
    srand(time(0));

    // First number hard coded in because an amount and initial balance were given in the prompt
    Transaction t(1143.24,"Initial balance");


    // parallel vectors

    v.push_back(t); // this vector provides an easy way to add items to the other vector

    tlog.add_transaction(t); // this vector is used from here on because it holds all information and functions needed for the program


    // fills the vectors with random numbers
    for(int i = 1; i < MAX_SIZE; i++)
    {
        Transaction u;

        double amount = generate_number(); // abstracted into a second function for error checking
        u.make_transaction(v[i-1],amount);

        // adding the Transaction to this vector first makes it easier to compare transactions (needed when making a new Transaction)
        v.push_back(u);

        tlog.add_transaction(v[i]);
    }
}

/*
    Creates a random number to modify each transaction by
    @return the amount to modify by
*/
double generate_number()
{
    const int MAX_CHANGE = 80000; // used to cap the maximum amount the account will let transfer at once
    const int SHIFT = 35000; // shifts MAX_CHANGE so that withdrawals can be made as well
    const double CONVERSION_RATE = 100.0; // converts the random number from int to double to be represented as a dollar amount

    int amount_pennies = rand() % MAX_CHANGE - SHIFT;
    double amount = amount_pennies / CONVERSION_RATE;

    return amount;
}
