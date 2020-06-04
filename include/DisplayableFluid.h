//
// Created by Lukasz on 03.06.2020.
//

#pragma once

#include "SFML/Graphics.hpp"
#include "Fluid.h"


class DisplayableFluidBuilder;

class DisplayableFluid : public Fluid {
    friend class DisplayableFluidBuilder;

    std::unique_ptr<sf::RenderWindow> _window;

    DisplayableFluid(int size, float dt, float diffusion, float viscosity, std::unique_ptr<sf::RenderWindow>);

public:

    ~DisplayableFluid() override = default;

    void Render();

    void Fade();

};




