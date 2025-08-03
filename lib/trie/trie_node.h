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

#ifndef TRIE_NODE_H_INCLUDED
#define TRIE_NODE_H_INCLUDED

#include <cstddef>
#include <memory>
#include <vector>

/**
 * @brief Class that represents a single node in a Trie
 *
 */
class TrieNode
{
private:
    /**
     * @brief Flag to denote the end of a word in a path of the Trie
     *
     */
    bool is_end_of_word;
    /**
     * @brief Number of existing children (elements that are not nullptr)
     *
     */
    size_t number_of_children;
    /**
     * @brief Children of the node
     *
     */
    std::vector<std::unique_ptr<TrieNode>> children;

public:
    /**
     * @brief Default constructor
     *
     */
    TrieNode();

    /**
     * @brief Check if this node marks the end of a word
     *
     * @return true if this node is the end of a word, false otherwise
     */
    bool isEndOfWord() const;
    /**
     * @brief Set whether this node represents the end of a word
     *
     * @param is_end_of_word whether this node represents the end of a word
     */
    void setEndOfWord(bool is_end_of_word);

    /**
     * @brief Get the number of children
     *
     * @return size_t The number of children
     */
    size_t numberOfChildren() const;

    /**
     * @brief Check whether a child node exists for the given character
     *
     * @param c English character (a-zA-Z)
     * @return true if a child exists, false otherwise
     */
    bool hasChild(char c) const;
    /**
     * @brief Get the child node associated with the given character
     *
     * @param c English character (a-zA-Z)
     * @return Pointer to the child node if it exists, nullptr if it doesn't
     */
    TrieNode* getChild(char c) const;
    /**
     * @brief Create a new child node for the given character, if it doesn't already exist
     *
     * @param c English character (a-zA-Z)
     */
    void createChild(char c);
};

#endif // TRIE_NODE_H_INCLUDED
