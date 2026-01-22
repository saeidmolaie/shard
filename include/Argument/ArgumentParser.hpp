#pragma once

#include <vector>

#include "Argument.hpp"

class ArgumentParser
{
    public:
        ArgumentParser() = delete;
        ArgumentParser(const ArgumentParser&) = delete;
        ArgumentParser(ArgumentParser&&) = delete;
        ArgumentParser& operator=(const ArgumentParser&) = delete;
        ArgumentParser& operator=(ArgumentParser&&) = delete;

    public:
        static std::vector<Argument> Parse(const int& argc, char* argv[]);
};