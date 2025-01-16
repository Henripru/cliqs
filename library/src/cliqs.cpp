#include "cliqs.hpp"

#include <climits>
#include <iostream>

namespace cliqs
{

void ShowMenu(const std::string& appName, const std::vector<Task>& tasks)
{
    std::cout << "*------------------------------------*\n|";
    for (size_t i = 0; i < 18 - (appName.length() / 2); ++i) std::cout << " ";
    std::cout << appName;
    for (size_t i = 0; i < 18 - (appName.length() / 2); ++i) std::cout << " ";
    std::cout << "|\n*------------------------------------*\n";

    size_t i = 0;
    for (; i < tasks.size(); ++i)
    {
        std::cout << i << " - " << tasks[i].Name << std::endl;
    }
    std::cout << i << " - Quit" << std::endl;
}

size_t GetChoice(const std::vector<Task>& tasks)
{
    size_t choice = SIZE_MAX;
    bool isValidChoice = false;
    do {
        std::cout << "Enter choice: ";
        std::cin >> choice;

        isValidChoice = !std::cin.fail() && choice <= tasks.size();

        if (!isValidChoice)
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid choice. Try again..." << std::endl;
        }
    } while(!isValidChoice);

    return choice;
}

void Run(const std::string& appName, const std::vector<Task>& tasks)
{
    size_t choice;
    bool isQuit;
    do {
        ShowMenu(appName, tasks);
        choice = GetChoice(tasks);
        isQuit = (choice == tasks.size());
        if (!isQuit)
        {
            if (tasks[choice])
            {
                tasks[choice]();
            }
        }
    } while(!isQuit);
}

}


