#pragma once

#include "ArgumentValidationIssue.hpp"

struct ArgumentValidationResult
{
    private:
        bool _hasErrors = false;
        bool _hasWarnings = false;

    private:
        std::vector<ArgumentValidationIssue> _issues;

    public:
        static ArgumentValidationResult Success()
        {
            return {};
        }

        static ArgumentValidationResult Failure(std::vector<ArgumentValidationIssue>& issues)
        {
            ArgumentValidationResult result;

            result._issues = std::move(issues);
            result.ComputeFlags();

            return result;
        }

    public:
        void Add(const ArgumentValidationIssue& issue)
        {
            if(issue.Severity() == ArgumentValidationIssueSeverity::Error)
            {
                AddError(issue.Message());
            }
            else if (issue.Severity() == ArgumentValidationIssueSeverity::Warning)
            {
                AddWarning(issue.Message());
            }
        }

        void AddError(const std::string& message)
        {
            _hasErrors = true;
            _issues.emplace_back(message, ArgumentValidationIssueSeverity::Error);
        }

        void AddWarning(const std::string& message)
        {
            _hasWarnings = true;
            _issues.emplace_back(message, ArgumentValidationIssueSeverity::Warning);
        }

    public:
        const bool IsSuccess() const
        {
            return !_hasErrors;
        }

        const bool& HasWarnings() const
        {
            return _hasWarnings;
        }

    private:
        void ComputeFlags()
        {
            for (const auto& issue : _issues)
            {
                if (_hasErrors && _hasWarnings)
                    break;

                auto severity = issue.Severity();

                if (severity == ArgumentValidationIssueSeverity::Error)
                    _hasErrors = true;

                else if (severity == ArgumentValidationIssueSeverity::Warning)
                    _hasWarnings = true;
            }
        }
};