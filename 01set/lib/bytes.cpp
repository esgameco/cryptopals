#include "bytes.h"

/*
    Contructor Methods
*/

// Bytes constructor from any iterable
template<typename T>
Bytes::Bytes(const T& newBytes, const BytesFormat& format = BytesFormat::ascii) : format(format)
{
    this->updateBytes<T>(newBytes, format);
}

// Updates the bytes array to the contents of an iterable
template<typename T>
void Bytes::updateBytes(const T& newBytes, const BytesFormat& format)
{
    this->bytes.clear();
    for (auto& i : newBytes)
        this->bytes.push_back((uint8_t)i);
    this->decodeFrom(format);
    this->convertFrom(format);
}

/*
    Encoded Display
*/

// TODO: Change push_back to something more efficient.
//       Pretty sure that strings are immutable so
//       each call to push_back creates a new string.

// Encodes bytes to ascii chars
std::string Bytes::getAsciiString()
{
    std::string str;

    for (const uint8_t& i : this->bytes)
    {
        str.push_back((char)i);
    }

    return str;
}

// Encodes bytes to hex
std::string Bytes::getHexString()
{
    std::string str;

    for (const uint8_t& i : this->bytes)
    {
        if (i < 10)
        {
            str.push_back((char)(i+'0'));
        }
        else
        {
            str.push_back((char)(i+'a'-10));
        }
    }

    return str;
}

// Encodes bytes to base64
std::string Bytes::getBase64String()
{
    std::string str;

    for (const uint8_t& i : this->bytes)
    {
        if (i < 26)
        {
            str.push_back((char)(i+'A'));
        }
        else if (i < 52)
        {
            str.push_back((char)(i+'a'-26));
        }
        else if (i < 62)
        {
            str.push_back((char)(i+'0'-52));
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

/*
    Decoding Methods
*/

void Bytes::decodeFrom(const BytesFormat& format)
{
    switch (format)
    {
    case BytesFormat::hex:
        this->decodeHexFromAscii();
        break;
    
    case BytesFormat::base64:
        this->decodeBase64FromAscii();
        break;
    
    default:
        break;
    }
}

// Decodes bytes from hex ascii format to numerical hex
void Bytes::decodeHexFromAscii()
{
    std::vector<uint8_t> hex;

    for (const uint8_t& i : this->bytes)
    {
        if (i < 'a')
        {
            hex.push_back((uint8_t)(i-'0'));
        }
        else
        {
            hex.push_back((uint8_t)(i-'a'+10));
        }
    }

    this->bytes = hex;
}

// Decodes bytes from base64 ascii format to numerical base64
void Bytes::decodeBase64FromAscii()
{
    std::vector<uint8_t> base64;

    for (const uint8_t& i : this->bytes)
    {
        if (i >= 'A' && i <= 'Z')
        {
            base64.push_back((uint8_t)(i-'A'));
        }
        else if (i >= 'a' && i <= 'z')
        {
            base64.push_back((uint8_t)(i-'a'+26));
        }
        else if (i >= '0' && i <= '9')
        {
            base64.push_back((uint8_t)(i-'0'+52));
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

    this->bytes = base64;
}

/*
    Conversion Methods
*/

// Converts current bytes to ascii
void Bytes::convertFrom(const BytesFormat& format)
{
    switch (format)
    {
    case BytesFormat::hex:
        this->convertToAsciiFromHex();
        break;
    
    case BytesFormat::base64:
        this->convertToAsciiFromBase64();
        break;
    
    default:
        break;
    }
}

// Converts current bytes to ascii from hex
// 2 4-bit -> 1 8-bit
void Bytes::convertToAsciiFromHex()
{
    std::vector<uint8_t> ascii;
    uint8_t current;

    for (int i = 0; i < bytes.size(); i+= 2)
    {
        // Extracts 2 4-bit hex values
        current = bytes[i+1];
        current += bytes[i] << 4;
        // Extracts 1 ascii value from the 8-bit value
        ascii.push_back(current);
    }

    this->bytes = ascii;
}

// Converts current bytes to ascii from base64
// 4 6-bit -> 3 8-bit
void Bytes::convertToAsciiFromBase64()
{
    std::vector<uint8_t> ascii;
    uint32_t current;

    for (int i = 0; i < bytes.size(); i+= 4)
    {
        // Extracts 4 6-bit base64 values
        current = bytes[i+3];
        current += bytes[i+2] << 6;
        current += bytes[i+1] << 12;
        current += bytes[i] << 18;
        // Extracts 3 8-bit ascii values
        ascii.push_back(current % 256);
        ascii.push_back((current >> 8) % 256);
        ascii.push_back((current >> 16) % 256);
    }

    this->bytes = ascii;
}

