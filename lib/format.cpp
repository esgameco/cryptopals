#include "format.h"

/*
 
    Format Methods
 
*/

// Gets base64 string from bytes
std::string Format::getBase64String(const std::vector<uint8_t>& base64Bytes)
{
    std::string str;

    for (const uint8_t& i : base64Bytes)
    {
        if (i < 26)
        {
            str.push_back((char)(i + 'A'));
        }
        else if (i < 52)
        {
            str.push_back((char)(i + 'a' - 26));
        }
        else if (i < 62)
        {
            str.push_back((char)(i + '0' - 52));
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

    for (const uint8_t& i : hexBytes)
    {
        if (i < 10)
        {
            str.push_back((char)(i + '0'));
        }
        else
        {
            str.push_back((char)(i + 'a' - 10));
        }
    }

    return str;
}

// Gets ascii string from bytes
std::string Format::getAsciiString(const std::vector<uint8_t>& asciiBytes)
{
    std::string str;

    for (const uint8_t& i : asciiBytes)
    {
        str.push_back((char)i);
    }

    return str;
}

// Decodes bytes from hex ascii format to numerical hex
std::vector<uint8_t> Format::decodeHexFromAscii(const std::vector<uint8_t>& bytes)
{
    std::vector<uint8_t> hex;

    for (const uint8_t& i : bytes)
    {
        if (i < 'a')
        {
            hex.push_back((uint8_t)(i - '0'));
        }
        else
        {
            hex.push_back((uint8_t)(i - 'a' + 10));
        }
    }

    return hex;
}

// Decodes bytes from base64 ascii format to numerical base64
std::vector<uint8_t> Format::decodeBase64FromAscii(const std::vector<uint8_t>& bytes)
{
    std::vector<uint8_t> base64;

    for (const uint8_t& i : bytes)
    {
        if (i >= 'A' && i <= 'Z')
        {
            base64.push_back((uint8_t)(i - 'A'));
        }
        else if (i >= 'a' && i <= 'z')
        {
            base64.push_back((uint8_t)(i - 'a' + 26));
        }
        else if (i >= '0' && i <= '9')
        {
            base64.push_back((uint8_t)(i - '0' + 52));
        }
        else if (i == '+')
        {
            base64.push_back(62);
        }
        else if (i == '/')
        {
            base64.push_back(63);
        }
    }

    return base64;
}