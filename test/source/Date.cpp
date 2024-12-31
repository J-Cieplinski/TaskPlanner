#include <Date.hpp>

#include <string>

#include <gtest/gtest.h>

namespace planner
{

TEST(Date, StringConstructorShouldProperlyCreateDate)
{
    const std::string CREATED_STR {"2024-06-15"};
    constexpr std::uint32_t EXPECTED_YEARS {2024};
    constexpr std::uint32_t EXPECTED_MONTHS {6};
    constexpr std::uint32_t EXPECTED_DAYS {15};

    Date date{CREATED_STR};

    EXPECT_EQ(date.getDate().year(), std::chrono::year(EXPECTED_YEARS));
    EXPECT_EQ(date.getDate().month(), std::chrono::month(EXPECTED_MONTHS));
    EXPECT_EQ(date.getDate().day(), std::chrono::day(EXPECTED_DAYS));
}

TEST(Date, StringConstructorShouldThrowOnIncorrectDate)
{
    const std::string CREATED_STR {"2024-06"};

    EXPECT_THROW(Date{CREATED_STR}, std::runtime_error);
}

} // namespace planner



