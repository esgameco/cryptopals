#include "xor.h"

/*

    XOR Methods

*/

std::vector<uint8_t> Xor::fixedXor(const std::vector<uint8_t>& base, const std::vector<uint8_t>& add)
{
    std::vector<uint8_t> xored;
    if (base.size() != add.size())
    {
        std::cout << "You must provide equal length vectors." << std::endl;
    }

    for (int i = 0; i < base.size(); i++)
    {
        xored.push_back(base[i]^add[i]);
    }

    return xored;
}

std::vector<uint8_t> Xor::singleByteXor(const std::vector<uint8_t>& bytes, uint8_t xorByte)
{
    std::vector<uint8_t> xored;

    for (int i = 0; i < bytes.size(); i++)
    {
        xored.push_back(bytes[i]^xorByte);
    }

    return xored;
}

std::vector<uint8_t> Xor::repeatingKeyXor(const std::vector<uint8_t>& bytes, const std::vector<uint8_t>& key)
{
    std::vector<uint8_t> xored;

    for (int i = 0; i < bytes.size(); i++)
    {
        xored.push_back(bytes[i] ^ key[i % key.size()]);
    }

    return xored;
}