#pragma once

/**
 * Name: Bytes
 * Purpose: A vector of bytes that can have operations performed on them.
 * Author: Chance Vodnoy
 * Date: 8/7/21
*/

#include <iostream>
#include <vector>

enum class BytesFormat
{
    ascii,
    hex,
    base64
};

/*
    Bytes Class:

    Stores bytes as a vector of 8-bit unsigned integers in the form of ascii characters.
    Can get representation as hex or base64.
*/
class Bytes
{
public:
    // Constructor Methods
    template<typename T>
    Bytes(const T&, const BytesFormat&);
    template<typename T>
    void updateBytes(const T&, const BytesFormat&);

    // Display in Encoded Formats
    std::string getAsciiString();
    std::string getHexString();
    std::string getBase64String();

    // Decode Ascii to Formats
    void decodeFrom(const BytesFormat&);

    // Format Conversions
    void convertFrom(const BytesFormat&);

private:
    // Private Conversion Methods
    void convertToAsciiFromHex();
    void convertToAsciiFromBase64();

    // Private Decoding Methods
    void decodeHexFromAscii();
    void decodeBase64FromAscii();

    // Member Variables
    BytesFormat format;
    std::vector<uint8_t> bytes;
};