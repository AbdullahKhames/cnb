#ifndef HASH_H
#define HASH_H

#include "base.h"

class Hash
{
public:
    // Compute 32-bit FNV-1 hash
    uint32_t Hash32(std::string str);

    // Compute 64-bit FNV-1 hash
    uint64_t Hash64(std::string str);
};

void playWithHashing();
#endif
