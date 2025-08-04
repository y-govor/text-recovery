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

#ifndef BK_TREE_NODE_H_INCLUDED
#define BK_TREE_NODE_H_INCLUDED

#include <istream>
#include <memory>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * @brief Class that represents a node in a BK-tree
 *
 */
class BKTreeNode
{
private:
    /**
     * @brief A word of the current node
     *
     */
    std::string word;
    /**
     * @brief Children of the current node. The collection stores an edit distance between
     * the word of this node and the child node, as well as a pointer to that node
     *
     */
    std::unordered_map<int, std::unique_ptr<BKTreeNode>> children;

public:
    /**
     * @brief Default constructor
     *
     */
    BKTreeNode();

    /**
     * @brief Get the word of the current node
     *
     * @return A word of the current node
     */
    std::string getWord() const;
    /**
     * @brief Set a word for the current node
     *
     * @param word A word of the current node
     */
    void setWord(const std::string& word);

    /**
     * @brief Check if a node has a child node with the specified edit distance
     *
     * @param distance Edit distance of the child node
     * @return true if a child node with the specified edit distance exists, otherwise false
     */
    bool hasChild(int distance) const;

    /**
     * @brief Get a child node with the specified edit distance
     *
     * @param distance Edit distance
     * @return A child node with the specified edit distance
     */
    BKTreeNode* getChild(int distance) const;

    /**
     * @brief Add a new child node
     *
     * @param distance Edit distance
     * @param word A word of the node
     */
    void addChild(int distance, const std::string& word);

    /**
     * @brief Insert a word
     *
     * @param word A word to insert
     */
    void insert(const std::string& word);

    /**
     * @brief Find all words similar to the query within the tolerance value
     *
     * @param query Query
     * @param tolerance Tolerance value (max edit distance)
     * @param results A collection with results to pass
     */
    void find(const std::string& query, unsigned int tolerance,
              std::vector<std::string>& results) const;

    /**
     * @brief Seerialize current node
     *
     * @param os Output stream
     */
    void serialize(std::ostream& os) const;

    /**
     * @brief Deserialize current node
     *
     * @param is Input stream
     */
    void deserialize(std::istream& is);
};

#endif // BK_TREE_NODE_H_INCLUDED
