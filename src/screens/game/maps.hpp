/*
** EPITECH PROJECT, 2021
** G-JAM-001-PAR-0-3-jam-axel.karcher
** File description:
** Maps
*/

#ifndef MAPS_HPP_
#define MAPS_HPP_

#include <memory>
#include <SFML/Graphics.hpp>

#include "Block.hpp"

struct map_s {
    std::vector<std::shared_ptr<Block>> blocks;
    sf::Text hiddenText;
    std::string hiddenChar;
};

#endif /* !MAPS_HPP_ */
