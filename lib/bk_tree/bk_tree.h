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

#ifndef BK_TREE_H_INCLUDED
#define BK_TREE_H_INCLUDED

#include "bk_tree_node.h"

#include <memory>
#include <string>
#include <vector>

class BKTree
{
private:
    /**
     * @brief Root node
     *
     */
    std::unique_ptr<BKTreeNode> root;

public:
    /**
     * @brief Default constructor
     *
     */
    BKTree();

    /**
     * @brief Insert a word into a tree
     *
     * @param word A word to insert
     */
    void insert(const std::string& word);

    /**
     * @brief Find all words similar to the query within the tolerance value
     *
     * @param query Query
     * @param tolerance Tolerance value (max edit distance)
     * @return A list of matching words
     */
    std::vector<std::string> find(const std::string& query, unsigned int tolerance = 2) const;
};

#endif // BK_TREE_H_INCLUDED
