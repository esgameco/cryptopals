#pragma once

/**
 * Name: Xor
 * Purpose: Xor Ciphers
 * Author: Chance Vodnoy
 * Date: 3/2/21
*/

#include <iostream>
#include <string.h>
#include <cinttypes>
#include <vector>

class Xor
{
public:
    std::vector<uint8_t> fixedXor(const std::vector<uint8_t>&, const std::vector<uint8_t>&);
    std::vector<uint8_t> singleByteXor(const std::vector<uint8_t>&, uint8_t);
    std::vector<uint8_t> repeatingKeyXor(const std::vector<uint8_t>&, const std::vector<uint8_t>&);
};