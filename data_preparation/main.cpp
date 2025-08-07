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
#include "argument.h"
#include "tree_builder.h"

#include <exception>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    // List of valid arguments
    // Columns in Argument constructor: is boolean, name, default value
    std::vector<Argument> args = {Argument(true, "-h", "false"),
                                  Argument(true, "--help", "false"),
                                  Argument(false, "-w", ""),
                                  Argument(false, "--wordlist", ""),
                                  Argument(false, "-t", ""),
                                  Argument(false, "--build-trie", ""),
                                  Argument(false, "-b", ""),
                                  Argument(false, "--build-bktree", "")};

    // Initialize a command line argument parser
    ArgParserEx arg_parser(argc, argv, args);

    try
    {
        // Parse command line arguments
        arg_parser.parse();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n'
                  << "Use \'prepare_data -h\' or \'prepare_data --help\' to display help\n";
        return 1;
    }

    // Display help if '-h' or '--help' arguments are present
    if(arg_parser.getArgumentValue("-h") == "true" ||
       arg_parser.getArgumentValue("--help") == "true")
    {
        std::cerr << "Usage: prepare_data [OPTIONS]\n\n"
                  << "Required parameters:\n"
                  << "  -w, --wordlist\t\tInput file with the list of words\n"
                  << "\t\t\t\t\t\t(always required)\n"
                  << "  -t, --build-trie\t\tOutput file with created Trie\n"
                  << "\t\t\t\t\t\t(required if --build-bktree is not used)\n"
                  << "  -b, --build-bktree\tOutput file with created BK-tree\n"
                  << "\t\t\t\t\t\t(required if --build-trie is not used)\n\n"
                  << "Optional parameters:\n"
                  << "  -h, --help\t\t\tDisplay this usage information\n\n"
                  << "Examples:\n"
                  << "  prepare_data -w wordlist.txt -t trie.dat\n"
                  << "  prepare_data -w wordlist.txt -b bktree.dat\n"
                  << "  prepare_data -w wordlist.txt -t trie.dat -b bktree.dat\n";
        return 0;
    }

    // Get values for '-w' and '--wordlist'
    std::string short_arg_val = arg_parser.getArgumentValue("-w");
    std::string long_arg_val = arg_parser.getArgumentValue("--wordlist");

    // Check if either '-w' or '--wordlist' has value
    if(short_arg_val.empty() && long_arg_val.empty())
    {
        std::cerr << "Error: missing a value for either \'-w\' or \'--wordlist\'\n"
                  << "Use \'prepare_data -h\' or \'prepare_data --help\' to display help\n";
        return 1;
    }

    // Do not allow both '-w' and '--wordlist' options at the same time
    if(!short_arg_val.empty() && !long_arg_val.empty())
    {
        std::cerr << "Error: both \'-w\' and \'--wordlist\' are specified\n"
                  << "Use \'prepare_data -h\' or \'prepare_data --help\' to display help\n";
        return 1;
    }

    std::string value = short_arg_val.empty() ? long_arg_val : short_arg_val;

    TreeBuilder tree_builder;

    try
    {
        // Read a list of words from file into a collection
        tree_builder.readWordlist(value);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    // Get values for '-t' and '--build-trie'
    short_arg_val = arg_parser.getArgumentValue("-t");
    long_arg_val = arg_parser.getArgumentValue("--build-trie");

    // Check if either '-t' or '--build-trie' has value
    if(!short_arg_val.empty() || !long_arg_val.empty())
    {
        // Do not allow both '-t' and '--build-trie' options at the same time
        if(!short_arg_val.empty() && !long_arg_val.empty())
        {
            std::cerr << "Error: both \'-t\' and \'--build-trie\' are specified\n"
                      << "Use \'prepare_data -h\' or \'prepare_data --help\' to display help\n";
            return 1;
        }

        value = short_arg_val.empty() ? long_arg_val : short_arg_val;

        try
        {
            // Build a Trie (prefix tree)
            tree_builder.buildTrie(value);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            return 1;
        }
    }

    // Get values for '-b' and '--build-bktree'
    short_arg_val = arg_parser.getArgumentValue("-b");
    long_arg_val = arg_parser.getArgumentValue("--build-bktree");

    // Check if either '-b' or '--build-bktree' has value
    if(!short_arg_val.empty() || !long_arg_val.empty())
    {
        // Do not allow both '-b' and '--build-bktree' options at the same time
        if(!short_arg_val.empty() && !long_arg_val.empty())
        {
            std::cerr << "Error: both \'-b\' and \'--build-bktree\' are specified\n"
                      << "Use \'prepare_data -h\' or \'prepare_data --help\' to display help\n";
            return 1;
        }

        value = short_arg_val.empty() ? long_arg_val : short_arg_val;

        try
        {
            // Build a BK-tree
            tree_builder.buildBKTree(value);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            return 1;
        }
    }
}
