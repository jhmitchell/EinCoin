#include "Block.h"
#include "Blockchain.h"
#include <cassert>

Blockchain::Blockchain() : difficulty(2)
{
    // Initialize the chain with the genesis block
    chain.emplace_back(createGenesisBlock());
}

void Blockchain::addBlock(Block &block)
{
    block.mineBlock(difficulty);
    chain.push_back(block);
}

bool Blockchain::isChainValid() const
{
    for (size_t i = 1; i < chain.size(); i++)
    {
        const Block &curBlock = chain[i];
        const Block &prevBlock = chain[i - 1];

        // Check if the current block's hash is correct
        if (curBlock.getHash() != curBlock.calculateHash())
        {
            return false;
        }

        // Check if the current block points to the correct previous block
        if (curBlock.getPrevHash() != prevBlock.getHash())
        {
            return false;
        }
    }

    return true;
}

const Block &Blockchain::getLastBlock() const
{
    assert(!chain.empty());
    return chain.back();
}

Block Blockchain::createGenesisBlock() const
{
	return Block(0, "0");
}
