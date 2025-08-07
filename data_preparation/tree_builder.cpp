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

#include "tree_builder.h"

#include "bk_tree.h"
#include "trie.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <random>
#include <stdexcept>
#include <string>

/**
 * @brief Default constructor
 *
 */
TreeBuilder::TreeBuilder() : words() {}

/**
 * @brief Read a list of words from the file
 *
 * @param filepath Path to the file containing a list of words
 */
void TreeBuilder::readWordlist(const std::string& filepath)
{
    std::ifstream file(filepath, std::ios::binary);

    if(!file.is_open() || !file.good())
    {
        throw std::runtime_error("could not open file " + filepath);
    }

    std::string line;
    while(std::getline(file, line))
    {
        line = this->transformString(line);

        if(this->isValidString(line))
        {
            this->words.push_back(line);
        }
    }

    file.close();
}

/**
 * @brief Create and serialize a Trie (prefix tree)
 *
 * @param filepath Path to the output file
 */
void TreeBuilder::buildTrie(const std::string& filepath)
{
    Trie trie;

    for(const std::string& word : this->words)
    {
        trie.insert(word);
    }

    std::ofstream file(filepath, std::ios::binary);

    if(!file.is_open() || !file.good())
    {
        throw std::runtime_error("could not create/open file " + filepath);
    }

    trie.serialize(file);
    file.close();
}

/**
 * @brief Create and serialize a BK-tree
 *
 * @param filepath Path to the output file
 */
void TreeBuilder::buildBKTree(const std::string& filepath)
{
    // Randomly shuffle the words for achieving a better balance in the tree
    std::shuffle(std::begin(this->words), std::end(this->words),
                 std::mt19937{std::random_device{}()});

    BKTree tree;

    for(const std::string& word : this->words)
    {
        tree.insert(word);
    }

    std::ofstream file(filepath, std::ios::binary);

    if(!file.is_open() || !file.good())
    {
        throw std::runtime_error("could not create/open file " + filepath);
    }

    tree.serialize(file);
    file.close();
}

/**
 * @brief Transform the string. Removes newline and carriage return
 * characters, as well as converts letters to lowercase
 *
 * @param s Input string
 * @return Transformed string
 */
std::string TreeBuilder::transformString(const std::string& s) const
{
    std::string result;
    result.reserve(s.size());

    for(char c : s)
    {
        if(c == '\n' || c == '\r') // newline or CR
        {
            continue;
        }
        else if(c >= 'A' && c <= 'Z') // uppercase letters
        {
            // Cast to unsigned char first to avoid issues with tolower
            result += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
        else // other characters
        {
            result += c;
        }
    }

    return result;
}

/**
 * @brief Check if a string only contains English lowercase letters (a-z)
 *
 * @param s String to check
 * @return true if a string only contains English lowercase letters, false otherwise
 */
bool TreeBuilder::isValidString(const std::string& s) const
{
    for(char c : s)
    {
        if(!(c >= 'a' && c <= 'z'))
        {
            return false;
        }
    }

    return true;
}
