//
// Created by Lukasz on 04.06.2020.
//

#include "DisplayableFluidBuilder.h"

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

DisplayableFluidBuilder &DisplayableFluidBuilder::CreateWindow() {
    if (_size == 0) {
        throw std::logic_error("You must set size prior to creating a window");
    }
    _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(_size, _size), "Fluid Solver");
    return *this;
}

DisplayableFluid DisplayableFluidBuilder::Build() {
    return DisplayableFluid(_size, _dt, _diffusion, _viscosity, std::move(_window));
}
