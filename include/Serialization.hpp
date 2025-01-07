#pragma once

#include <istream>
#include <optional>
#include <ostream>
#include <span>
#include <vector>

namespace planner
{

class Entry;

void serialize(std::ostream& stream, const Entry& entry);
void serialize(std::ostream& stream, std::span<Entry> entry);
std::vector<Entry> deserialize(std::istream& stream);

}  // namespace planner
