#pragma once

#include <Entry.hpp>

namespace planner
{

class ConsolePrinter
{
public:
    static void Print(std::span<Entry> entries);
};

}  // namespace planner