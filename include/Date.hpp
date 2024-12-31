#pragma once

#include <chrono>
#include <string_view>

namespace planner::date
{

class Date
{
using year_month_day = std::chrono::year_month_day;
public:
    Date(std::string_view date);
    Date(const year_month_day& date);

    year_month_day getDate() const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
private:
    year_month_day date_;
};

} // namespace planner::date
