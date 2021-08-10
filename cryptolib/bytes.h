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
#include "xor.h"
#include "frequency.h"

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
    // Bytes constructor from any iterable
    Bytes(const std::string&, const BytesFormat&);
    Bytes(const std::vector<uint8_t>&, const BytesFormat&);
    Bytes();

    // Updates the bytes array to the contents of an iterable
    template <typename T>
    void updateBytes(const T& newBytes, const BytesFormat& format)
    {
        this->bytes.clear();
        for (auto& i : newBytes)
            this->bytes.push_back((uint8_t)i);
        this->decodeFrom(format);
        this->convertFrom(format);
    }

    // Display Bytes in Formats
    std::string displayInFormat(const BytesFormat&);
    std::vector<uint8_t> getBytesAs(const BytesFormat&);

    // Xor
    Bytes fixedXor(Bytes&);
    Bytes singleByteXor(const uint8_t&);

    // Frequency


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
    std::unique_ptr<Xor> xorer;
};