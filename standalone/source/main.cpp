#include <Entry.hpp>

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

    std::cout << entry;
    return 0;
}
