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

#ifndef ARG_PARSER_EX_H_INCLUDED
#define ARG_PARSER_EX_H_INCLUDED

#include "arg_parser.h"
#include "argument.h"

#include <vector>

/**
 * @brief A class for parsing command line arguments.
 * An extension of ArgParser
 *
 */
class ArgParserEx : public ArgParser
{
public:
    /**
     * @brief Initialize command line arguments parser
     *
     * @param argc Number of command line arguments
     * @param argv List of command line arguments passed to the program
     * @param args List of valid command line arguments
     */
    ArgParserEx(int argc, char* argv[], const std::vector<Argument>& args);

    /**
     * @brief Parse command line arguments
     *
     */
    void parse() override;
};

#endif // ARG_PARSER_EX_H_INCLUDED
