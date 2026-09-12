#include "settings/softwaredecoderthreads.h"

#include <climits>
#include <iostream>

int main()
{
    struct Case { int requested; int available; int expected; };
    const Case cases[] = {
        {0, 12, 8}, {0, 16, 8}, {0, 6, 6},
        {4, 12, 4}, {8, 12, 8}, {12, 12, 12}, {16, 12, 12},
        {4, 16, 4}, {8, 16, 8}, {12, 16, 12}, {16, 16, 16},
        {12, 10, 10}, {16, 6, 6}, {16, 64, 16},
        {16, 0, 1}, {8, -1, 1},
        {-1, 16, 8}, {7, 16, 8}, {32, 16, 8},
        {INT_MIN, 16, 8}, {INT_MAX, 16, 8},
    };

    for (const auto& test : cases) {
        const int actual = SoftwareDecoderThreads::resolve(test.requested, test.available);
        if (actual != test.expected) {
            std::cerr << "requested=" << test.requested << ", available=" << test.available
                      << ": expected " << test.expected << ", got " << actual << '\n';
            return 1;
        }
    }

    std::cout << "BC-250 decoder thread policy: all 21 cases passed\n";
}
