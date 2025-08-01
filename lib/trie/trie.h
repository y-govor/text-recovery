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

#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include "trie_node.h"

#include <memory>
#include <string>
#include <vector>

/**
 * @brief Class that represents a Trie data structure
 *
 */
class Trie
{
private:
    /**
     * @brief Root node of the Trie
     *
     */
    std::unique_ptr<TrieNode> root;

public:
    /**
     * @brief Default constructor
     *
     */
    Trie();

    /**
     * @brief Insert a word into the Trie
     *
     * @param word A word to insert
     */
    void insert(const std::string& word);
    /**
     * @brief Search a word in the Trie
     *
     * @param word A word to search for
     * @return true if a word exists in the Trie, false otherwise
     */
    bool search(const std::string& word) const;
    /**
     * @brief Check if Trie contains a word that starts with a given prefix
     *
     * @param prefix Prefix
     * @return true if Trie contains a word that starts with a given prefix, false otherwise
     */
    bool startsWith(const std::string& prefix) const;

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
    std::vector<int> getValidEndings(const std::string& text, int startPos = 0);

    /**
     * @brief Check if any word in the Trie matches the pattern
     *
     * @param pattern Pattern to check
     * @return true if any word in the Trie matches the pattern, false otherwise
     */
    bool matchPattern(const std::string& pattern);
    /**
     * @brief Check if any word in the Trie matches the pattern
     *
     * @param pattern Pattern to check
     * @param index Starting index in the pattern
     * @param node A Trie node to start from
     * @return true if any word in the Trie matches the pattern, false otherwise
     */
    bool matchPattern(const std::string& pattern, int index, TrieNode* node);

    /**
     * @brief Collect all words in Trie that match a given pattern
     *
     * @param pattern Pattern that words should match
     * @return A list of words that match a given pattern
     */
    std::vector<std::string> collectMatches(const std::string& pattern);
    /**
     * @brief Collect all words in Trie that match a given pattern
     *
     * @param pattern Pattern that words should match
     * @param index Starting index in the pattern
     * @param node A Trie node to start from
     * @param current Part of a word that has been built
     * @param results A list of words that match a given pattern
     */
    void collectMatches(const std::string& pattern, int index, TrieNode* node,
                        const std::string& current, std::vector<std::string>& results);

    /**
     * @brief Print all words in the Trie starting from a root node
     *
     */
    void print() const;
    /**
     * @brief Print all words in the Trie starting from a given node
     *
     * @param node A Trie node to start from
     * @param prefix Prefix of a word
     */
    void print(TrieNode* node, const std::string& prefix) const;
};

#endif // TRIE_H_INCLUDED
