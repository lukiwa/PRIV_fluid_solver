//
// Created by Lukasz on 04.06.2020.
//

#pragma once

#include "DisplayableFluid.h"


class DisplayableFluidBuilder {

    int _size{0};
    double _dt{0.1};
    double _diffusion{0};
    double _viscosity{0};
    double _fade_degree{0};
    double _scale{1};


public:
    DisplayableFluidBuilder() = default;

    ~DisplayableFluidBuilder() = default;

    DisplayableFluidBuilder &Size(int size);

    DisplayableFluidBuilder &TimeStep(double dt);

    DisplayableFluidBuilder &Diffusion(double diffusion);

    DisplayableFluidBuilder &Viscosity(double viscosity);

    DisplayableFluidBuilder &Fade(double fade);

    DisplayableFluidBuilder &Scale(double scale);

    DisplayableFluid Build(sf::RenderWindow &window) const;
};







