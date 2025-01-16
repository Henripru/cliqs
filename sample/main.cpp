#include "cliqs.hpp"

#include <iostream>

int main()
{
    std::vector<cliqs::Task> tasks = {
        {"Task1", [](){std::cout << "Doing task 1\n";}}
    };

    cliqs::Run("sampleApp", tasks);

    return 0;
}