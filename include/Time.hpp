#pragma once

#include <fmt/ostream.h>

#include <chrono>
#include <cstdint>
#include <string>

namespace planner
{

class Time
{
    using hh_mm_ss = std::chrono::hh_mm_ss<std::chrono::seconds>;

public:
    Time(std::uint32_t time);
    Time(hh_mm_ss time);
    Time(std::string_view time);

    hh_mm_ss getTime() const;

    friend std::ostream& operator<<(std::ostream& os, const Time& time);

    bool operator<(const Time& other) const;
    bool operator==(const Time& other) const;

private:
    hh_mm_ss createFromString(std::string_view time) const;
    std::pair<std::chrono::seconds, std::size_t> extractSecondsFromTimeUnit(
        std::string_view str, std::chrono::seconds multiplier) const;

    hh_mm_ss time_;
};

std::ostream& operator<<(std::ostream& os, const Time& time);

}  // namespace planner

// clang-format off
template <> struct fmt::formatter<planner::Time> : ostream_formatter {};