#include "Argument/ArgumentValidator.hpp"

ArgumentValidationResult ArgumentValidator::Validate(const std::vector<Argument>& arguments)
{
    ArgumentValidationResult result = ArgumentValidationResult::Success();

    if(arguments.empty())
    {
        result.AddError("At least one argument is required.");
        return result;
    }

    for (size_t i = 0; i < arguments.size(); i++)
    {
        const Argument& argument = arguments.at(i);

        if(!argument.IsValid())
        {
            result.AddError(argument.Name() + " is an invalid argument.");
            continue;
        }

        for (size_t j = (i + 1); j < arguments.size(); j++)
        {
            std::optional<ArgumentValidationIssue> issue;
            const Argument& nextArgument = arguments.at(j);

            if(argument.IsCompatibleWith(nextArgument, issue))
                continue;

            if(!issue.has_value())
            {
                result.AddError(
                    argument.Name() + " is incompatible with " +
                    nextArgument.Name() + ", but no detailed validation issue was provided.");

                continue;
            }

            result.Add(issue.value());
        }
    }

    return result;
}