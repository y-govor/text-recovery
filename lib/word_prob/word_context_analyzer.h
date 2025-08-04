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

#ifndef WORD_CONTEXT_ANALYZER_H_INCLUDED
#define WORD_CONTEXT_ANALYZER_H_INCLUDED

#include "word_prob.h"

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>

/**
 * @brief A class for tracking how often each word appears with other words
 * before and after it. It it intended to be a base class that provides
 * functionality for managing items in the context_map
 *
 */
class WordContextAnalyzer
{
protected:
    /**
     * @brief A map that stores words, as well as a pointer to the WordProb object
     * that stores before and after maps for keeping track of all words and how often
     * they appear before and after the word represented by the context_map's key
     *
     */
    std::unordered_map<std::string, std::unique_ptr<WordProb>> context_map;

public:
    /**
     * @brief Default constructor
     *
     */
    WordContextAnalyzer();

    /**
     * @brief Check if context map contains a word
     *
     * @param word A word to look for
     * @return true if context map contains a word, false otherwise
     */
    bool hasWord(const std::string& word) const;
    /**
     * @brief Check if before collection in WordProb contains a word
     *
     * @param word A word in context map to look for
     * @param before_word A word in before collection to look for
     * @return true if a word in before collection exists, false otherwise
     */
    bool hasBeforeWord(const std::string& word, const std::string& before_word) const;
    /**
     * @brief Check if after collection in WordProb contains a word
     *
     * @param word A word in context map to look for
     * @param after_word A word in after collection to look for
     * @return true if a word in after collection exists, false otherwise
     */
    bool hasAfterWord(const std::string& word, const std::string& after_word) const;

    /**
     * @brief Add a new word to the context map
     *
     * @param word A word to add
     */
    void addWord(const std::string& word);
    /**
     * @brief Add a new word to the before collection
     *
     * @param word A word in the context map
     * @param before_word A word to add to before collection
     * @param value A value to assign
     */
    void addBeforeWord(const std::string& word, const std::string& before_word,
                       std::uint64_t value = 1);
    /**
     * @brief Add a new word to the after collection
     *
     * @param word A word in the context map
     * @param after_word A word to add to after collection
     * @param value A value to assign
     */
    void addAfterWord(const std::string& word, const std::string& after_word,
                      std::uint64_t value = 1);

    /**
     * @brief Get the number of times before_word has appeared before word
     *
     * @param word A word in the context map
     * @param before_word A word in the before collection
     * @return The number of times before_word has appeared before word.
     * If a specified word does not exist in the before collection, the
     * maximum possible value for an unsigned 64-bit integer is returned instead
     */
    std::uint64_t getBeforeWordCount(const std::string& word, const std::string& before_word) const;
    /**
     * @brief Get the number of times after_word has appeared after word
     *
     * @param word A word in the context map
     * @param after_word A word in the after collection
     * @return The number of times after_word has appeared after word.
     * If a specified word does not exist in the after collection, the
     * maximum possible value for an unsigned 64-bit integer is returned instead
     */
    std::uint64_t getAfterWordCount(const std::string& word, const std::string& after_word) const;

    /**
     * @brief Increase count of the word in before collection if this word exists
     *
     * @param word A word in the context map
     * @param before_word A word in before collection
     * @param value A value to add to the count (1 by default)
     */
    void increaseBeforeWordCount(const std::string& word, const std::string& before_word,
                                 std::uint64_t value = 1);
    /**
     * @brief Increase count of the word in after collection if this word exists
     *
     * @param word A word in the context map
     * @param after_word A word in after collection
     * @param value A value to add to the count (1 by default)
     */
    void increaseAfterWordCount(const std::string& word, const std::string& after_word,
                                std::uint64_t value = 1);
};

#endif // WORD_CONTEXT_ANALYZER_H_INCLUDED
