#pragma once

#include <iostream>
#include <string.h>
#include <cinttypes>
#include <vector>

/*
    Convert

    Helper class that converts bytes from one format to another.
*/
class Convert
{
public:
    std::vector<uint8_t> convertToAsciiFromHex(const std::vector<uint8_t>&);
    std::vector<uint8_t> convertToAsciiFromBase64(const std::vector<uint8_t>&);
    std::vector<uint8_t> convertToHexFromAscii(const std::vector<uint8_t>&);
    std::vector<uint8_t> convertToBase64FromAscii(const std::vector<uint8_t>&);
};
