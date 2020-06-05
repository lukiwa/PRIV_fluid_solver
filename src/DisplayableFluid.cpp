//
// Created by Lukasz on 03.06.2020.
//

#include "DisplayableFluid.h"

DisplayableFluid::DisplayableFluid(int size, float dt, float diffusion, float viscosity,
                                   sf::RenderWindow *window)
        : Fluid(size, dt, diffusion, viscosity), _window(window), _pixel_map(size) {}

void DisplayableFluid::Render() {
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            _pixel_map.SetPixelDensity(i, j, _density(i, j));
        }
    }
    _window->draw(_pixel_map);
}

void DisplayableFluid::Fade() {
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_density(i, j) > 1) {
                _density(i, j) -= 0.1;
            }
        }
    }
}