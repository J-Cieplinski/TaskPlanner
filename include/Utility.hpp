#pragma once

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <cstdint>

namespace planner
{

enum class Priority : std::uint8_t
{
    LOW,
    NORMAL,
    HIGH
};

inline bool operator<(Priority left, Priority right)
{
    return static_cast<std::uint8_t>(left) > static_cast<std::uint8_t>(right);
}

inline std::ostream& operator<<(std::ostream& os, Priority priority)
{
    switch (priority)
    {
        case Priority::LOW:
            return os << "LOW";
        case Priority::NORMAL:
            return os << "NORMAL";
        case Priority::HIGH:
            return os << "HIGH";
        default:
            return os << "UNKNOWN";
    }
}

}  // namespace planner

// clang-format off
template <> struct fmt::formatter<planner::Priority> : ostream_formatter {};