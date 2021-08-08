#pragma once

/**
 * Name: Format
 * Purpose: Formatting strings and bytes to various formats
 * Author: Chance Vodnoy
 * Date: 3/2/21
*/

#include <iostream>
#include <string.h>
#include <cinttypes>
#include <vector>

class Format
{
    public:
    std::string getBase64String(const std::vector<uint8_t>&);
    std::string getHexString(const std::vector<uint8_t>&);
    std::string getAsciiString(const std::vector<uint8_t>&);
};

class Convert
{
    public:
    std::vector<uint8_t> hexToBase64(const std::vector<uint8_t>&);
    std::vector<uint8_t> hexToAscii(const std::vector<uint8_t>&);
    std::vector<uint8_t> getHexBytes(const std::string&);
    uint8_t extractHex(uint8_t);
};