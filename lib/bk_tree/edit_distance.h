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

#ifndef EDIT_DISTANCE_H_INCLUDED
#define EDIT_DISTANCE_H_INCLUDED

#include <string>

namespace EditDistance
{
    /**
     * @brief A constant that defines the size of the alphabet.
     * Only lowercase English letters (a-z) and wildcards (*) are allowed
     *
     */
    const unsigned int ALPHABET_SIZE = 27;

    /**
     * @brief Map a character to an array index
     *
     * @param c Character
     * @return Index in the array that corresponds to a given character
     * if the character is valid, otherwise -1
     */
    int charToIndex(char c);

    /**
     * @brief Calculate edit distance between two strings using Damerau–Levenshtein distance
     * <https://en.wikipedia.org/wiki/Damerau–Levenshtein_distance>
     *
     * @param a First string
     * @param b Second string
     * @return Edit distance
     */
    int editDistance(const std::string& a, const std::string& b);
}

#endif // EDIT_DISTANCE_H_INCLUDED
