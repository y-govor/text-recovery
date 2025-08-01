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

#include "trie.h"
#include "trie_node.h"

#include <iostream>
#include <memory>

/**
 * @brief Default constructor
 *
 */
Trie::Trie() : root(std::make_unique<TrieNode>()) {}

/**
 * @brief Insert a word into the Trie
 *
 * @param word A word to insert
 */
void Trie::insert(const std::string& word)
{
    TrieNode* node = this->root.get();

    for(char c : word)
    {
        if(!node->hasChild(c))
        {
            node->createChild(c);
        }

        node = node->getChild(c);
    }

    node->setEndOfWord(true);
}

/**
 * @brief Search a word in the Trie
 *
 * @param word A word to search for
 * @return true if a word exists in the Trie, false otherwise
 */
bool Trie::search(const std::string& word) const
{
    TrieNode* node = this->root.get();

    for(char c : word)
    {
        if(!node->hasChild(c))
        {
            return false;
        }

        node = node->getChild(c);
    }

    return node->isEndOfWord();
}

/**
 * @brief Check if Trie contains a word that starts with a given prefix
 *
 * @param prefix Prefix
 * @return true if Trie contains a word that starts with a given prefix, false otherwise
 */
bool Trie::startsWith(const std::string& prefix) const
{
    TrieNode* node = this->root.get();

    for(char c : prefix)
    {
        if(!node->hasChild(c))
        {
            return false;
        }

        node = node->getChild(c);
    }

    return true;
}

/**
 * @brief Get a list of indices of all possible word endings. For example:
 * If given the text "themanran", the Trie contains words "the" and "them",
 * and the starting position is 0, the list will contain indices 3 and 4,
 * as the text can be split into either "the" or "them" from the beginning
 *
 * @param text Text that contains multiple words with spaces removed
 * @param startPos Starting position (default is 0)
 * @return A list of indices where a word might end
 */
std::vector<int> Trie::getValidEndings(const std::string& text, int startPos)
{
    // A list of valid endings
    std::vector<int> valid_endings;

    TrieNode* node = this->root.get();

    for(int i = startPos; i < text.length(); i++)
    {
        if(!node->hasChild(text[i]))
        {
            break;
        }

        node = node->getChild(text[i]);

        if(node->isEndOfWord())
        {
            valid_endings.push_back(i + 1);
        }
    }

    return valid_endings;
}

/**
 * @brief Print all words in the Trie starting from a root node
 *
 */
void Trie::print() const
{
    this->print(this->root.get(), "");
}

/**
 * @brief Print all words in the Trie starting from a given node
 *
 * @param node A Trie node to start from
 * @param prefix Prefix of a word
 */
void Trie::print(TrieNode* node, const std::string& prefix) const
{
    if(node->isEndOfWord())
    {
        std::cout << prefix << '\n';
    }

    for(char c = 'a'; c <= 'z'; c++)
    {
        if(node->hasChild(c))
        {
            this->print(node->getChild(c), prefix + c);
        }
    }
}
