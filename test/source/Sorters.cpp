#include <Sorters.hpp>

#include <gtest/gtest.h>

namespace planner
{

namespace
{

const planner::Entry entry{
    .name = "TEST",
    .dueDate = planner::Date{"2024-12-01"},
    .duration = planner::Time("23:00:00"),
    .priority = planner::Priority::HIGH,
};

const planner::Entry entry1{
    .name = "TEST 2",
    .dueDate = planner::Date{"2025-12-01"},
    .duration = planner::Time("02:41:45"),
    .priority = planner::Priority::NORMAL,
};

const planner::Entry entry2{
    .name = "TEST 2",
    .dueDate = planner::Date{"2025-12-02"},
    .duration = planner::Time("02:41:41"),
    .priority = planner::Priority::LOW,
};

} // namespace

TEST(SortByField, ShouldProperlySortByDueDate)
{
    std::vector entries {entry1, entry2, entry};
    const std::vector EXPECTED_ENTRIES {entry, entry1, entry2};

    SortByField<&Entry::dueDate>(entries);

    EXPECT_EQ(entries, EXPECTED_ENTRIES);
}

TEST(SortByField, ShouldProperlySortByDuration)
{
    std::vector entries {entry1, entry2, entry};
    const std::vector EXPECTED_ENTRIES {entry2, entry1, entry};

    SortByField<&Entry::duration>(entries);

    EXPECT_EQ(entries, EXPECTED_ENTRIES);
}

TEST(SortByField, ShouldProperlySortByPriority)
{
    std::vector entries {entry1, entry2, entry};
    const std::vector EXPECTED_ENTRIES {entry, entry1, entry2};

    SortByField<&Entry::priority>(entries);

    EXPECT_EQ(entries, EXPECTED_ENTRIES);
}

} // namespace planner
