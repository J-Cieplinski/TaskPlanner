#include <App.hpp>

#include <ConsoleUI.hpp>
#include <Serialization.hpp>
#include <Sorters.hpp>

namespace planner
{

namespace
{

enum Options
{
    ADD = 1,
    REMOVE,
    SAVE,
    LOAD,
    SORT,
    EXIT
};

}  // namespace

void App::run()
{
    bool shouldRefresh{true};
    while (true)
    {
        if (shouldRefresh)
        {
            ConsoleUI::ClearConsole();
            ConsoleUI::PrintEntries(entries_);
            ConsoleUI::ShowOptions();

            shouldRefresh = false;
        }

        if (auto option = ConsoleUI::GetSelection())
        {
            switch (option)
            {
                case Options::ADD:
                {
                    if (auto entry = ConsoleUI::FillEntry())
                    {
                        entries_.emplace_back(std::move(*entry));
                    }
                    break;
                }
                case Options::REMOVE:
                {
                    if (auto entry = ConsoleUI::GetEntryForRemoval(entries_))
                    {
                        std::erase(entries_, *entry);
                    }
                    break;
                }
                case Options::SAVE:
                {
                    const auto path = ConsoleUI::GetPath();
                    saveEntries(path);
                    break;
                }
                case Options::LOAD:
                {
                    const auto path = ConsoleUI::GetPath();
                    loadEntries(path);
                    break;
                }
                case Options::SORT:
                {
                    SortByField<&Entry::dueDate>(entries_);
                    break;
                }
                case Options::EXIT:
                {
                    ConsoleUI::ClearConsole();
                    return;
                }
            }

            shouldRefresh = true;
        }
    }
}

void App::loadEntries(const std::filesystem::path& path)
{
    std::ifstream file(path);
    if (not file.is_open())
    {
        fmt::print("Invalid path {}", path.string());
        return;
    }

    entries_ = deserialize(file);
}

void App::saveEntries(const std::filesystem::path& path)
{
    std::ofstream file(path);
    if (not file.is_open())
    {
        fmt::print("Invalid path {}", path.string());
        return;
    }

    serialize(file, entries_);
}

}  // namespace planner