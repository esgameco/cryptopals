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
#include "../lib/frequency.h"

int main(void)
{
    Convert* convert = new Convert();
    Format* format = new Format();
    Xor* xorCipher = new Xor();
    Frequency* frequency = new Frequency();

    std::string input;
    char inputByte;

    std::cout << "Input hex value: " << std::endl;
    std::cin >> input;

    std::cout << "Input xor byte value: " << std::endl;
    std::cin >> inputByte;

    std::vector<uint8_t> hexBytes = convert->getHexBytes(input);
    uint8_t xorByte = convert->extractHex(inputByte);

    std::vector<uint8_t> xoredBytes = xorCipher->singleByteXor(hexBytes, xorByte);
    
    std::vector<uint8_t> asciiBytes = convert->hexToAscii(xoredBytes);
    std::cout << format->getAsciiString(asciiBytes) << std::endl;

    std::vector<uint8_t> asciiFrequency = frequency->getAsciiFrequency(asciiBytes);

    delete convert;
    delete format;
    delete xorCipher;

    return 0;
}