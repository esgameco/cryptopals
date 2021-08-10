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
    std::string input1, input2;

    std::cout << "Input base hex value: " << std::endl;
    std::cin >> input1;

    std::cout << "Input additional hex value: " << std::endl;
    std::cin >> input2;

    Bytes bytes1 = Bytes(input1, BytesFormat::hex);
    Bytes bytes2 = Bytes(input2, BytesFormat::hex);

    Bytes xored = bytes1.fixedXor(bytes2);
    
    std::cout << xored.displayInFormat(BytesFormat::hex) << std::endl;

    return 0;
}