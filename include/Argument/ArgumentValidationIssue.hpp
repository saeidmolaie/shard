#pragma once

#include <string>

struct ArgumentValidationIssue
{
    enum class Severity
    {
        Error,
        Warning
    };

    private:
        Severity _severity;
        std::string _message;

    public:
        explicit ArgumentValidationIssue(const Severity& severity, const std::string& message)
        {
            _severity = std::move(severity);
            _message = std::move(message);
        }

    public:
        const Severity& Severity() const
        {
            return _severity;
        }

        const std::string& Message() const
        {
            return _message;
        }
};