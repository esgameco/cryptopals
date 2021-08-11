/**
 * Name: Challenge 6
 * Purpose: Break Repeating-Key XOR
 * Author: Chance Vodnoy
 * Date: 8/10/21
*/

#include <iostream>
#include <string>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <fstream>

#include <bytes.h>

int main(void)
{
    std::ifstream inp("./6.txt");
    std::string line;

    std::vector<Bytes> byteStrings;

    while (inp >> line)
        byteStrings.push_back(Bytes(line, BytesFormat::base64));

    std::vector<Bytes> possibleBytes;

    for (Bytes& bytes : byteStrings)
        for (int i = 0; i < 128; i++)
        {
            Bytes addBytes = bytes.singleByteXor(i);
            if (!addBytes.containsIncorrectAscii())
                possibleBytes.push_back(addBytes);
        }

    // TODO: Optimize by caching results
    std::sort(possibleBytes.begin(), possibleBytes.end(),
        [&](Bytes& a, Bytes& b)
        {
            return a.getNormalFrequencyDegree() < b.getNormalFrequencyDegree();
        }
    );

    for (int i = 0; i < 5; i++)
        std::cout << possibleBytes[i].displayInFormat(BytesFormat::ascii) << std::endl;

    return 0;
}