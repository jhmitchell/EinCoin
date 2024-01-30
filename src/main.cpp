#include "Blockchain.h"
#include "Transaction.h"
#include <iostream>

int main()
{
    Blockchain blockchain;

    std::cout << "Mining block 1..." << std::endl;
    Block block1(1, blockchain.getLastBlock().getHash());
    block1.addTransaction(Transaction("John", "Brad", 100));
    block1.addTransaction(Transaction("Brad", "Tyler", 50));
    blockchain.addBlock(block1);

    std::cout << "Mining block 2..." << std::endl;
    Block block2(2, blockchain.getLastBlock().getHash());
    block2.addTransaction(Transaction("John", "Tyler", 25));
    blockchain.addBlock(block2);

    std::cout << "Is chain valid? " << (blockchain.isChainValid() ? "Yes" : "No") << std::endl;
    return 0;
}
