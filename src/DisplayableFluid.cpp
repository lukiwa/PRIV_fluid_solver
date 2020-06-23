//
// Created by Lukasz on 03.06.2020.
//

#include "DisplayableFluid.h"

DisplayableFluid::DisplayableFluid(int size, double scale, double dt, double diffusion, double viscosity,
                                   double fade_degree,
                                   sf::RenderWindow &window)
        : Fluid(size, dt, diffusion, viscosity),
          _window(window),
          _pixel_map(size, scale),
          fade_degree(fade_degree),
          _scale(scale) {}


/**
 * @brief Gets fluid state (density at each point) and draws it into the window
 */
void DisplayableFluid::Render() {

    Step();

    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            _pixel_map.SetPixel(i, j, _density(i, j));
        }
    }
    Fade();
    _window.draw(_pixel_map);

}

/**
 * @brief Fluid cells will lightly disappear
 */
void DisplayableFluid::Fade() {
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_density(i, j) > fade_degree) {
                _density(i, j) -= fade_degree;
            }
        }
    }
}