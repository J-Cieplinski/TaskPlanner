#pragma once

#include <fmt/ostream.h>

#include <chrono>
#include <string>

namespace planner
{

class Date
{
    using year_month_day = std::chrono::year_month_day;

public:
    Date(const std::string& date);
    Date(const year_month_day& date);
    Date(std::int32_t y, std::uint32_t m, std::uint32_t d);

    year_month_day getDate() const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;

private:
    year_month_day date_;
};

}  // namespace planner

// clang-format off
template <> struct fmt::formatter<planner::Date> : ostream_formatter {};