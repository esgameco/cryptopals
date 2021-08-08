/**
 * Name: Challenge 2
 * Purpose: Fixed Xor 2 Strings
 * Author: Chance Vodnoy
 * Date: 3/2/21
*/

#include <iostream>
#include <string.h>
#include <cinttypes>
#include <vector>

#include "../lib/format.h"
#include "../lib/xor.h"

int main(void)
{
    std::string input1, input2;

    std::cout << "Input base hex value: " << std::endl;
    std::cin >> input1;

    std::cout << "Input additional hex value: " << std::endl;
    std::cin >> input2;

    Convert* convert = new Convert();
    Format* format = new Format();
    Xor* xorCipher = new Xor();
    std::vector<uint8_t> baseHexBytes = convert->getHexBytes(input1);
    std::vector<uint8_t> addHexBytes = convert->getHexBytes(input2);
    
    std::cout << format->getHexString(xorCipher->fixedXor(baseHexBytes, addHexBytes)) << std::endl;

    delete convert;
    delete format;

    return 0;
}