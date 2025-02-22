#include <Time.hpp>

#include <string>

#include <gtest/gtest.h>

namespace planner
{

TEST(Time, StringConstructorShouldProperlyCreateTime)
{
    const std::string CREATED_STR{"01:23:25"};
    constexpr std::chrono::hours EXPECTED_HOURS{1};
    constexpr std::chrono::minutes EXPECTED_MINUTES{23};
    constexpr std::chrono::seconds EXPECTED_SECONDS{25};

    Time time{CREATED_STR};

    EXPECT_EQ(time.getTime().hours(), EXPECTED_HOURS);
    EXPECT_EQ(time.getTime().minutes(), EXPECTED_MINUTES);
    EXPECT_EQ(time.getTime().seconds(), EXPECTED_SECONDS);
}

TEST(Time, StringConstructorShouldProperlyCreateTimeFromIncorrectInput)
{
    const std::string CREATED_STR{"01:61:61"};
    constexpr std::chrono::hours EXPECTED_HOURS{2};
    constexpr std::chrono::minutes EXPECTED_MINUTES{2};
    constexpr std::chrono::seconds EXPECTED_SECONDS{1};

    Time time{CREATED_STR};

    EXPECT_EQ(time.getTime().hours(), EXPECTED_HOURS);
    EXPECT_EQ(time.getTime().minutes(), EXPECTED_MINUTES);
    EXPECT_EQ(time.getTime().seconds(), EXPECTED_SECONDS);
}

TEST(Time, IntConstructorShouldProperlyCreateTime)
{
    constexpr std::uint32_t CREATED_SECONDS{5005};

    constexpr std::chrono::hours EXPECTED_HOURS{1};
    constexpr std::chrono::minutes EXPECTED_MINUTES{23};
    constexpr std::chrono::seconds EXPECTED_SECONDS{25};

    Time time{CREATED_SECONDS};

    EXPECT_EQ(time.getTime().hours(), EXPECTED_HOURS);
    EXPECT_EQ(time.getTime().minutes(), EXPECTED_MINUTES);
    EXPECT_EQ(time.getTime().seconds(), EXPECTED_SECONDS);
}

TEST(Time, ShouldProperlyPrintWithOperator)
{
    const std::string EXPECTED_STRING{"01:23:25"};

    Time time{EXPECTED_STRING};

    std::stringstream ss;
    ss << time;

    EXPECT_EQ(ss.str(), EXPECTED_STRING);
}

TEST(Time, OperatorLessShouldProperlyEvaluate)
{
    const std::string FIRST{"01:23:24"};
    const std::string SECOND{"01:23:25"};

    Time first{FIRST};
    Time second{SECOND};

    EXPECT_TRUE(first < second);
}

TEST(Time, OperatorEqualShouldProperlyEvaluate)
{
    const std::string FIRST{"01:23:25"};
    const std::string SECOND{"01:23:25"};

    Time first{FIRST};
    Time second{SECOND};

    EXPECT_EQ(first, second);
}

}  // namespace planner
