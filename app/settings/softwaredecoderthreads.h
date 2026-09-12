#pragma once

#include <algorithm>

namespace SoftwareDecoderThreads {

constexpr int Default = 8;

inline int normalize(int requested)
{
    switch (requested) {
    case 0: // Auto
    case 4:
    case 8:
    case 12:
    case 16:
        return requested;
    default:
        return 0;
    }
}

inline int resolve(int requested, int available)
{
    requested = normalize(requested);
    return std::min(requested == 0 ? Default : requested, std::max(1, available));
}

}
