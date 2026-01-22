#pragma once

#include <string>
#include <optional>

struct Argument
{
    private:
        std::string _name;
        std::optional<std::string> _value;

    public:
        explicit Argument(const std::string& name)
        {
            _name = std::move(name);
        }

        explicit Argument(const std::string& name, const std::string& value)
        {
            _name = std::move(name);
            _value = std::move(value);
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
};