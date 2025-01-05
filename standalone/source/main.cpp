#include <Entry.hpp>
#include <ConsolePrinter.hpp>

#include <cxxopts.hpp>
#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    planner::Entry entry{
        .name = "TEST",
        .dueDate = planner::Date{"2024-12-01"},
        .duration = planner::Time("23"),
        .priority = planner::Priority::HIGH,
    };

    planner::Entry entry1{
        .name = "TEST 2",
        .dueDate = planner::Date{"2025-12-01"},
        .duration = planner::Time("2:4:4"),
        .priority = planner::Priority::LOW,
    };

    planner::ConsolePrinter::Print({entry, entry1});

    return 0;
}
