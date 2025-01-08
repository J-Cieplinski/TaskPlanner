#pragma once

#include <Entry.hpp>

#include <filesystem>
#include <optional>

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
};

}  // namespace planner