#include "Transaction.h"

Transaction::Transaction(const std::string &fromAddress,
                         const std::string &toAddress,
                         double amount)
    : fromAddress(fromAddress),
      toAddress(toAddress),
      amount(amount)
{
}

const std::string &Transaction::getFromAddress() const
{
    return fromAddress;
}

const std::string &Transaction::getToAddress() const
{
    return toAddress;
}

double Transaction::getAmount() const
{
    return amount;
}
