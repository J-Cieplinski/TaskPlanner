#include <Sorters.hpp>

#include <gtest/gtest.h>

namespace planner
{

namespace
{

const Entry entry{
    .name = "TEST",
    .dueDate = Date{"2024-12-01"},
    .duration = Time("23:00:00"),
    .priority = Priority::HIGH,
};

const Entry entry1{
    .name = "TEST 2",
    .dueDate = Date{"2025-12-01"},
    .duration = Time("02:41:45"),
    .priority = Priority::NORMAL,
};

const Entry entry2{
    .name = "TEST 3",
    .dueDate = Date{"2025-12-02"},
    .duration = Time("02:41:41"),
    .priority = Priority::LOW,
};

}  // namespace

TEST(SortByField, ShouldProperlySortByDueDate)
{
    std::vector entries{entry1, entry2, entry};
    const std::vector EXPECTED_ENTRIES{entry, entry1, entry2};

    SortByField<&Entry::dueDate>(entries);

    EXPECT_EQ(entries, EXPECTED_ENTRIES);
}

TEST(SortByField, ShouldProperlySortByDuration)
{
    std::vector entries{entry1, entry2, entry};
    const std::vector EXPECTED_ENTRIES{entry2, entry1, entry};

    SortByField<&Entry::duration>(entries);

    EXPECT_EQ(entries, EXPECTED_ENTRIES);
}

TEST(SortByField, ShouldProperlySortByPriority)
{
    std::vector entries{entry1, entry2, entry};
    const std::vector EXPECTED_ENTRIES{entry, entry1, entry2};

    SortByField<&Entry::priority>(entries);

    EXPECT_EQ(entries, EXPECTED_ENTRIES);
}

TEST(CustomSort, ShouldProperlySortWithCustomSorter)
{
    std::vector entries{entry1, entry2, entry};
    const std::vector EXPECTED_ENTRIES{entry2, entry1, entry};
    auto pred = [](const Entry& left, const Entry& right) -> bool
    { return left.duration < right.duration; };

    CustomSort(entries, pred);

    EXPECT_EQ(entries, EXPECTED_ENTRIES);
}

}  // namespace planner
