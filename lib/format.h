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

/*
    Format

    Helper class that formats ascii bytes other specified formats.
*/
class Format
{
    public:
    std::string getBase64String(const std::vector<uint8_t>&);
    std::string getHexString(const std::vector<uint8_t>&);
    std::string getAsciiString(const std::vector<uint8_t>&);

    std::vector<uint8_t> decodeHexFromAscii(const std::vector<uint8_t>&);
    std::vector<uint8_t> decodeBase64FromAscii(const std::vector<uint8_t>&);
};