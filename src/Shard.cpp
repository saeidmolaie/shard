#include "Argument/ArgumentParser.hpp"
#include "Argument/ArgumentValidator.hpp"

int main(int argc, char* argv[])
{
    std::vector<Argument> arguments = ArgumentParser::Parse(argc, argv);
    ArgumentValidationResult argumentsValidationResult = ArgumentValidator::Validate(arguments);

    if(!argumentsValidationResult.IsSuccess())
    {
        return EXIT_FAILURE;
    }

    if(argumentsValidationResult.HasWarnings())
    {
    }

    return EXIT_SUCCESS;
}