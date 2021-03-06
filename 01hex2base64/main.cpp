/**
 * Name: Challenge 1
 * Purpose: Convert Hex to Base64
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

    std::cout << "Input hex value: " << std::endl;
    std::cin >> input;

    Bytes bytes = Bytes(input, BytesFormat::hex);
    
    std::cout << bytes.displayInFormat(BytesFormat::base64) << std::endl;

    return 0;
}