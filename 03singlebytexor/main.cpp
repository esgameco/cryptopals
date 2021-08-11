/**
 * Name: Challenge 3
 * Purpose: Single-Byte XOR Cipher
 * Author: Chance Vodnoy
 * Date: 8/8/21
*/

#include <iostream>
#include <string.h>
#include <cinttypes>
#include <vector>
#include <algorithm>

#include <bytes.h>

int main(void)
{
    std::string input;
    char inputByte;

    std::cout << "Input hex value: " << std::endl;
    std::cin >> input;

    //std::cout << "Input xor byte value: " << std::endl;
    //std::cin >> inputByte;

    Bytes bytes = Bytes(input, BytesFormat::hex);

    std::vector<Bytes> possibleBytes;

    for (int i = 0; i < 128; i++)
    {
        possibleBytes.push_back(bytes.singleByteXor(i));
    }

    // TODO: Optimize by caching results
    std::sort(possibleBytes.begin(), possibleBytes.end(), 
        [](Bytes& a, Bytes& b)
        {
            return a.getNormalFrequencyDegree() < b.getNormalFrequencyDegree();
        }
    );

    for (int i = 0; i < 5; i++)
        std::cout << possibleBytes[i].displayInFormat(BytesFormat::ascii) << std::endl;

    return 0;
}

// RESULT: Cooking MC's like a pound of bacon