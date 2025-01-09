#pragma once

#include <Entry.hpp>

#include <filesystem>
#include <optional>
#include <span>
#include <string_view>

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

    template <typename... Args> static void WriteToLog(std::string_view fmt, Args... args);
};

}  // namespace planner

/*
 * Template implememntation
 */

#include <fmt/os.h>

namespace planner
{

extern fmt::ostream LOG_FILE;

template <typename... Args> void ConsoleUI::WriteToLog(std::string_view fmt, Args... args)
{
    LOG_FILE.print(fmt::runtime_format_string({fmt}), std::forward<Args>(args)...);
    LOG_FILE.flush();
}

}  // namespace planner
