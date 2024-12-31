#include <Time.hpp>

#include <string>

#include <gtest/gtest.h>

namespace planner
{

TEST(Time, StringConstructorShouldProperlyCreateTime)
{
    const std::string CREATED_STR {"01:23:25"};
    constexpr std::uint32_t EXPECTED_HOURS {1};
    constexpr std::uint32_t EXPECTED_MINUTES {23};
    constexpr std::uint32_t EXPECTED_SECONDS {25};

    Time time{CREATED_STR};

    EXPECT_EQ(time.getTime().hours(), std::chrono::hours(EXPECTED_HOURS));
    EXPECT_EQ(time.getTime().minutes(), std::chrono::minutes(EXPECTED_MINUTES));
    EXPECT_EQ(time.getTime().seconds(), std::chrono::seconds(EXPECTED_SECONDS));
}

TEST(Time, IntConstructorShouldProperlyCreateTime)
{
    const std::string EXPECTED_STRING {"01:23:25"};
    constexpr std::uint32_t CREATED_SECONDS {5005};

    Time time{CREATED_SECONDS};

    std::stringstream ss;
    ss << time;

    EXPECT_EQ(ss.str(), EXPECTED_STRING);
}

} // namespace planner



