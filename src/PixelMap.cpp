//
// Created by Lukasz on 04.06.2020.
//

#include <iostream>
#include "PixelMap.h"
#include "SFML/OpenGL.hpp"

PixelMap::PixelMap(int size) :
        _pixels(size * size * 4),
        _size(size) {
    _texture.create(size, size);
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

    _pixels[4 * (x + y * _size)] = 0;
    _pixels[4 * (x + y * _size) + 1] = 0;
    _pixels[4 * (x + y * _size) + 2] = 0;
    if (density > 255) {
        _pixels[4 * (x + y * _size) + 3] = 255;
    } else {
        _pixels[4 * (x + y * _size) + 3] = density;
    }


}

void PixelMap::DrawGL() {
    _texture.update(_pixels.data());


    sf::Texture::bind(NULL);
}


