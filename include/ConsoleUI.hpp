#pragma once

#include <Entry.hpp>

#include <filesystem>
#include <optional>
#include <span>

namespace planner
{

class ConsoleUI
{
public:
    static void PrintEntries(std::span<Entry> entries);
    static void ShowOptions();
    static void ClearConsole();
    static int GetSelection();
    static std::filesystem::path GetPath();
    static std::optional<Entry> FillEntry();
    static std::optional<Entry> GetEntryForRemoval(std::span<Entry> entries);
};

}  // namespace planner