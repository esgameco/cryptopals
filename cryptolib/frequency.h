#pragma once

/**
 * Name: Frequency
 * Purpose: Get the frequency of each character
 * Author: Chance Vodnoy
 * Date: 3/2/21
*/

#include <iostream>
#include <string>
#include <cinttypes>
#include <vector>
#include <streambuf>
#include <fstream>

class Frequency
{
public:
    std::vector<double> getAsciiFrequency(const std::vector<uint8_t>&);
    double compareNormalAsciiFrequency(const std::vector<double>&);

protected:
    static std::vector<double> asciiFrequency;

private:
    std::vector<double> loadFrequency(std::string);
};