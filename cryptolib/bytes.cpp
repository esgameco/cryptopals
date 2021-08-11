#include "bytes.h"

std::unique_ptr<Format> Bytes::formater = std::make_unique<Format>();
std::unique_ptr<Convert> Bytes::converter = std::make_unique<Convert>();
std::unique_ptr<Xor> Bytes::xorer = std::make_unique<Xor>();
std::unique_ptr<Frequency> Bytes::frequency = std::make_unique<Frequency>();

/*

    Constructor Methods

*/

Bytes::Bytes(const std::string& newBytes, const BytesFormat& format)
    : format(BytesFormat::ascii)
{
    this->updateBytes<std::string>(newBytes, format);
}
Bytes::Bytes(const std::vector<uint8_t>& newBytes, const BytesFormat& format)
    : format(BytesFormat::ascii)
{
    this->updateBytes<std::vector<uint8_t>>(newBytes, format);
}
Bytes::Bytes()
    : format(BytesFormat::ascii)
{}

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

    Xor Methods

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

// Xor each bit of Bytes against a repeating key
Bytes Bytes::repeatingKeyXor(Bytes& key)
{
    return Bytes(this->xorer->repeatingKeyXor(this->bytes, key.getBytesAs(this->format)), this->format);
}

/*

    Frequency Methods

*/

// Returns the degree to which the Bytes object has a normal ascii frequency
// The closer to 0, the better
// TODO: Cache result
double Bytes::getNormalFrequencyDegree()
{
    if (this->currentNormalFrequencyDegree == 0)
        this->updateNormalFrequencyDegree();
    return this->currentNormalFrequencyDegree;
}


void Bytes::updateNormalFrequencyDegree()
{
    this->currentNormalFrequencyDegree = this->frequency->compareNormalAsciiFrequency(this->frequency->getAsciiFrequency(this->bytes));
}

// Checks whether the current Bytes contains ascii values above 127
bool Bytes::containsIncorrectAscii()
{
    for (const uint8_t& i : this->bytes)
        if (i > 127)
            return true;
    return false;
}

/*

    Decoding Methods

*/

// Decodes ascii characters in a specified format to their numerical format
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