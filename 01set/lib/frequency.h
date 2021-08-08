#pragma once

/**
 * Name: Frequency
 * Purpose: Get the frequency of each character
 * Author: Chance Vodnoy
 * Date: 3/2/21
*/

#include <iostream>
#include <string.h>
#include <cinttypes>
#include <vector>
#include <streambuf>

class Frequency
{
    public:
    std::vector<uint8_t> getAsciiFrequency(const std::vector<uint8_t>&);
    double compareNormalAsciiFrequency(const std::vector<uint8_t>&, uint16_t);

    private:
    std::vector<double> loadFrequency(std::string);
};