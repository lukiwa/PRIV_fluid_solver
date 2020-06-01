//
// Created by Lukasz on 01.06.2020.
//

#pragma once

#include "Array2D.h"

/**
 * @brief Class representing fluid inside square of size = _size;
 */
class Fluid {
    int _size;
    float _dt;
    float _diffusion;
    float _viscosity;

    //TODO std::vector<float> s;

    Array2D<double> _density;
    Array2D<double> _velocity_x;
    Array2D<double> _velocity_y;
    Array2D<double> _prev_velocity_x;
    Array2D<double> _prev_velocity_y;
public:
    Fluid(int size, float dt, float diffusion, float viscosity);

    void AddDensity(int x, int y, float amount);

    void AddVelocity(int x, int y, float amount_x, float amount_y);

    void Step();

};




