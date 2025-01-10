#include <Entry.hpp>

#include <sstream>
#include <string>

#include <fmt/format.h>
#include <gtest/gtest.h>

namespace planner
{

TEST(Entry, OperatorEqualShouldReturnTrueForTheSameObject)
{
    const Entry ENTRY{
        .name = "TEST",
        .dueDate = Date{"2024-12-01"},
        .duration = Time("23:00:00"),
        .priority = Priority::HIGH,
    };

    EXPECT_EQ(ENTRY, ENTRY);
}

TEST(Entry, OperatorEqualShouldReturnFalseForDifferentObjects)
{
    const Entry ENTRY{
        .name = "TEST",
        .dueDate = Date{"2024-12-01"},
        .duration = Time("23:00:00"),
        .priority = Priority::HIGH,
    };

    const Entry SECOND_ENTRY{
        .name = "TEST1",
        .dueDate = Date{"2024-12-01"},
        .duration = Time("23:00:00"),
        .priority = Priority::HIGH,
    };

    EXPECT_NE(ENTRY, SECOND_ENTRY);
}

TEST(Entry, ShouldProperlyPrintWithOperator)
{
    const Entry ENTRY{
        .name = "TEST",
        .dueDate = Date{"2024-12-01"},
        .duration = Time("23:00:00"),
        .priority = Priority::HIGH,
    };

    const auto EXPECTED_STRING{
        fmt::format("|{:^20s}|{:^20s}|{:^20s}|{:^20s}|", "TEST", "2024-12-01", "23:00:00", "HIGH")};

    std::stringstream ss;

    ss << ENTRY;

    EXPECT_EQ(ss.str(), EXPECTED_STRING);
}

}  // namespace planner
