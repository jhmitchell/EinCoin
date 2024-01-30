#include "Block.h"
#include "Transaction.h"
#include <sstream>
#include <ctime>
#include <iostream>

Block::Block(int idx,
             const std::string &prevHash)
    : index(idx),
      prevHash(prevHash),
      nonce(0),
      timestamp(std::time(nullptr))
{
    // Initial hash calculation
    hash = calculateHash();
}

void Block::addTransaction(const Transaction &tx)
{
    transactions.push_back(tx);
}

std::string Block::calculateHash() const
{
    std::stringstream ss;
    ss << index << prevHash << timestamp << nonce << hashTransactions();
    return ss.str();
}

void Block::mineBlock(int difficulty)
{
    std::string target(difficulty, '0');

    while (hash.substr(0, difficulty) != target)
    {
        nonce++;
        hash = calculateHash();
    }

    std::cout << "Block mined: " << hash << std::endl;
}

int Block::getIndex() const
{
    return index;
}

const std::string &Block::getPrevHash() const
{
    return prevHash;
}

const std::string &Block::getHash() const
{
    return hash;
}

std::string Block::hashTransactions() const
{
    std::stringstream ss;

    for (const Transaction &tx : transactions)
    {
        ss << tx.getFromAddress() << tx.getToAddress() << tx.getAmount();
    }

    return ss.str();
}