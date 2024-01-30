#ifndef BLOCK_H
#define BLOCK_H

#include "Transaction.h"
#include <string>
#include <vector>

class Block {
public:
    Block(int idx, const std::string &prevHash);

    void addTransaction(const Transaction &tx);
    std::string calculateHash() const;
    void mineBlock(int difficulty);

    int getIndex() const;
    const std::string &getPrevHash() const;
    const std::string &getHash() const;

private:
    int index;
    std::string prevHash;
    std::string hash;
    std::vector<Transaction> transactions;
    long long nonce;
    long long timestamp;

    std::string hashTransactions() const;
};

#endif // BLOCK_H
