/**
 * Name: Challenge 5
 * Purpose: Implement Repeating-Key XOR
 * Author: Chance Vodnoy
 * Date: 8/10/21
*/

#include <iostream>
#include <string>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <fstream>

#include <bytes.h>

int main(void)
{
    std::string input;
    char inputByte;

    std::cout << "Input ascii value: " << std::endl;
    std::getline(std::cin, input);
    Bytes bytes(input, BytesFormat::ascii);

    std::cout << "Input key value: " << std::endl;
    std::getline(std::cin, input);
    Bytes key(input, BytesFormat::ascii);

    Bytes xored = bytes.repeatingKeyXor(key);
    std::cout << xored.displayInFormat(BytesFormat::hex) << std::endl;

    return 0;
}