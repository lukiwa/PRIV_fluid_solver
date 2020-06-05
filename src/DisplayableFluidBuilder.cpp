//
// Created by Lukasz on 04.06.2020.
//

#include "DisplayableFluidBuilder.h"

DisplayableFluidBuilder::DisplayableFluidBuilder() :
        _size(0),
        _dt(0.1),
        _diffusion(0),
        _viscosity(0) {}

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

DisplayableFluidBuilder &DisplayableFluidBuilder::CreateWindow(sf::RenderWindow *window) {
    _window = std::move(window);
    return *this;
}

DisplayableFluid DisplayableFluidBuilder::Build() {
    return DisplayableFluid(_size, _dt, _diffusion, _viscosity, _window);
}

