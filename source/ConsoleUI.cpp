#include <ConsoleUI.hpp>

#include <iostream>

#include <fmt/printf.h>

namespace planner
{

void ConsoleUI::PrintEntries(std::span<Entry> entries)
{
    fmt::print("{:_^21}{:_^21}{:_^21}{:_^22}\n", "_", "_", "_", "_");
    fmt::print("|{:^20}|{:^20}|{:^20}|{:^20}|\n", "Name", "Deadline", "Duration", "Priority");

    for (const auto& entry : entries)
    {
        fmt::print("{}\n", entry);
    }

    fmt::print("|{:_^20}|{:_^20}|{:_^20}|{:_^20}|\n", "_", "_", "_", "_");
}

void ConsoleUI::ShowOptions()
{
    fmt::print("1. {}\n2. {}\n3. {}\n4. {}\n5. {}\n6. {}\n", "Add Entry", "Remove Entry",
               "Save to file", "Load from file", "Sort", "Exit");
}

void ConsoleUI::ClearConsole()
{
#if defined _WIN32
    system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif
}

int ConsoleUI::GetSelection()
{
    int choice{0};
    std::cin >> choice;
    return choice;
}

std::filesystem::path ConsoleUI::GetPath()
{
    std::filesystem::path path;
    fmt::print("Enter path: ");
    std::cin >> path;

    return path;
}

std::optional<Entry> ConsoleUI::FillEntry()
{
    std::string name;
    std::string dueDate;
    std::string duration;
    int priority;

    fmt::print("Task name: ");
    std::cin.clear();
    std::getline(std::cin >> std::ws, name);

    fmt::print("Due date in YYYY-MM-DD format: ");
    std::cin >> dueDate;
    fmt::print("Duration: ");
    std::cin >> duration;
    fmt::print("Priority:\n1.{}\n2.{}\n3.{}\n", Priority::LOW, Priority::NORMAL, Priority::HIGH);
    std::cin >> priority;

    try
    {
        Entry entry{
            .name = std::move(name),
            .dueDate = Date{dueDate},
            .duration = Time{duration},
            .priority = static_cast<Priority>(priority),
        };

        return entry;
    }
    catch (std::exception& e)
    {
        fmt::print("Unable to construct entry with msg: {}\n", e.what());
    }

    return std::nullopt;
}

std::optional<Entry> ConsoleUI::GetEntryForRemoval(std::span<Entry> entries)
{
    std::string name;
    fmt::print("Enter name of entry for removal: ");
    std::cin.clear();
    std::getline(std::cin >> std::ws, name);

    auto it
        = std::ranges::find_if(entries, [&name](const Entry& entry) { return entry.name == name; });

    return it != entries.end() ? std::optional{*it} : std::nullopt;
}

}  // namespace planner
