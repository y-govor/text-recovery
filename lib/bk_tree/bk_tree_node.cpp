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

#include "bk_tree_node.h"
#include "edit_distance.h"

#include <memory>

/**
 * @brief Default constructor
 *
 */
BKTreeNode::BKTreeNode() : word(), children() {}

/**
 * @brief Get the word of the current node
 *
 * @return A word of the current node
 */
std::string BKTreeNode::getWord() const
{
    return this->word;
}

/**
 * @brief Set a word for the current node
 *
 * @param word A word of the current node
 */
void BKTreeNode::setWord(const std::string& word)
{
    this->word = word;
}

/**
 * @brief Check if a node has a child node with the specified edit distance
 *
 * @param distance Edit distance of the child node
 * @return true if a child node with the specified edit distance exists, otherwise false
 */
bool BKTreeNode::hasChild(int distance) const
{
    auto it = this->children.find(distance);
    // If the item does not exist, the iterator will point at the end
    return it != this->children.end();
}

/**
 * @brief Get a child node with the specified edit distance
 *
 * @param distance Edit distance
 * @return A child node with the specified edit distance
 */
BKTreeNode* BKTreeNode::getChild(int distance) const
{
    auto it = this->children.find(distance);
    return (it != this->children.end()) ? it->second.get() : nullptr;
}

/**
 * @brief Add a new child node
 *
 * @param distance Edit distance
 * @param word A word of the node
 */
void BKTreeNode::addChild(int distance, const std::string& word)
{
    if(!this->hasChild(distance))
    {
        this->children[distance] = std::make_unique<BKTreeNode>();
        this->children[distance].get()->setWord(word);
    }
}

/**
 * @brief Insert a word
 *
 * @param word A word to insert
 */
void BKTreeNode::insert(const std::string& word)
{
    BKTreeNode* node = this;

    while(true)
    {
        int distance = EditDistance::editDistance(word, node->getWord());

        if(!node->hasChild(distance))
        {
            node->addChild(distance, word);
            return;
        }

        node = node->getChild(distance);
    }
}

/**
 * @brief Find all words similar to the query within the tolerance value
 *
 * @param query Query
 * @param tolerance Tolerance value (max edit distance)
 * @param results A collection with results to pass
 */
void BKTreeNode::find(const std::string& query, unsigned int tolerance,
                      std::vector<std::string>& results) const
{
    int distance = EditDistance::editDistance(query, this->word);

    if(distance <= tolerance)
    {
        results.push_back(this->word);
    }

    int min_dist = distance - tolerance;
    int max_dist = distance + tolerance;

    for(const auto& it : this->children)
    {
        if(it.first >= min_dist && it.first <= max_dist)
        {
            it.second.get()->find(query, tolerance, results);
        }
    }
}

/**
 * @brief Seerialize current node
 *
 * @param os Output stream
 */
void BKTreeNode::serialize(std::ostream& os) const
{
    // Get the length of the word
    unsigned int word_len = static_cast<unsigned int>(this->word.size());

    // Write the length of the word and the word itself
    os.write(reinterpret_cast<char*>(&word_len), sizeof(word_len));
    os.write(&this->word[0], word_len);

    // Write the number of children the current node has
    unsigned int num_children = static_cast<unsigned int>(this->children.size());
    os.write(reinterpret_cast<char*>(&num_children), sizeof(num_children));

    // Serialize children
    for(const auto& it : children)
    {
        // Write the edit distance of the child node
        unsigned short distance = static_cast<unsigned short>(it.first);
        os.write(reinterpret_cast<char*>(&distance), sizeof(distance));

        // Serialize the child node
        it.second.get()->serialize(os);
    }
}

/**
 * @brief Deserialize current node
 *
 * @param is Input stream
 */
void BKTreeNode::deserialize(std::istream& is)
{
    // Read the length of the word
    unsigned int word_len;
    is.read(reinterpret_cast<char*>(&word_len), sizeof(word_len));

    // Read the word
    this->word.resize(word_len);
    is.read(&this->word[0], word_len);

    // Read the number of child nodes
    unsigned int num_children;
    is.read(reinterpret_cast<char*>(&num_children), sizeof(num_children));

    // Deserialize child nodes
    for(unsigned int i = 0; i < num_children; i++)
    {
        // Read the edit distance of the child node
        unsigned short distance;
        is.read(reinterpret_cast<char*>(&distance), sizeof(distance));

        // Create and deserialize the child node
        this->children[distance] = std::make_unique<BKTreeNode>();
        this->children[distance].get()->deserialize(is);
    }
}
