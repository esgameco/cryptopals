#include "bytes.h"

/*

    Contructor Methods

*/

// Bytes constructor from any iterable
template<typename T>
Bytes::Bytes(const T& newBytes, const BytesFormat& format) 
    : format(BytesFormat::ascii)
{
    this->formater = std::make_unique<Format>();
    this->converter = std::make_unique<Format>();
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

    Display Methods

*/

// Displays bytes using specified format
std::string Bytes::displayInFormat(const BytesFormat& format)
{
    switch (format)
    {
    case BytesFormat::hex:
        return this->formater->getHexString(this->bytes);

    case BytesFormat::base64:
        return this->formater->getBase64String(this->bytes);

    case BytesFormat::ascii:
        return this->formater->getAsciiString(this->bytes);

    default:
        break;
    }
}

/*

    Decoding Methods

*/

void Bytes::decodeFrom(const BytesFormat& format)
{
    switch (format)
    {
    case BytesFormat::hex:
        this->bytes = this->formater->decodeHexFromAscii(this->bytes);
        break;
    
    case BytesFormat::base64:
        this->bytes = this->formater->decodeBase64FromAscii(this->bytes);
        break;
    
    default:
        break;
    }
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
        this->bytes = this->converter->convertToAsciiFromHex(this->bytes);
        break;
    
    case BytesFormat::base64:
        this->bytes = this->converter->convertToAsciiFromBase64(this->bytes);
        break;
    
    default:
        break;
    }
}