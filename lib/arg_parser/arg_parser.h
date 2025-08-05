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

#ifndef ARG_PARSER_H_INCLUDED
#define ARG_PARSER_H_INCLUDED

#include "argument.h"

#include <cstddef>
#include <string>
#include <vector>

/**
 * @brief A base class for parsing command line arguments.
 * Does not contain parsing logic
 *
 */
class ArgParser
{
protected:
    /**
     * @brief A constant that defines a code of non existing element.
     * Equal to the maximum possible value for an unsigned 64-bit integer
     *
     */
    const std::size_t ELEMENT_DOES_NOT_EXIST;
    /**
     * @brief Command line arguments passed to the program
     *
     */
    std::vector<std::string> argv;
    /**
     * @brief List of valid command line arguments
     *
     */
    std::vector<Argument> args;

public:
    /**
     * @brief Initialize command line arguments parser
     *
     * @param argc Number of command line arguments
     * @param argv List of command line arguments passed to the program
     * @param args List of valid command line arguments
     */
    ArgParser(int argc, char* argv[], const std::vector<Argument>& args);

    /**
     * @brief Get the argument value
     *
     * @param name Argument name
     * @return  Value of an argument if it exists, an empty string otherwise
     */
    std::string getArgumentValue(const std::string& name) const;

    /**
     * @brief A virtual method for parsing command line arguments.
     * A child class needs to define the parsing logic
     *
     */
    virtual void parse();

private:
    /**
     * @brief Get the index of the argument
     *
     * @param name Argument name
     * @return Index of the argument
     */
    std::size_t getArgumentIndex(const std::string& name) const;
};

#endif // ARG_PARSER_H_INCLUDED
