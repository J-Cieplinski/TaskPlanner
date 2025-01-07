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

    std::ofstream file("test.bin", std::ios::out | std::ios::binary);
    if(!file.is_open())
    {
        throw std::runtime_error("File not opened");
    }

    planner::serialize(file, entry);

    file.close();


    std::ifstream fileI("test.bin", std::ios::in | std::ios::binary);
    planner::ConsolePrinter::Print({planner::deserialize(fileI)});

    return 0;
}
