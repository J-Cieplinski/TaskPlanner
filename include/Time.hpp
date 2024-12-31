#pragma once

#include <chrono>
#include <cstdint>
#include <string>

namespace planner::time
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
private:
    hh_mm_ss createFromString(std::string_view time) const;
    std::pair<std::chrono::seconds, std::size_t> extractSecondsFromTimeUnit(const std::string_view str, std::chrono::seconds multiplier) const;

    hh_mm_ss time_;
};

std::ostream& operator<<(std::ostream& os, const Time& time);

} // namespace planner::time