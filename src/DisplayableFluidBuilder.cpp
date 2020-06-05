//
// Created by Lukasz on 04.06.2020.
//

#include "DisplayableFluidBuilder.h"

DisplayableFluidBuilder::DisplayableFluidBuilder() :
        _size(0),
        _dt(0.1),
        _diffusion(0),
        _viscosity(0),
        _fade_degree(0) {}

/**
 * @brief Creates DisplayableFluid with set parameters and render window
 * @param window created render window
 *        NOTE: Window size must correspond to the size of the fluid box!!!
 * @return DisplayableFluid object
 */
DisplayableFluid DisplayableFluidBuilder::Build(sf::RenderWindow &window) const {
    window.create(sf::VideoMode(_size, _size), "Fluid");
    return DisplayableFluid(_size, _dt, _diffusion, _viscosity, _fade_degree, window);
}

DisplayableFluidBuilder &DisplayableFluidBuilder::Size(int size) {
    _size = size;
    return *this;
}

DisplayableFluidBuilder &DisplayableFluidBuilder::TimeStep(double dt) {
    _dt = dt;
    return *this;
}

DisplayableFluidBuilder &DisplayableFluidBuilder::Diffusion(double diffusion) {
    _diffusion = diffusion;
    return *this;
}

DisplayableFluidBuilder &DisplayableFluidBuilder::Viscosity(double viscosity) {
    _viscosity = viscosity;
}

DisplayableFluidBuilder &DisplayableFluidBuilder::Fade(double fade) {
    _fade_degree = fade;
    return *this;
}


