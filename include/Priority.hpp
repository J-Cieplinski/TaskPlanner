#pragma once

#include <cstdint>

#include <fmt/format.h>
#include <fmt/ostream.h>

namespace planner
{

enum class Priority
{
    HIGH = 1,
    NORMAL,
    LOW
};

inline bool operator<(Priority left, Priority right)
{
    // While not being logical that HIGH < LOW it helps with sorting
    // so HIGH takes precedence over LOW when sorting by less
    return static_cast<std::uint8_t>(left) < static_cast<std::uint8_t>(right);
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