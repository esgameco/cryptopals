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

#include "../lib/format.h"

int main(void)
{
    std::string input;

    std::cout << "Input hex value: " << std::endl;
    std::cin >> input;

    Convert* convert = new Convert();
    Format* format = new Format();
    std::vector<uint8_t> hexBytes = convert->getHexBytes(input);
    
    std::cout << format->getBase64String(convert->hexToBase64(hexBytes)) << std::endl;

    delete convert;
    delete format;

    return 0;
}