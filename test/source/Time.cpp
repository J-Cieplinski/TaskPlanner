#include <doctest/doctest.h>
#include <Time.hpp>
#include <greeter/version.h>

#include <string>

namespace planner::time
{

TEST_CASE("Time")
{
    Time time{"01:23:25"};

    CHECK_EQ(time.getTime().hours(), std::chrono::hours(1));
    CHECK_EQ(time.getTime().minutes(), std::chrono::minutes(23));
    CHECK_EQ(time.getTime().seconds(), std::chrono::seconds(25));
}

TEST_CASE("TimeString")
{
    const std::string expected {"01:23:25"};
    constexpr std::uint32_t seconds {5005};
    Time time{seconds};
    std::stringstream ss;
    ss << time;
    CHECK_EQ(ss.str(), expected);
}

} // namespace planner::time



