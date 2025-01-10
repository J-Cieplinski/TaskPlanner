#include <Entry.hpp>
#include <Serialization.hpp>

#include <algorithm>

namespace planner
{

namespace
{

struct PodAdapter
{
    std::int32_t y;
    std::uint32_t m;
    std::uint32_t d;
    std::int64_t duration;
    Priority priority;
};

}  // namespace

void serialize(std::ostream& stream, const Entry& entry)
{
    PodAdapter data;

    data.y = static_cast<int>(entry.dueDate.getDate().year());
    data.m = static_cast<unsigned int>(entry.dueDate.getDate().month());
    data.d = static_cast<unsigned int>(entry.dueDate.getDate().day());
    data.duration = entry.duration.getTime().to_duration().count();
    data.priority = entry.priority;

    stream.write(reinterpret_cast<const char*>(&data), sizeof(data));

    auto strLen = entry.name.length();
    stream.write(reinterpret_cast<const char*>(&strLen), sizeof(strLen));
    stream.write(reinterpret_cast<const char*>(&entry.name.front()), strLen);
}

void serialize(std::ostream& stream, std::span<Entry> entries)
{
    std::ranges::for_each(entries, [&stream](const Entry& entry) { serialize(stream, entry); });
}

std::vector<Entry> deserialize(std::istream& stream)
{
    PodAdapter data;
    std::vector<Entry> entries;

    while (not stream.read(reinterpret_cast<char*>(&data), sizeof(PodAdapter)).eof())
    {
        std::size_t strLen{0};
        std::string name{};
        stream.read(reinterpret_cast<char*>(&strLen), sizeof(strLen));

        try
        {
            name.resize(strLen);
        }
        catch (std::exception&)
        {
            return {};
        }

        stream.read(reinterpret_cast<char*>(&name.front()), strLen);

        entries.emplace_back(name, Date{data.y, data.m, data.d}, Time{data.duration},
                             data.priority);
    }

    return entries;
}

}  // namespace planner