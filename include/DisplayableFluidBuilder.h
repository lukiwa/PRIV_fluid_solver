//
// Created by Lukasz on 04.06.2020.
//

#pragma once

#include "DisplayableFluid.h"


class DisplayableFluidBuilder {

    int _size;
    double _dt;
    double _diffusion;
    double _viscosity;
    double _fade_degree;


public:
    DisplayableFluidBuilder();

    DisplayableFluidBuilder &Size(int size);

    DisplayableFluidBuilder &TimeStep(double dt);

    DisplayableFluidBuilder &Diffusion(double diffusion);

    DisplayableFluidBuilder &Viscosity(double viscosity);

    DisplayableFluidBuilder &Fade(double fade);

    DisplayableFluid Build(sf::RenderWindow &window) const;
};







