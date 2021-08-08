#include "bytes.h"

/*
    Contructor Methods
*/

// Bytes constructor from any iterable
template<typename T>
Bytes::Bytes(const T& newBytes, const BytesFormat& format)
{
    updateBytes<T>(newBytes, format);
}

// Updates the bytes array to the contents of an iterable
template<typename T>
void Bytes::updateBytes(const T& newBytes, const BytesFormat& format)
{
    this->format = format;
    this->bytes.clear();
    for (auto& i : newBytes)
        this->bytes.push_back((uint8_t)i);
}

/*
    Conversion Methods
*/

// Converts current bytes to a specified format
void Bytes::convertTo(const BytesFormat& format)
{
    switch (format)
    {
    case BytesFormat::ascii:
        break;
    
    default:
        break;
    }
}