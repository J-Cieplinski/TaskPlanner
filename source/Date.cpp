#include <Date.hpp>

#include <sstream>

namespace planner
{

Date::Date(std::string_view date)
{
    std::string dateStr{date};
    std::stringstream ss(dateStr);

    if (not std::chrono::from_stream(ss, "%F", date_))
    {
        throw std::runtime_error(dateStr + " is not a valid date format");
    }
}

Date::Date(const year_month_day& date)
    : date_{date}
{
}

Date::Date(std::uint16_t y, std::uint16_t m, std::uint16_t d)
    : date_{std::chrono::year{y}, std::chrono::month{m}, std::chrono::day{d}}
{
}

Date::year_month_day Date::getDate() const
{
    return date_;
}

bool Date::operator<(const Date& other) const
{
    return date_ < other.date_;
}

bool Date::operator==(const Date& other) const
{
    return date_ == other.date_;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.date_;
    return os;
}

}  // namespace planner
