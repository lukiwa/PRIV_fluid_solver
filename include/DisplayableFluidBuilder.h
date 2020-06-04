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
    std::unique_ptr<sf::RenderWindow> _window;


public:

    DisplayableFluidBuilder &Size(int size);

    DisplayableFluidBuilder &TimeStep(double dt);

    DisplayableFluidBuilder &Diffusion(double diffusion);

    DisplayableFluidBuilder &Viscosity(double viscosity);

    DisplayableFluidBuilder &CreateWindow();

    DisplayableFluid Build();
};







