//
// Created by Lukasz on 03.06.2020.
//

#pragma once

#include "SFML/Graphics.hpp"
#include "Fluid.h"
#include "PixelMap.h"

class DisplayableFluidBuilder;

/**
 * @brief Represents fluid which can be displayed in sf::RenderWindow
 */
class DisplayableFluid : public Fluid {
    friend class DisplayableFluidBuilder;

    sf::RenderWindow &_window; //window in which fluid will be displayed
    PixelMap _pixel_map; //all fluid cells represented as pixels
    double fade_degree; //how much the fluid will fade in time


    DisplayableFluid(int size, double dt, double diffusion, double viscosity, double fade_degree,
                     sf::RenderWindow &window);

    void Fade();

public:

    ~DisplayableFluid() override = default;

    void Render();

};




