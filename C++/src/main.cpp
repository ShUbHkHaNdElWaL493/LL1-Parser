/*
    Shubh Khandelwal
*/

#include <iostream>
#include <parse/parse.hpp>

int main(int argc, char **argv)
{

    if (argc != 2)
    {

        std::cerr << "Usage: ./${EXECUTABLE_FILE} ${RULES_FILE}.txt" << std::endl;
        return 1;

    } else
    {

        std::ifstream rules(argv[1]);

        if (!rules.is_open())
        {
            std::cerr << "Error: Rules file could not be opened." << std::endl;
            return 1;
        }

        LL1Parser parser(rules);
        rules.close();

        std::string line;
        std::cout << "Enter the string to be parsed." << std::endl;
        std::cin >> line;

        if (parser.parse(line))
        {
            std::cout << "The string \"" << line << "\" can be parsed by the parser." << std::endl;
        } else
        {
            std::cout << "The string \"" << line << "\" cannot be parsed by the parser." << std::endl;
        }

        return 0;

    }

}