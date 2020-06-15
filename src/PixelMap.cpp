//
// Created by Lukasz on 04.06.2020.
//

#include <iostream>
#include "PixelMap.h"


PixelMap::PixelMap(int size, double scale) :
        _pixels(size * size * 4),
        _size(size),
        _scale(scale) {
    std::fill(_pixels.begin(), _pixels.end(), 0);
    _texture.create(size, size);
    _sprite.setScale(_scale, _scale);

}

void PixelMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    _texture.update(_pixels.data());
    _sprite.setTexture(_texture);
    target.draw(_sprite, states);
}

/**
 * @brief Set given pixel density (amount of dark "dye")
 * @param x x coord of fluid
 * @param y y coord of fluid
 * @param density density of "dye" at given point
 */
void PixelMap::SetPixel(int x, int y, int density) {
    _pixels[4 * (x + y * _size) + 3] = std::min(255, density);
}
