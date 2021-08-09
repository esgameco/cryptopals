#pragma once

/**
 * Name: Bytes
 * Purpose: A vector of bytes that can have operations performed on them.
 * Author: Chance Vodnoy
 * Date: 8/7/21
*/

#include <iostream>
#include <vector>

#include "format.h"
#include "convert.h"

enum class BytesFormat
{
    ascii,
    hex,
    base64
};

/*
    Bytes

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

    // Display Bytes in Formats
    std::string displayInFormat(const BytesFormat&);

private:
    // Private Methods
    // Decode Bytes to Formats
    void decodeFrom(const BytesFormat&);

    // Format Conversions
    void convertFrom(const BytesFormat&);

    // Member Variables
    BytesFormat format;
    std::vector<uint8_t> bytes;

    std::unique_ptr<Format> formater;
    std::unique_ptr<Convert> converter;
};