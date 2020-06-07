//
// Created by Lukasz on 01.06.2020.
//

#pragma once

#include "Array2D.h"
#include "FluidFunctions.h"

/**
 * @brief Class representing fluid inside square of size = _size;
 */
class Fluid {

    double _dt;
    double _diffusion;
    double _viscosity;

    Array2D<double> _velocity_x;
    Array2D<double> _velocity_y;
    Array2D<double> _prev_velocity_x;
    Array2D<double> _prev_velocity_y;

protected:
    int _size;
    Array2D<double> _prev_density;
    Array2D<double> _density;


public:
    Fluid(int size, double dt, double diffusion, double viscosity);


    virtual ~Fluid() = default;

    void AddDensity(int x, int y, float amount);

    void AddVelocity(int x, int y, float amount_x, float amount_y);

    void Step();

};




