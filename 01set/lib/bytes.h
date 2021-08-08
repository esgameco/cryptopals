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
*/
class Bytes
{
public:
    // Constructor methods
    template<typename T>
    Bytes(const T&, const BytesFormat&);
    template<typename T>
    void updateBytes(const T&, const BytesFormat&);

    // Format Conversions
    void convertTo(const BytesFormat&);

private:
    // Private Conversion Methods
    void convertToAsciiFromHex();

    BytesFormat format;
    std::vector<uint8_t> bytes;
};