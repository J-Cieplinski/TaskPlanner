#include <Entry.hpp>
#include <Serialization.hpp>

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

Entry deserialize(std::istream& stream)
{
    PodAdapter* data;
    auto str = new char[sizeof(PodAdapter)];
    stream.read(str, sizeof(PodAdapter));
    data = reinterpret_cast<PodAdapter*>(str);

    return {
            .name = std::string{data->name},
            .dueDate = Date{data->y, data->m, data->d},
            .duration = Time{data->duration},
            .priority = data->priority
        };
}

} // namespace planner