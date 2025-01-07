#pragma once

#include <Date.hpp>
#include <Time.hpp>
#include <Utility.hpp>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <string>

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