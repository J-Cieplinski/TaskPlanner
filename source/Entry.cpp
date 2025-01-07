#include <Entry.hpp>

namespace planner
{

namespace
{

struct Data
{
    std::string_view name;
    std::uint16_t y;
    std::uint16_t m;
    std::uint16_t d;
    std::uint32_t duration;
    Priority priority;
};

} // namespace


void serialize(std::ofstream& stream, const Entry& entry)
{
    Data data;

    data.name = entry.name.c_str();
    data.y = static_cast<int>(entry.dueDate.getDate().year());
    data.m = static_cast<unsigned int>(entry.dueDate.getDate().month());
    data.d = static_cast<unsigned int>(entry.dueDate.getDate().day());
    data.duration = entry.duration.getTime().to_duration().count();
    data.priority = entry.priority;

    stream.write(reinterpret_cast<const char*>(&data), sizeof(data));
}

template<class T> void ignore( const T& ) { };

Entry deserialize(std::ifstream& stream)
{
    using namespace std::chrono;

    Data* data;
    auto str = new char[sizeof(Data)];
    stream.read(str, sizeof(Data));
    data = reinterpret_cast<Data*>(str);

    return {
            .name = std::string{data->name},
            .dueDate = Date{data->y, data->m, data->d},
            .duration = Time{data->duration},
            .priority = data->priority
        };
}

} // namespace planner

