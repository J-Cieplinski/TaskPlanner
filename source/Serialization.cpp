#include <Entry.hpp>
#include <Serialization.hpp>

#include <algorithm>

namespace planner
{

namespace
{

struct PodAdapter
{
    std::string_view name;
    std::uint16_t y;
    std::uint16_t m;
    std::uint16_t d;
    std::uint32_t duration;
    Priority priority;
};

} // namespace


void serialize(std::ostream& stream, const Entry& entry)
{
    PodAdapter data;

    data.name = entry.name.c_str();
    data.y = static_cast<int>(entry.dueDate.getDate().year());
    data.m = static_cast<unsigned int>(entry.dueDate.getDate().month());
    data.d = static_cast<unsigned int>(entry.dueDate.getDate().day());
    data.duration = entry.duration.getTime().to_duration().count();
    data.priority = entry.priority;

    stream.write(reinterpret_cast<const char*>(&data), sizeof(data));
}

void serialize(std::ostream& stream, std::span<Entry> entries)
{
    std::ranges::for_each(entries, [&stream](const Entry& entry) {
        serialize(stream, entry);
    });
}

std::vector<Entry> deserialize(std::istream& stream)
{
    PodAdapter data;
    std::vector<Entry> entries;

    while(not stream.read(reinterpret_cast<char*>(&data), sizeof(PodAdapter)).eof())
    {
        entries.emplace_back(std::string{data.name}, Date{data.y, data.m, data.d}, Time{data.duration}, data.priority);
    }

    return entries;
}

} // namespace planner