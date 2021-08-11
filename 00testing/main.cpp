#include <iostream>
#include <string.h>
#include <cinttypes>
#include <vector>
#include <algorithm>

#include <bytes.h>

int main(void)
{
    std::string input;

    std::cout << "Input base64 value: " << std::endl;
    std::cin >> input;

    std::cout << input.size() << std::endl;

    Bytes bytes = Bytes(input, BytesFormat::base64);

    std::vector<Bytes> possibleBytes;

    for (int i = 0; i < 128; i++)
    {
        possibleBytes.push_back(bytes.singleByteXor(i));
    }

    // TODO: Optimize by caching results
    std::sort(possibleBytes.begin(), possibleBytes.end(),
        [](Bytes& a, Bytes& b)
        {
            return a.getNormalFrequencyDegree() < b.getNormalFrequencyDegree();
        }
    );

    for (int i = 0; i < 5; i++)
        std::cout << possibleBytes[i].displayInFormat(BytesFormat::ascii) << std::endl;

    std::cout << bytes.displayInFormat(BytesFormat::ascii) << std::endl;

    return 0;
}