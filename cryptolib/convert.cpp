#include "convert.h"

/*

    Convert Methods

*/

// Converts current bytes to ascii from hex
// 2 4-bit -> 1 8-bit
std::vector<uint8_t> Convert::convertToAsciiFromHex(const std::vector<uint8_t>& bytes)
{
    std::vector<uint8_t> ascii;
    uint8_t current;

    for (int i = 0; i < bytes.size(); i += 2)
    {
        // Extracts 2 4-bit hex values
        current = bytes[i + 1];
        current += bytes[i] << 4;
        // Extracts 1 ascii value from the 8-bit value
        ascii.push_back(current);
    }

    return ascii;
}

// Converts current bytes to ascii from base64
// 4 6-bit -> 3 8-bit
std::vector<uint8_t> Convert::convertToAsciiFromBase64(const std::vector<uint8_t>& bytes)
{
    std::vector<uint8_t> ascii;
    uint32_t current;

    for (int i = 0; i < bytes.size(); i += 4)
    {
        // Extracts 4 6-bit base64 values
        current = bytes[i + 3];
        current += bytes[i + 2] << 6;
        current += bytes[i + 1] << 12;
        current += bytes[i] << 18;
        // Extracts 3 8-bit ascii values
        ascii.push_back(current >> 16);
        ascii.push_back((current >> 8) % 256);
        ascii.push_back(current % 256);
    }

    return ascii;
}

// Converts current bytes to hex from ascii
// 1 8-bit -> 2 4-bit
std::vector<uint8_t> Convert::convertToHexFromAscii(const std::vector<uint8_t>& bytes)
{
    std::vector<uint8_t> hex;
    uint8_t current;

    for (int i = 0; i < bytes.size(); i++)
    {
        // Extracts 2 4-bit hex values from the 8-bit value
        hex.push_back(bytes[i] >> 4);
        hex.push_back(bytes[i] % 16);
    }

    return hex;
}

// Converts current bytes to base64 from ascii
// 3 8-bit -> 4 6-bit
std::vector<uint8_t> Convert::convertToBase64FromAscii(const std::vector<uint8_t>& bytes)
{
    std::vector<uint8_t> base64;
    uint32_t current;

    for (int i = 0; i < bytes.size(); i += 3)
    {
        // Extracts 3 8-bit ascii values
        current = bytes[i + 2];
        current += bytes[i + 1] << 8;
        current += bytes[i] << 16;
        // Extracts 4 6-bit base64 values
        base64.push_back(current >> 18);
        base64.push_back((current >> 12) % 64);
        base64.push_back((current >> 6) % 64);
        base64.push_back(current % 64);
    }

    return base64;
}