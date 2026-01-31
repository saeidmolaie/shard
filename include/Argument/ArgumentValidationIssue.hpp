#pragma once

#include <string>

#include "ArgumentValidationIssueSeverity.hpp"

struct ArgumentValidationIssue
{
    private:
        std::string _message;
        ArgumentValidationIssueSeverity _severity;

    public:
        explicit ArgumentValidationIssue(const std::string& message, const ArgumentValidationIssueSeverity& severity)
        {
            _message = message;
            _severity = severity;
        }

    public:
        const std::string& Message() const
        {
            return _message;
        }

        const ArgumentValidationIssueSeverity& Severity() const
        {
            return _severity;
        }
};