#pragma once

#include <vector>

#include "Argument/Argument.hpp"
#include "Argument/ArgumentValidationResult.hpp"

class ArgumentValidator
{
     public:
        ArgumentValidator() = delete;
        ArgumentValidator(const ArgumentValidator&) = delete;
        ArgumentValidator(ArgumentValidator&&) = delete;
        ArgumentValidator& operator=(const ArgumentValidator&) = delete;
        ArgumentValidator& operator=(ArgumentValidator&&) = delete;

    public:
        static ArgumentValidationResult Validate(const std::vector<Argument>& arguments);
};