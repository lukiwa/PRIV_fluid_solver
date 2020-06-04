//
// Created by Lukasz on 04.06.2020.
//

#include "PixelMap.h"


PixelMap::PixelMap(int size) :
        _size(size),
        _pixels(size * size * 4) {
    _texture.create(size, size);
}

void PixelMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    _texture.update(_pixels.data());
    _sprite.setTexture(_texture);
    target.draw(_sprite);
}

void PixelMap::SetPixelDensity(int x, int y, int density) {
    _pixels[(x + y * _size) + 4] = density;
}
