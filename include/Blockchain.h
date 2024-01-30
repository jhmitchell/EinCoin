#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <vector>

class Blockchain {
public:
    Blockchain();

    void addBlock(Block &block);
    bool isChainValid() const;

    const Block &getLastBlock() const;

private:
    std::vector<Block> chain;
    int difficulty;

    Block createGenesisBlock() const;
};

#endif // BLOCKCHAIN_H
