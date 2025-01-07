#include <Serialization.hpp>

#include <Entry.hpp>

#include <algorithm>

#include <gtest/gtest.h>

namespace planner
{

TEST(SerializeDeserialize, ShouldSerializeAndDeserializeCorrectly)
{
    const Entry INPUT_ENTRY{
        .name = "TEST",
        .dueDate = planner::Date{"2024-12-01"},
        .duration = planner::Time("23"),
        .priority = planner::Priority::HIGH,
    };

    std::stringstream ss;

    serialize(ss, INPUT_ENTRY);

    EXPECT_EQ(INPUT_ENTRY, deserialize(ss).front());
}

TEST(SerializeDeserialize, ShouldSerializeAndDeserializeCorrectlyASeriesOfEntries)
{
    const Entry INPUT_ENTRY{
        .name = "TEST",
        .dueDate = planner::Date{"2024-12-01"},
        .duration = planner::Time("21"),
        .priority = planner::Priority::HIGH,
    };

    const Entry INPUT_ENTRY2{
        .name = "TEST2",
        .dueDate = planner::Date{"2024-12-02"},
        .duration = planner::Time("22"),
        .priority = planner::Priority::NORMAL,
    };

    const Entry INPUT_ENTRY3{
        .name = "TEST3",
        .dueDate = planner::Date{"2024-12-03"},
        .duration = planner::Time("23"),
        .priority = planner::Priority::LOW,
    };

    std::vector INPUT_ENTRIES{INPUT_ENTRY, INPUT_ENTRY2, INPUT_ENTRY3};

    std::stringstream ss;

    serialize(ss, INPUT_ENTRIES);

    EXPECT_EQ(deserialize(ss), INPUT_ENTRIES);
}

TEST(Deserialize, ShouldDoNothingOnEmptyStream)
{
    std::stringstream ss;

    EXPECT_TRUE(deserialize(ss).empty());
}

}  // namespace planner
