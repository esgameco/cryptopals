#include "xor.h"

//----------------------------------------------------------------//
//-----------------------------(Xor)------------------------------//
//----------------------------------------------------------------//

std::vector<uint8_t> Xor::fixedXor(std::vector<uint8_t> base, std::vector<uint8_t> add)
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

std::vector<uint8_t> Xor::singleByteXor(std::vector<uint8_t> bytes, uint8_t xorByte)
{
    std::vector<uint8_t> xored;

    for (int i = 0; i < bytes.size(); i++)
    {
        xored.push_back(bytes[i]^xorByte);
    }

    return xored;
}