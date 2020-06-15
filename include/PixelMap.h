//
// Created by Lukasz on 04.06.2020.
//

#pragma once

#include "SFML/Graphics.hpp"

class PixelMap : public sf::Drawable {
    std::vector<sf::Uint8> _pixels; //RGBA format
    mutable sf::Texture _texture;
    mutable sf::Sprite _sprite;
    int _size;
    double _scale;

public:
    explicit PixelMap(int size, double scale);

    void SetPixel(int x, int y, int density);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};




