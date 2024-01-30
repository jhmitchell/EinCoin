#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(const std::string &fromAddress, const std::string &toAddress, double amount);

    const std::string &getFromAddress() const;
    const std::string &getToAddress() const;
    double getAmount() const;

private:
    std::string fromAddress;
    std::string toAddress;
    double amount;
};

#endif // TRANSACTION_H
