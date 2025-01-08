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
    fmt::print("1. Add Entry\n");
    fmt::print("2. Remove Entry\n");
    fmt::print("3. Save to file\n");
    fmt::print("4. Load from file\n");
    fmt::print("5. Sort\n");
    fmt::print("6. Exit\n");
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

}  // namespace planner
