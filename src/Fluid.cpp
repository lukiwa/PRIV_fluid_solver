//
// Created by Lukasz on 01.06.2020.
//

#include "Fluid.h"

Fluid::Fluid(int size, double dt, double diffusion, double viscosity) : _dt(dt),
                                                                        _diffusion(diffusion),
                                                                        _viscosity(viscosity),
                                                                        _velocity_x(size),
                                                                        _velocity_y(size),
                                                                        _prev_velocity_x(size),
                                                                        _prev_velocity_y(size),
                                                                        _size(size),
                                                                        _prev_density(size),
                                                                        _density(size) {}


/**
 * @brief Adds dye intensity at given point
 * @param x x coord
 * @param y y coord
 * @param amount amount of dye to be added
 */
void Fluid::AddDensity(int x, int y, double amount) {
    _density(x, y) += amount;
}

/**
 * @brief Adds velocity at given point
 * @param x x coord
 * @param y y coord
 * @param amount_x amount of velocity at x direction
 * @param amount_y amount of velocity at y direction
 */
void Fluid::AddVelocity(int x, int y, double amount_x, double amount_y) {
    _velocity_x(x, y) += amount_x;
    _velocity_y(x, y) += amount_y;
}


/**
 * @brief Calculates fluid state at next time step - determined by _dt
 */
void Fluid::Step() {
    fluid::Diffuse(BoundarySymbol::UP, _prev_velocity_x, _velocity_x, _viscosity, _dt, 4, _size);
    fluid::Diffuse(BoundarySymbol::DOWN, _prev_velocity_y, _velocity_y, _viscosity, _dt, 4, _size);


    fluid::Project(_prev_velocity_x, _prev_velocity_y, _velocity_x, _velocity_y, 4, _size);


    fluid::Advect(BoundarySymbol::UP, _velocity_x, _prev_velocity_x, _prev_velocity_x,
                  _prev_velocity_y, _dt, _size);
    fluid::Advect(BoundarySymbol::DOWN, _velocity_y, _prev_velocity_y, _prev_velocity_x,
                  _prev_velocity_y, _dt, _size);


    fluid::Project(_velocity_x, _velocity_y, _prev_velocity_x, _prev_velocity_y, 4, _size);

    fluid::Diffuse(BoundarySymbol::SIDE, _prev_density, _density, _diffusion, _dt, 4, _size);
    fluid::Advect(BoundarySymbol::SIDE, _density, _prev_density, _velocity_x, _velocity_y, _dt, _size);
}


