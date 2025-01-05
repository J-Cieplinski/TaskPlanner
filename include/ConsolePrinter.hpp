#pragma once

#include <Entry.hpp>

namespace planner
{

class ConsolePrinter
{
public:
    static void Print(const std::vector<Entry>& entries);
};

} // namespace planner