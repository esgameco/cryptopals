#include "format.h"

//----------------------------------------------------------------//
//--------------------------(Format)------------------------------//
//----------------------------------------------------------------//

// Gets base64 string from bytes
std::string Format::getBase64String(const std::vector<uint8_t>& base64Bytes)
{
    std::string str;

    for (uint8_t i : base64Bytes)
    {
        if (i < 26)
        {
            str.push_back((char)(i+65));
        }
        else if (i < 52)
        {
            str.push_back((char)(i+97-26));
        }
        else if (i < 62)
        {
            str.push_back((char)(i+48-52));
        }
        else if (i == 62)
        {
            str.push_back('+');
        }
        else if (i == 63)
        {
            str.push_back('/');
        }
    }

    return str;
}

// Gets hex string from bytes
std::string Format::getHexString(const std::vector<uint8_t>& hexBytes)
{
    std::string str;

    for (uint8_t i : hexBytes)
    {
        if (i < 10)
        {
            str.push_back((char)(i+48));
        }
        else
        {
            str.push_back((char)(i+97-10));
        }
    }

    return str;
}

// Gets ascii string from bytes
std::string Format::getAsciiString(const std::vector<uint8_t>& asciiBytes)
{
    std::string str;

    for (uint8_t i : asciiBytes)
    {
        str.push_back((char)i);
    }

    return str;
}

//----------------------------------------------------------------//
//-------------------------(Convert)------------------------------//
//----------------------------------------------------------------//

// Converts hex byte array to base64 byte array
std::vector<uint8_t> Convert::hexToBase64(const std::vector<uint8_t>& bytes)
{
    std::vector<uint8_t> base64;
    int current;

    for (int i = 0; i < bytes.size(); i+= 3)
    {
        // Extracts 3 hex values into a 12-bit value
        current = bytes[i+2];
        current += bytes[i+1]*16;
        current += bytes[i]*256;
        // Extracts 2 base64 values from the 12-bit value
        base64.push_back(current >> 6);
        base64.push_back(current % 64);
    }

    return base64;
}

// Converts hex byte array to ascii byte array
std::vector<uint8_t> Convert::hexToAscii(const std::vector<uint8_t>& bytes)
{
    std::vector<uint8_t> ascii;
    uint8_t current;

    for (int i = 0; i < bytes.size(); i+= 2)
    {
        // Extracts 2 hex values into a 8-bit value
        current = bytes[i+1];
        current += bytes[i]*16;
        // Extracts 1 ascii value from the 8-bit value
        ascii.push_back(current);
    }

    return ascii;
}

// Gets hex bytes from string
std::vector<uint8_t> Convert::getHexBytes(const std::string& str)
{
    std::vector<uint8_t> hexBytes;

    for (char c : str)
    {
        hexBytes.push_back(extractHex((uint8_t)c));
    }

    return hexBytes;
}

// Extracts hex value from ascii code
uint8_t Convert::extractHex(uint8_t ascii)
{
    // 97 -> a, 48 -> 0, 57 -> 9
    return (ascii > 57) ? (ascii-97)+10 : ascii-48;
}