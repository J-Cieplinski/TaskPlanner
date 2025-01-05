#pragma once

#include <Entry.hpp>

#include <algorithm>

namespace planner
{

template <auto field>
void SortByField(std::vector<Entry>& entries)
{
    std::sort(entries.begin(), entries.end(), [](const Entry& left, const Entry& right) {
        return left.*field < right.*field;
    });
}

} // namespace planner
