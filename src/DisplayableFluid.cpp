//
// Created by Lukasz on 03.06.2020.
//

#include "DisplayableFluid.h"

DisplayableFluid::DisplayableFluid(int size, float dt, float diffusion, float viscosity,
                                   std::unique_ptr<sf::RenderWindow> window)
        : Fluid(size, dt, diffusion, viscosity), _window(std::move(window)) {}

void DisplayableFluid::Render() {

}

void DisplayableFluid::Fade() {

}