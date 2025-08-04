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

#ifndef WORD_PROB_H_INCLUDED
#define WORD_PROB_H_INCLUDED

#include <cstdint>
#include <string>
#include <unordered_map>

/**
 * @brief Data structure for determining the likelihood of words occuring
 * before or after a given word. An object of this class will represent
 * a specific word, while before and after collections represent a list of
 * words and how often they appear before and after this word respectively.
 *
 */
class WordProb
{
private:
    /**
     * @brief A collection that represents a word and the
     * amount of times it appeared before a given word
     *
     */
    std::unordered_map<std::string, std::uint64_t> before;
    /**
     * @brief A collection that represents a word and the
     * amount of times it appeared after a given word
     *
     */
    std::unordered_map<std::string, std::uint64_t> after;

public:
    /**
     * @brief Default constructor
     *
     */
    WordProb();

    /**
     * @brief Check if before collection contains a word
     *
     * @param word A word to look for
     * @return true if a word in before collection exists, false otherwise
     */
    bool hasBeforeWord(const std::string& word) const;
    /**
     * @brief Check if after collection contains a word
     *
     * @param word A word to look for
     * @return true if a word in after collection exists, false otherwise
     */
    bool hasAfterWord(const std::string& word) const;

    /**
     * @brief Add a new word to the before collection
     *
     * @param word A word to add
     * @param value A value to assign
     */
    void addBeforeWord(const std::string& word, std::uint64_t value = 1);
    /**
     * @brief Add a new word to the after collection
     *
     * @param word A word to add
     * @param value A value to assign
     */
    void addAfterWord(const std::string& word, std::uint64_t value = 1);

    /**
     * @brief Get the count for a given word in the before collection
     * (the number of times the word has appeared before a word
     * represented by an object of this class)
     *
     * @param word A word
     * @return The number of times the word has appeared before a word
     * represented by an object of this class. If a specified word does
     * not exist in the before collection, the maximum possible value
     * for an unsigned 64-bit integer is returned instead
     */
    std::uint64_t getBeforeWordCount(const std::string& word) const;
    /**
     * @brief Get the count for a given word in the after collection
     * (the number of times the word has appeared after a word
     * represented by an object of this class)
     *
     * @param word A word
     * @return The number of times the word has appeared after a word
     * represented by an object of this class. If a specified word does
     * not exist in the after collection, the maximum possible value
     * for an unsigned 64-bit integer is returned instead
     */
    std::uint64_t getAfterWordCount(const std::string& word) const;

    /**
     * @brief Increase count of the word in before collection if this word exists
     *
     * @param word A word in the collection
     * @param value A value to add to the count (1 by default)
     */
    void increaseBeforeWordCount(const std::string& word, std::uint64_t value = 1);
    /**
     * @brief Increase count of the word in after collection if this word exists
     *
     * @param word A word in the collection
     * @param value A value to add to the count (1 by default)
     */
    void increaseAfterWordCount(const std::string& word, std::uint64_t value = 1);
};

#endif // WORD_PROB_H_INCLUDED
