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

#include "word_context_analyzer.h"
#include "word_prob.h"

#include <limits>
#include <memory>

/**
 * @brief Default constructor
 *
 */
WordContextAnalyzer::WordContextAnalyzer() : context_map() {}

/**
 * @brief Check if context map contains a word
 *
 * @param word A word to look for
 * @return true if context map contains a word, false otherwise
 */
bool WordContextAnalyzer::hasWord(const std::string& word) const
{
    auto it = this->context_map.find(word);
    return it != this->context_map.end();
}

/**
 * @brief Check if before collection in WordProb contains a word
 *
 * @param word A word in context map to look for
 * @param before_word A word in before collection to look for
 * @return true if a word in before collection exists, false otherwise
 */
bool WordContextAnalyzer::hasBeforeWord(const std::string& word,
                                        const std::string& before_word) const
{
    return hasWord(word) && this->context_map.at(word).get()->hasBeforeWord(before_word);
}

/**
 * @brief Check if after collection in WordProb contains a word
 *
 * @param word A word in context map to look for
 * @param after_word A word in after collection to look for
 * @return true if a word in after collection exists, false otherwise
 */
bool WordContextAnalyzer::hasAfterWord(const std::string& word, const std::string& after_word) const
{
    return hasWord(word) && this->context_map.at(word).get()->hasAfterWord(after_word);
}

/**
 * @brief Add a new word to the context map
 *
 * @param word A word to add
 */
void WordContextAnalyzer::addWord(const std::string& word)
{
    if(!this->hasWord(word))
    {
        this->context_map[word] = std::make_unique<WordProb>();
    }
}

/**
 * @brief Add a new word to the before collection
 *
 * @param word A word in the context map
 * @param before_word A word to add to before collection
 * @param value A value to assign
 */
void WordContextAnalyzer::addBeforeWord(const std::string& word, const std::string& before_word,
                                        std::uint64_t value)
{
    this->addWord(word);

    if(!this->hasBeforeWord(word, before_word))
    {
        this->context_map[word].get()->addBeforeWord(before_word, value);
    }
}

/**
 * @brief Add a new word to the after collection
 *
 * @param word A word in the context map
 * @param after_word A word to add to after collection
 * @param value A value to assign
 */
void WordContextAnalyzer::addAfterWord(const std::string& word, const std::string& after_word,
                                       std::uint64_t value)
{
    this->addWord(word);

    if(!this->hasAfterWord(word, after_word))
    {
        this->context_map[word].get()->addAfterWord(after_word, value);
    }
}

/**
 * @brief Get the number of times before_word has appeared before word
 *
 * @param word A word in the context map
 * @param before_word A word in the before collection
 * @return The number of times before_word has appeared before word.
 * If a specified word does not exist in the before collection, the
 * maximum possible value for an unsigned 64-bit integer is returned instead
 */
std::uint64_t WordContextAnalyzer::getBeforeWordCount(const std::string& word,
                                                      const std::string& before_word) const
{
    if(!this->hasWord(word))
    {
        return std::numeric_limits<std::uint64_t>().max();
    }

    return this->context_map.at(word).get()->getBeforeWordCount(before_word);
}

/**
 * @brief Get the number of times after_word has appeared after word
 *
 * @param word A word in the context map
 * @param after_word A word in the after collection
 * @return The number of times after_word has appeared after word.
 * If a specified word does not exist in the after collection, the
 * maximum possible value for an unsigned 64-bit integer is returned instead
 */
std::uint64_t WordContextAnalyzer::getAfterWordCount(const std::string& word,
                                                     const std::string& after_word) const
{
    if(!this->hasWord(word))
    {
        return std::numeric_limits<std::uint64_t>().max();
    }

    return this->context_map.at(word).get()->getAfterWordCount(after_word);
}

/**
 * @brief Increase count of the word in before collection if this word exists
 *
 * @param word A word in the context map
 * @param before_word A word in before collection
 * @param value A value to add to the count (1 by default)
 */
void WordContextAnalyzer::increaseBeforeWordCount(const std::string& word,
                                                  const std::string& before_word,
                                                  std::uint64_t value)
{
    if(this->hasBeforeWord(word, before_word))
    {
        this->context_map[word]->increaseBeforeWordCount(before_word, value);
    }
}

/**
 * @brief Increase count of the word in after collection if this word exists
 *
 * @param word A word in the context map
 * @param after_word A word in after collection
 * @param value A value to add to the count (1 by default)
 */
void WordContextAnalyzer::increaseAfterWordCount(const std::string& word,
                                                 const std::string& after_word, std::uint64_t value)
{
    if(this->hasAfterWord(word, after_word))
    {
        this->context_map[word]->increaseAfterWordCount(after_word, value);
    }
}
