#include <Time.hpp>

namespace planner
{

Time::Time(std::uint32_t time)
    : time_{std::chrono::seconds{time}}
{
}

Time::Time(hh_mm_ss time)
    : time_{time}
{
}

Time::Time(std::string_view time)
    : time_{createFromString(time)}
{
}

Time::hh_mm_ss Time::getTime() const
{
    return time_;
}

Time::hh_mm_ss Time::createFromString(std::string_view time) const
{
    using namespace std::chrono_literals;

    auto [hours, hPos] = extractSecondsFromTimeUnit(time, 3600s);

    if (hPos == time.npos)
    {
        return Time::hh_mm_ss{hours};
    }

    std::string mTime{time.substr(hPos + 1, time.size())};

    auto [minutes, mPos] = extractSecondsFromTimeUnit(mTime, 60s);

    if (mPos == mTime.npos)
    {
        return Time::hh_mm_ss{hours + minutes};
    }

    std::string sTime{mTime.substr(mPos + 1, mTime.size())};

    auto [seconds, _] = extractSecondsFromTimeUnit(sTime, 1s);

    return Time::hh_mm_ss{std::chrono::seconds{hours + minutes + seconds}};
}

std::pair<std::chrono::seconds, std::size_t> Time::extractSecondsFromTimeUnit(
    std::string_view str, std::chrono::seconds multiplier) const
{
    auto pos = str.find_first_of(':');
    auto unitStr = pos != str.npos ? std::string{str.substr(0, pos)} : std::string{str};

    auto unit = std::stoi(unitStr);

    return {unit * multiplier, pos};
}

std::ostream& operator<<(std::ostream& os, const Time& time)
{
    os << time.time_;
    return os;
}

}  // namespace planner
