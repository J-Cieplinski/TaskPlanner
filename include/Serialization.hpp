#pragma once

#include <istream>
#include <ostream>
#include <vector>

namespace planner
{

class Entry;

void serialize(std::ostream& stream, const Entry& entry);
Entry deserialize(std::istream& stream);

} // namespace planner
