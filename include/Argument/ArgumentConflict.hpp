#pragma once

#include <string>
#include <vector>

#include "Arguments.hpp"
#include "ArgumentValidationIssueSeverity.hpp"

struct ArgumentConflict
{
    private:
        const std::string _name;
        const std::string _message;
        const ArgumentValidationIssueSeverity _severity;

    public:
        explicit ArgumentConflict(
            const std::string& name,
            const std::string& message,
            const ArgumentValidationIssueSeverity& severity) : _name(name), _message(message), _severity(severity)
        {
        }

        const std::string& Name() const
        {
            return _name;
        }

        const std::string& Message() const
        {
            return _message;
        }

        const ArgumentValidationIssueSeverity& Severity() const
        {
            return _severity;
        }

    public:
        static std::vector<ArgumentConflict> ResolveConflicts(const std::string& argumentName)
        {
            std::vector<ArgumentConflict> conflicts;
            return conflicts;
        };
};