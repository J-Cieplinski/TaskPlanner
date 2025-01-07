#pragma once

#include <fmt/ostream.h>

#include <chrono>
#include <string_view>

namespace planner
{

class Date
{
    using year_month_day = std::chrono::year_month_day;

public:
    Date(std::string_view date);
    Date(const year_month_day& date);
    Date(std::uint16_t y, std::uint16_t m, std::uint16_t d);

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