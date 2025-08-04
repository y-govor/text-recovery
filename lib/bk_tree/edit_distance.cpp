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

#include "edit_distance.h"

#include <algorithm>
#include <vector>

/**
 * @brief Map a character to an array index
 *
 * @param c Character
 * @return Index in the array that corresponds to a given character
 * if the character is valid, otherwise -1
 */
int EditDistance::charToIndex(char c)
{
    if(c >= 'a' && c <= 'z') // lowercase letters
    {
        return c - 'a';
    }
    else if(c == '*') // wildcard
    {
        return ALPHABET_SIZE - 1;
    }

    // Invalid character
    return -1;
}

/**
 * @brief Calculate edit distance between two strings using Damerau–Levenshtein distance
 * <https://en.wikipedia.org/wiki/Damerau–Levenshtein_distance>
 *
 * @param a First string
 * @param b Second string
 * @return Edit distance
 */
int EditDistance::editDistance(const std::string& a, const std::string& b)
{
    size_t len_a = a.length();
    size_t len_b = b.length();
    size_t maxdist = len_a + len_b;

    // da[i] is the last row in the edit matrix d where character i appeared in string a
    std::vector<int> da(ALPHABET_SIZE, 0);

    // Edit distance matrix. d[i][j] is the distance between the first i characters
    // of string a and the first j characters of string b
    std::vector<std::vector<int>> d(len_a + 2, std::vector<int>(len_b + 2));

    d[0][0] = maxdist;

    for(int i = 1; i <= len_a + 1; i++)
    {
        d[i][0] = maxdist;
        d[i][1] = i - 1;
    }

    for(int j = 1; j <= len_b + 1; j++)
    {
        d[0][j] = maxdist;
        d[1][j] = j - 1;
    }

    for(int i = 1; i <= len_a; i++)
    {
        int db = 0;

        for(int j = 1; j <= len_b; j++)
        {
            int k = da[charToIndex(b[j - 1])];
            int l = db;

            int cost;
            if((a[i - 1] == b[j - 1]) || (a[i - 1] == '*') || (b[j - 1] == '*'))
            {
                cost = 0;
                db = j;
            }
            else
            {
                cost = 1;
            }

            d[i + 1][j + 1] = std::min({
                d[i][j] + cost, // substitution
                d[i + 1][j] + 1, // insertion
                d[i][j + 1] + 1, // deletion
                d[k][l] + (i - k - 1) + 1 + (j - l - 1) // transposition
            });
        }

        da[charToIndex(a[i - 1])] = i;
    }

    return d[len_a + 1][len_b + 1];
}
