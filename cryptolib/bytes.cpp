#include "bytes.h"

/*

    Constructor Methods

*/

Bytes::Bytes(const std::string& newBytes, const BytesFormat& format)
    : format(BytesFormat::ascii),
      formater(std::make_unique<Format>()),
      converter(std::make_unique<Convert>()),
      xorer(std::make_unique<Xor>())
{
    this->updateBytes<std::string>(newBytes, format);
}
Bytes::Bytes(const std::vector<uint8_t>& newBytes, const BytesFormat& format)
    : format(BytesFormat::ascii),
      formater(std::make_unique<Format>()),
      converter(std::make_unique<Convert>()),
      xorer(std::make_unique<Xor>())
{
    this->updateBytes<std::vector<uint8_t>>(newBytes, format);
}
Bytes::Bytes()
    : format(BytesFormat::ascii),
      formater(std::make_unique<Format>()),
      converter(std::make_unique<Convert>()),
      xorer(std::make_unique<Xor>()) {}

/*

    Display Methods

*/

// Displays bytes using specified format
std::string Bytes::displayInFormat(const BytesFormat& format)
{
    std::vector<uint8_t> displayBytes = this->getBytesAs(format);

    switch (format)
    {
    case BytesFormat::hex:
        return this->formater->getHexString(displayBytes);

    case BytesFormat::base64:
        return this->formater->getBase64String(displayBytes);

    case BytesFormat::ascii:
        return this->formater->getAsciiString(displayBytes);

    default:
        return "";
    }
}

/*

    Xor

*/

// Xor each bit of Bytes against the bit of another Bytes
Bytes Bytes::fixedXor(Bytes& bytesAgainst)
{
    return Bytes(this->xorer->fixedXor(this->bytes, bytesAgainst.getBytesAs(this->format)), this->format);
}

// Xor each bit of Bytes against the bit of another Bytes
Bytes Bytes::singleByteXor(const uint8_t& byteAgainst)
{
    return Bytes(this->xorer->singleByteXor(this->bytes, byteAgainst), this->format);
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

// Gets a formated version of the current bytes
std::vector<uint8_t> Bytes::getBytesAs(const BytesFormat& format)
{
    switch (format)
    {
    case BytesFormat::hex:
        return this->converter->convertToHexFromAscii(this->bytes);

    case BytesFormat::base64:
        return this->converter->convertToBase64FromAscii(this->bytes);

    default:
        return this->bytes;
    }
}