/*
    Text Recovery
    A C++ program for restoring damaged text
    Copyright (C) 2025 Yurii Govor

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "arg_parser_ex.h"
#include "arg_parser.h"

#include <cstddef>
#include <stdexcept>
#include <string>

/**
 * @brief Initialize command line arguments parser
 *
 * @param argc Number of command line arguments
 * @param argv List of command line arguments passed to the program
 * @param args List of valid command line arguments
 */
ArgParserEx::ArgParserEx(int argc, char* argv[], const std::vector<Argument>& args) :
    ArgParser(argc, argv, args)
{
}

/**
 * @brief Parse command line arguments
 *
 */
void ArgParserEx::parse()
{
    const std::size_t count = argv.size();

    // Check if the first argument is either '-h' or '--help'
    if(count > 0 && (argv[0] == "-h" || argv[0] == "--help"))
    {
        args[getArgumentIndex(argv[0])].setValue("true");
        return; // Ignore other arguments and quit
    }

    // Program requires at least two non-boolean arguments and their values
    // if neither '-h' nor '--help' is the first argument
    if(count < 4)
    {
        throw std::invalid_argument("missing required arguments");
    }

    // Check all arguments
    for(std::size_t i = 0; i < count; i++)
    {
        std::size_t index = getArgumentIndex(argv[i]);

        if(index == ELEMENT_DOES_NOT_EXIST) // String did not match argument name
        {
            throw std::invalid_argument("invalid arguments");
        }

        if(args[index].isBool()) // Boolean argument
        {
            args[index].setValue("true");
        }
        else // Non-boolean argument
        {
            // Check the next argument contains value

            if((i + 1 >= count) || getArgumentIndex(argv[i + 1]) != ELEMENT_DOES_NOT_EXIST)
            {
                throw std::invalid_argument("invalid arguments");
            }

            args[index].setValue(argv[i + 1]);
            i++; // Skip the next argument
        }
    }
}
