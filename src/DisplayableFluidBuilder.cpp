//
// Created by Lukasz on 04.06.2020.
//

#include "DisplayableFluidBuilder.h"


/**
 * @brief Creates DisplayableFluid with set parameters and render window
 * @param window created render window
 *        NOTE: Window size must correspond to the size of the fluid box!!!
 * @return DisplayableFluid object
 */
DisplayableFluid DisplayableFluidBuilder::Build(sf::RenderWindow &window) const {
    window.create(sf::VideoMode(_size , _size ), "Fluid");
    return DisplayableFluid( _size / _scale, _scale, _dt, _diffusion, _viscosity,
                            _fade_degree, window);
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
    return *this;
}

DisplayableFluidBuilder &DisplayableFluidBuilder::Fade(double fade) {
    _fade_degree = fade;
    return *this;
}

DisplayableFluidBuilder &DisplayableFluidBuilder::Scale(double scale) {
    _scale = scale;
    return *this;
}


