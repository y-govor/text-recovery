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

#ifndef ARGUMENT_H_INCLUDED
#define ARGUMENT_H_INCLUDED

#include <string>

/**
 * @brief Class that represents a command line argument
 *
 */
class Argument
{
private:
    /**
     * @brief Whether the argument is boolean
     *
     */
    bool is_bool;
    /**
     * @brief Argument name
     *
     */
    std::string name;
    /**
     * @brief Argument value
     *
     */
    std::string value;

public:
    /**
     * @brief Create a new argument
     *
     * @param is_bool Whether the argument is boolean
     * @param name Argument name
     * @param value Argument value
     */
    Argument(bool is_bool, const std::string& name, const std::string& value);

    /**
     * @brief Get whether the argument is boolean
     *
     * @return true if the argument is boolean, false otherwise
     */
    bool isBool() const;

    /**
     * @brief Get argument name
     *
     * @return Argument name
     */
    std::string getName() const;

    /**
     * @brief Get argument value
     *
     * @return Argument value
     */
    std::string getValue() const;
};

#endif // ARGUMENT_H_INCLUDED
