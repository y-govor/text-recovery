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

#include "arg_parser.h"

#include <cstddef>
#include <limits>

/**
 * @brief Initialize command line arguments parser
 *
 * @param argc Number of command line arguments
 * @param argv List of command line arguments passed to the program
 * @param args List of valid command line arguments
 */
ArgParser::ArgParser(int argc, char* argv[], const std::vector<Argument>& args) :
    ELEMENT_DOES_NOT_EXIST(std::numeric_limits<std::size_t>().max()),
    argv(argv + 1, argv + argc) // Convert an array of C strings (char*) to a string vector
{
}

/**
 * @brief Get the index of the argument
 *
 * @param name Argument name
 * @return Index of the argument
 */
std::size_t ArgParser::getArgumentIndex(const std::string& name) const
{
    for(std::size_t i = 0; i < this->args.size(); i++)
    {
        if(this->args[i].getName() == name)
        {
            return i;
        }
    }

    return ELEMENT_DOES_NOT_EXIST;
}

/**
 * @brief Get the argument value
 *
 * @param name Argument name
 * @return  Value of an argument if it exists, an empty string otherwise
 */
std::string ArgParser::getArgumentValue(const std::string& name) const
{
    std::size_t index = this->getArgumentIndex(name);

    if(index != ELEMENT_DOES_NOT_EXIST)
    {
        return this->args[index].getValue();
    }

    return "";
}
