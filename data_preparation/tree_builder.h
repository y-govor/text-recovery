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

#ifndef TREE_BUILDER_H_INCLUDED
#define TREE_BUILDER_H_INCLUDED

#include <string>
#include <vector>

/**
 * @brief Class for reading a list of words from a file and creating
 * tree data structures. Supports Trie (prefix tree) and a BK-tree
 *
 */
class TreeBuilder
{
private:
    /**
     * @brief A list of words
     *
     */
    std::vector<std::string> words;

public:
    /**
     * @brief Default constructor
     *
     */
    TreeBuilder();

    /**
     * @brief Read a list of words from the file
     *
     * @param filepath Path to the file containing a list of words
     */
    void readWordlist(const std::string& filepath);

    /**
     * @brief Create and serialize a Trie (prefix tree)
     *
     * @param filepath Path to the output file
     */
    void buildTrie(const std::string& filepath);

    /**
     * @brief Create and serialize a BK-tree
     *
     * @param filepath Path to the output file
     */
    void buildBKTree(const std::string& filepath);

private:
    /**
     * @brief Transform the string. Removes newline and carriage return
     * characters, as well as converts letters to lowercase
     *
     * @param s Input string
     * @return Transformed string
     */
    std::string transformString(const std::string& s) const;
    /**
     * @brief Check if a string only contains English lowercase letters (a-z)
     *
     * @param s String to check
     * @return true if a string only contains English lowercase letters, false otherwise
     */
    bool isValidString(const std::string& s) const;
};

#endif // TREE_BUILDER_H_INCLUDED
