#pragma once

#include <Date.hpp>
#include <Time.hpp>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <string>

namespace planner
{

enum class Priority
{
    LOW,
    NORMAL,
    HIGH
};

inline std::ostream& operator<<(std::ostream& os, Priority priority)
{
    switch(priority)
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

} // namespace planner

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

inline std::ostream& operator<<(std::ostream& os, Entry& entry)
{
    std::string output = fmt::format("|{:^20s}|{:^20s}|{:^20s}|{:^20s}|", entry.name, entry.dueDate, entry.duration, entry.priority);
    return os << output;
}

} // namespace planner

template <> struct fmt::formatter<planner::Entry> : ostream_formatter {};