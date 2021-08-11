#include "frequency.h"

//----------------------------------------------------------------//
//--------------------------(Frequency)---------------------------//
//----------------------------------------------------------------//

std::vector<double> Frequency::asciiFrequency;

// Gets the frequency of each character in an ascii vector
std::vector<double> Frequency::getAsciiFrequency(const std::vector<uint8_t>& asciiBytes)
{
    std::vector<double> frequency(128, 0);

    for (uint8_t i : asciiBytes)
    {
        // TODO: Move size outside
        frequency[i] += (1.0/asciiBytes.size());
    }

    return frequency;
}

// Compares the character frequency passed in with normal character frequency
double Frequency::compareNormalAsciiFrequency(const std::vector<double>& asciiFrequencyPercentage)
{
    std::vector<double> normalAsciiFrequencyPercentage;
    double frequencyDifference = 0;

    // Gets the normal percentage
    // TODO: Make it not a constant path somehow
    normalAsciiFrequencyPercentage = loadFrequency("C:\\Users\\chanc\\Documents\\Projects\\cryptopals\\CryptoPals\\cryptolib\\data\\freq.data");

    // Compares the frequency between normal and given
    for (int i = 0; i < asciiFrequencyPercentage.size(); i++)
    {
        //std::cout << i << ": " << normalAsciiFrequencyPercentage[i] << ", " << asciiFrequencyPercentage[i] << std::endl;
        frequencyDifference += abs(normalAsciiFrequencyPercentage[i]-asciiFrequencyPercentage[i]);
    }

    return frequencyDifference;
}

// Loads a json frequency file as doubles
// Cached into static member variable for performance reasons
std::vector<double> Frequency::loadFrequency(std::string filePath)
{
    if (!Frequency::asciiFrequency.empty())
        return Frequency::asciiFrequency;

    std::ifstream inp(filePath);
    std::string line;
    std::vector<double> frequency;

    while (inp >> line)
        frequency.push_back(std::atof(line.c_str()));
    
    Frequency::asciiFrequency = frequency;

    return frequency;
}