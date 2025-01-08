#pragma once

#include <Entry.hpp>

#include <filesystem>
#include <vector>

namespace planner
{

class App
{
public:
    void run();
    void loadEntries(const std::filesystem::path& path);
    void saveEntries(const std::filesystem::path& path);

private:
    std::vector<Entry> entries_;
};

}  // namespace planner
