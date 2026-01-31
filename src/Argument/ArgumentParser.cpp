#include "Argument/ArgumentParser.hpp"

std::vector<Argument> ArgumentParser::Parse(const int& argc, char* argv[])
{
    std::vector<Argument> arguments;

    if(argc <= 0)
        return arguments;

    arguments.reserve(argc);

    for (size_t i = 0; i < argc; i++)
    {
        std::string token = argv[i];

        if (token.empty() || token[0] != '-')
            continue;

        const size_t name_start = 1;
        const size_t equal_pos = token.find('=');

        const std::string name =
            token.substr(name_start, equal_pos - name_start);

        if (equal_pos != std::string::npos)
        {
            const std::string value = token.substr(equal_pos + 1);
            arguments.emplace_back(name, value);
        }
        else
        {
            arguments.emplace_back(name);
        }
    }

    return arguments;
}