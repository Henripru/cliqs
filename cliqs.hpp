#ifndef CLIQS_HPP
#define CLIQS_HPP

#include <functional>
#include <string>
#include <vector>

namespace cliqs
{

struct Task
{
    std::string Name;
    std::function<void()> Task;
};

/// @brief Blocking call that Runs CLI until Quit is selected.
void Run(const std::string& appName, const std::vector<Task>& tasks);

}

#endif