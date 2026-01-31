#pragma once

#include <vector>
#include <string>
#include <optional>

#include "Arguments.hpp"
#include "ArgumentConflict.hpp"
#include "ArgumentValidationIssue.hpp"

struct Argument
{
    private:
        const std::string _name;
        std::optional<std::string> _value;
        const bool _isValidName;

    private:
        std::vector<ArgumentConflict> _conflicts;

    public:
        explicit Argument(const std::string& name) : _name(name), _isValidName(IsValidName(name))
        {
            _conflicts = ArgumentConflict::ResolveConflicts(name);
        }

        explicit Argument(const std::string& name, const std::string& value) : Argument(name)
        {
            _value = value;
        }

    public:
        const std::string& Name() const
        {
            return _name;
        }

        const std::string* Value() const
        {
            return _value ? &_value.value() : nullptr;
        }

        bool HasValue() const
        {
            return _value.has_value();
        }

        bool IsValid() const
        {
            return _isValidName;
        }

        bool IsCompatibleWith(const Argument& argument, std::optional<ArgumentValidationIssue>& issue) const
        {
            if(_conflicts.empty())
                return true;

            for (size_t i = 0; i < _conflicts.size(); i++)
            {
                const ArgumentConflict& conflict = _conflicts.at(i);

                if(argument.Name() == conflict.Name())
                {
                    issue.emplace(conflict.Message(), conflict.Severity());
                    return false;
                }
            }

            return true;
        }

    private:
        bool IsValidName(const std::string& name)
        {
            for (int i = 0; i < ARGUMENTS_SIZE; i++)
            {
                if (_name == ARGUMENTS[i])
                    return true;
            }

            return false;
        }
};