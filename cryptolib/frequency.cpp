#include "frequency.h"

//----------------------------------------------------------------//
//--------------------------(Frequency)---------------------------//
//----------------------------------------------------------------//

// Gets the frequency of each character in an ascii vector
std::vector<uint8_t> getAsciiFrequency(const std::vector<uint8_t>& asciiBytes)
{
    std::vector<uint8_t> frequency;
    frequency.reserve(128);

    for (uint8_t i : asciiBytes)
    {
        frequency[i]++;
    }

    return frequency;
}

// Compares the character frequency passed in with normal character frequency
double compareNormalAsciiFrequency(const std::vector<uint8_t>& asciiFrequency, uint16_t bytesSize)
{
    std::vector<double> asciiFrequencyPercentage;
    std::vector<double> normalAsciiFrequencyPercentage;
    double frequencyDifference = 0;

    // Gets the percentage so it can be compared
    for (int i = 0; i < asciiFrequency.size(); i++)
    {
        asciiFrequencyPercentage.push_back((double)asciiFrequency[i]/bytesSize);
    }

    // Gets the normal percentage
    // TODO: Make it not a constant path somehow
    //normalAsciiFrequencyPercentage = loadFrequency("../data/lfn.json");

    // Compares the frequency between normal and given
    //for (int i = 0; i < asciiFrequencyPercentage.size(); i++)
    //{
    //    frequencyDifference += abs(normalAsciiFrequencyPercentage[i]-asciiFrequencyPercentage[i]);
    //}

    return frequencyDifference;
}

// Loads a json frequency file as doubles
std::vector<double> loadFrequency(std::string filePath)
{
    // std::ifstream i(filePath);
    return std::vector<double>();
}