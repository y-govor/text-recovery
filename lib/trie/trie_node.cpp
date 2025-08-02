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

#include "trie_node.h"

#include <cctype>
#include <memory>

/**
 * @brief Default constructor
 *
 */
TrieNode::TrieNode() : is_end_of_word(false), number_of_children(0), children(26) {}

/**
 * @brief Check if this node marks the end of a word
 *
 * @return true if this node is the end of a word, false otherwise
 */
bool TrieNode::isEndOfWord() const
{
    return this->is_end_of_word;
}

/**
 * @brief Set whether this node represents the end of a word
 *
 * @param is_end_of_word whether this node represents the end of a word
 */
void TrieNode::setEndOfWord(bool is_end_of_word)
{
    this->is_end_of_word = is_end_of_word;
}

/**
 * @brief Get the number of children
 *
 * @return size_t The number of children
 */
size_t TrieNode::numberOfChildren()
{
    return this->number_of_children;
}

/**
 * @brief Check whether a child node exists for the given character
 *
 * @param c English character (a-zA-Z)
 * @return true if a child exists, false otherwise
 */
bool TrieNode::hasChild(char c) const
{
    return this->children[std::tolower(c) - 'a'] != nullptr;
}

/**
 * @brief Get the child node associated with the given character
 *
 * @param c English character (a-zA-Z)
 * @return Pointer to the child node if it exists, nullptr if it doesn't
 */
TrieNode* TrieNode::getChild(char c) const
{
    return this->children[std::tolower(c) - 'a'].get();
}

/**
 * @brief Create a new child node for the given character, if it doesn't already exist
 *
 * @param c English character (a-zA-Z)
 */
void TrieNode::createChild(char c)
{
    char ch = std::tolower(c);

    if(!this->hasChild(c))
    {
        this->children[ch - 'a'] = std::make_unique<TrieNode>();
        this->number_of_children++;
    }
}
