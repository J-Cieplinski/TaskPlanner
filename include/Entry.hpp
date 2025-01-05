#pragma once

#include <Date.hpp>
#include <Time.hpp>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <string>

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

namespace planner
{

struct Entry
{
    std::string name;
    Date dueDate;
    Time duration;
    Priority priority;
};

inline bool operator==(const Entry& left, const Entry& right)
{
    return std::tie(left.name, left.dueDate, left.duration, left.priority)
        == std::tie(right.name, right.dueDate, right.duration, right.priority);
}

inline std::ostream& operator<<(std::ostream& os, const Entry& entry)
{
    return os << fmt::format("|{:^20s}|{:^20s}|{:^20s}|{:^20s}|", entry.name, entry.dueDate,
                                     entry.duration, entry.priority);
}

}  // namespace planner

// clang-format off
template <> struct fmt::formatter<planner::Entry> : ostream_formatter {};