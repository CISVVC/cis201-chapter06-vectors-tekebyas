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

void fill_vector(std::vector<Transaction> &v, Transactionlog &tlog)
{
    const int MAX_SIZE = 30;
    srand(time(0));

    Transaction t(1143.24,"Initial balance");
    v.push_back(t);
    tlog.add_transaction(t);

    for(int i = 1; i < MAX_SIZE; i++)
    {
        Transaction u;

        double amount = generate_number();
        u.make_transaction(v[i-1],amount);

        v.push_back(u);
        tlog.add_transaction(v[i]);
    }
}

double generate_number()
{
    const int MAX_CHANGE = 80000;
    const int SHIFT = 35000;
    const double CONVERSION_RATE = 100.0;

    int amount_pennies = rand() % MAX_CHANGE - SHIFT;
    double amount = amount_pennies / CONVERSION_RATE;

    return amount;
}
