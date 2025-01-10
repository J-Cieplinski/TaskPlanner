#include <Date.hpp>

#include <chrono>
#include <sstream>
#include <string>

#include <gtest/gtest.h>

namespace planner
{

TEST(Date, StringConstructorShouldProperlyCreateDate)
{
    const std::string CREATED_STR{"2024-06-15"};
    constexpr std::chrono::year EXPECTED_YEARS{2024};
    constexpr std::chrono::month EXPECTED_MONTHS{6};
    constexpr std::chrono::day EXPECTED_DAYS{15};

    Date date{CREATED_STR};

    EXPECT_EQ(date.getDate().year(), EXPECTED_YEARS);
    EXPECT_EQ(date.getDate().month(), EXPECTED_MONTHS);
    EXPECT_EQ(date.getDate().day(), EXPECTED_DAYS);
}

TEST(Date, YYMMDDConstructorShouldProperlyCreateDate)
{
    constexpr std::chrono::year EXPECTED_YEARS{2024};
    constexpr std::chrono::month EXPECTED_MONTHS{6};
    constexpr std::chrono::day EXPECTED_DAYS{15};
    std::chrono::year_month_day YY_MM_DD{EXPECTED_YEARS, EXPECTED_MONTHS, EXPECTED_DAYS};

    Date date{YY_MM_DD};

    EXPECT_EQ(date.getDate(), YY_MM_DD);
}

TEST(Date, StringConstructorShouldThrowOnIncorrectDateFormat)
{
    const std::string CREATED_STR{"2024-06-32"};

    EXPECT_THROW(Date{CREATED_STR}, std::runtime_error);
}

TEST(Date, StringConstructorShouldThrowOnIncorrectDate)
{
    const std::string CREATED_STR{"2024-06"};

    EXPECT_THROW(Date{CREATED_STR}, std::runtime_error);
}

TEST(Date, OperatorLessShouldProperlyEvaluate)
{
    const std::string FIRST{"2024-06-25"};
    const std::string SECOND{"2024-06-26"};
    Date first(FIRST);
    Date second(SECOND);

    EXPECT_TRUE(first < second);
    EXPECT_FALSE(second < first);
}

TEST(Date, OperatorEqualShouldProperlyEvaluate)
{
    const std::string FIRST{"2024-06-25"};
    const std::string SECOND{"2024-06-25"};
    Date first(FIRST);
    Date second(SECOND);

    EXPECT_EQ(first, second);
}

TEST(Date, ShouldProperlyPrintWithOperator)
{
    const std::string CREATED_STR{"2024-06-25"};
    Date date(CREATED_STR);
    std::stringstream ss;

    ss << date;

    EXPECT_EQ(ss.str(), CREATED_STR);
}

}  // namespace planner
