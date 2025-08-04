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

#include "word_prob.h"

#include <limits>

/**
 * @brief Default constructor
 *
 */
WordProb::WordProb() : before(), after() {}

/**
 * @brief Check if before collection contains a word
 *
 * @param word A word to look for
 * @return true if a word in before collection exists, false otherwise
 */
bool WordProb::hasBeforeWord(const std::string& word) const
{
    auto it = this->before.find(word);
    return it != this->before.end();
}

/**
 * @brief Check if after collection contains a word
 *
 * @param word A word to look for
 * @return true if a word in after collection exists, false otherwise
 */
bool WordProb::hasAfterWord(const std::string& word) const
{
    auto it = this->after.find(word);
    return it != this->after.end();
}

/**
 * @brief Add a new word to the before collection
 *
 * @param word A word to add
 * @param value A value to assign
 */
void WordProb::addBeforeWord(const std::string& word, std::uint64_t value)
{
    if(!this->hasBeforeWord(word))
    {
        this->before[word] = value;
    }
}

/**
 * @brief Add a new word to the after collection
 *
 * @param word A word to add
 * @param value A value to assign
 */
void WordProb::addAfterWord(const std::string& word, std::uint64_t value)
{
    if(!this->hasAfterWord(word))
    {
        this->after[word] = value;
    }
}

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
std::uint64_t WordProb::getBeforeWordCount(const std::string& word) const
{
    if(!this->hasBeforeWord(word))
    {
        return std::numeric_limits<std::uint64_t>().max();
    }

    return this->before.at(word);
}

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
std::uint64_t WordProb::getAfterWordCount(const std::string& word) const
{
    if(!this->hasAfterWord(word))
    {
        return std::numeric_limits<std::uint64_t>().max();
    }

    return this->after.at(word);
}

/**
 * @brief Increase count of the word in before collection if this word exists
 *
 * @param word A word in the collection
 * @param value A value to add to the count (1 by default)
 */
void WordProb::increaseBeforeWordCount(const std::string& word, std::uint64_t value)
{
    if(this->hasBeforeWord(word))
    {
        this->before[word] += value;
    }
}

/**
 * @brief Increase count of the word in after collection if this word exists
 *
 * @param word A word in the collection
 * @param value A value to add to the count (1 by default)
 */
void WordProb::increaseAfterWordCount(const std::string& word, std::uint64_t value)
{
    if(this->hasAfterWord(word))
    {
        this->after[word] += value;
    }
}
