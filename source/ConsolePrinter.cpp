#include <ConsolePrinter.hpp>

#include <ranges>

#include <fmt/printf.h>

namespace planner
{

void ConsolePrinter::Print(const std::vector<Entry>& entries)
{
    fmt::print("{:_^21}{:_^21}{:_^21}{:_^22}\n", "_","_","_","_");
    fmt::print("|{:^20}|{:^20}|{:^20}|{:^20}|\n", "Name","Deadline","Duration","Priority");

    for(const auto& entry : entries)
    {
        fmt::print("{}\n", entry);
    }

    fmt::print("|{:_^20}|{:_^20}|{:_^20}|{:_^20}|\n", "_","_","_","_");
}

} // namespace planner
