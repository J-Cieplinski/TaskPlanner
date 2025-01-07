#pragma once

#include <Entry.hpp>

#include <algorithm>
#include <functional>

namespace planner
{

template <auto field> void SortByField(std::span<Entry> entries)
{
    std::ranges::sort(
        entries, [](const Entry& left, const Entry& right) { return left.*field < right.*field; });
}

void CustomSort(std::span<Entry> entries,
                std::function<bool(const Entry& left, const Entry& right)> pred)
{
    std::ranges::sort(entries, pred);
}

}  // namespace planner
