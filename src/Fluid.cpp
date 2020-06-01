//
// Created by Lukasz on 01.06.2020.
//

#include "Fluid.h"

Fluid::Fluid(int size, float dt, float diffusion, float viscosity) : _size(size),
                                                                     _dt(dt),
                                                                     _diffusion(diffusion),
                                                                     _viscosity(viscosity),
                                                                     _density(size),
                                                                     _velocity_x(size),
                                                                     _velocity_y(size),
                                                                     _prev_velocity_x(size),
                                                                     _prev_velocity_y(size) {

}

/**
 * @brief Adds dye intensity at given point
 * @param x x coord
 * @param y y coord
 * @param amount amount of dye to be added
 */
void Fluid::AddDensity(int x, int y, float amount) {
    _density(x, y) += amount;
}

/**
 * @brief Adds velocity at given point
 * @param x x coord
 * @param y y coord
 * @param amount_x amount of velocity at x direction
 * @param amount_y amount of velocity at y direction
 */
void Fluid::AddVelocity(int x, int y, float amount_x, float amount_y) {
    _velocity_x(x, y) += amount_x;
    _velocity_y(x, y) += amount_y;
}

/** TODO
 * @brief Calculates fluid state at next time step - determined by _dt
 */
void Fluid::Step() {

}

