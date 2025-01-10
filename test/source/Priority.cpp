#include <Priority.hpp>

#include <sstream>
#include <string>

#include <gtest/gtest.h>

namespace planner
{

class PriorityTest : public testing::TestWithParam<std::pair<Priority, std::string>>
{
};

INSTANTIATE_TEST_SUITE_P(Params, PriorityTest,
                         testing::Values(std::make_pair(Priority::LOW, "LOW"),
                                         std::make_pair(Priority::NORMAL, "NORMAL"),
                                         std::make_pair(Priority::HIGH, "HIGH"),
                                         std::make_pair(static_cast<Priority>(-1), "UNKNOWN")));

TEST_P(PriorityTest, ShouldProperlyPrintWithOperator)
{
    const auto& [priority, EXPECTED_STRING] = GetParam();

    std::stringstream ss;
    ss << priority;

    EXPECT_EQ(ss.str(), EXPECTED_STRING);
}

TEST_F(PriorityTest, LessOperatorShouldProperlyEvaluate)
{
    EXPECT_TRUE(Priority::HIGH < Priority::LOW);
    EXPECT_TRUE(Priority::NORMAL < Priority::LOW);
    EXPECT_TRUE(Priority::HIGH < Priority::NORMAL);
}

}  // namespace planner
