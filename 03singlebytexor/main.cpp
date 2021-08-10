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

    for (int i = 0; i < 128; i++)
    {
        Bytes xored = bytes.singleByteXor(i);

        std::cout << xored.displayInFormat(BytesFormat::ascii) << std::endl;
    }

    return 0;
}