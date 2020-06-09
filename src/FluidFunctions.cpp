//
// Created by Lukasz on 02.06.2020.
//

#include <cmath>
#include "FluidFunctions.h"

/**
 * @brief Diffuse dye(density) or velocities inside fluid
 * @param bound at which edge boundary conditions will later be set
 * @param medium velocity or density will be spreaded
 * @param prev_medium previous medium conditions
 * @param spread_speed speed of spreading the medium
 * @param dt time step
 * @param iterations in how many iterations the diffusion will take place
 * @param size size of the cube in which fluid is stored
 */
void fluid::Diffuse(BoundarySymbol bound, Array2D<double> &medium, Array2D<double> &prev_medium,
                    double spread_speed, double dt, int iterations, int size) {
    double a = dt * spread_speed * (size - 2) * (size - 2);
    LinearSolve(bound, medium, prev_medium, a, 1 + 6 * a, iterations, size);
}

/**
 * @brief Solves linear equations
 * @param bound at which edge boundary conditions will later be set
 * @param medium amount of medium that expands
 * @param prev_medium previous amount of medium that expands
 * @param a differential equation parameter
 * @param c differential equation parameter
 * @param size size of the cube in which fluid is stored in
 */
void fluid::LinearSolve(BoundarySymbol bound, Array2D<double> &medium, Array2D<double> &prev_medium,
                        double a, double c, int iterations, int size) {
    double c_reciprocal = 1.0 / c;

    for (int k = 0; k < iterations; ++k) {
        for (int j = 1; j < size - 1; ++j) {
            for (int i = 1; i < size - 1; ++i) {
                medium(i, j) = (prev_medium(i, j) +
                                a * (medium(i + 1, j) +
                                     medium(i - 1, j) +
                                     medium(i, j + 1) +
                                     medium(i, j - 1))
                               ) * c_reciprocal;
            }
        }
        SetBoundaryConditions(bound, medium, size);
    }
}

/**
 * @brief As the fluid is incompressible the amount of it must remain constant - amount of fluid going out must
 *        be the same as the fluid going in. This functions runs through all the velocities cells and fixes them
 * @param velocity_x x velocity
 * @param velocity_y y velocity
 * @param p TODO what is this
 * @param divergence divergency of the fluid
 * @param iterations in how many iterations the projection will take place
 * @param size size of the cube in which fluid is stored in
 */
void fluid::Project(Array2D<double> &velocity_x, Array2D<double> &velocity_y, Array2D<double> &p,
                    Array2D<double> &divergence, int iterations, int size) {

    for (int j = 1; j < size - 1; ++j) {
        for (int i = 1; i < size - 1; ++i) {
            divergence(i, j) = -0.5f * (velocity_x(i + 1, j)
                                        - velocity_x(i - 1, j)
                                        + velocity_y(i, j + 1)
                                        - velocity_y(i, j - 1)) / size;
            p(i, j) = 0;
        }
    }

    SetBoundaryConditions(BoundarySymbol::SIDE, divergence, size);
    SetBoundaryConditions(BoundarySymbol::SIDE, p, size);
    LinearSolve(BoundarySymbol::UP, p, divergence, 1, 6, iterations, size);


    for (int j = 1; j < size - 1; j++) {
        for (int i = 1; i < size - 1; i++) {
            velocity_x(i, j) -= 0.5f * (p(i + 1, j)
                                        - p(i - 1, j)) * size;

            velocity_y(i, j) -= 0.5f * (p(i, j + 1)
                                        - p(i, j - 1)) * size;

        }
    }

    SetBoundaryConditions(BoundarySymbol::UP, velocity_x, size);
    SetBoundaryConditions(BoundarySymbol::DOWN, velocity_y, size);

}

/**
 * @brief Moves density and velocities given set of velocities at given point.
 * @param bound bound at which edge boundary conditions will later be set
 * @param density density field
 * @param prev_density previous density field
 * @param velocity_x field of x velocities
 * @param velocity_y field of y velocities
 * @param dt time step
 * @param size size of cube in which fluid is stored
 */
void fluid::Advect(BoundarySymbol bound, Array2D<double> &density, Array2D<double> &prev_density,
                   Array2D<double> &velocity_x, Array2D<double> &velocity_y, double dt, int size) {

    double dt_x = dt * (size - 2);
    double dt_y = dt * (size - 2);

    double temp_velocity_x, temp_velocity_y;
    double x, y;

    double prev_x, next_x, prev_y, next_y;

    //TODO what is this
    double s0, s1, t0, t1;

    for (int j = 1; j < size - 1; ++j) {
        for (int i = 1; i < size - 1; ++i) {
            temp_velocity_x = dt_x * velocity_x(i, j);
            temp_velocity_y = dt_y * velocity_y(i, j);
            x = i - temp_velocity_x;
            y = j - temp_velocity_y;

            if (x < 0.5) { x = 0.5; }
            if (x > size + 0.5) { x = size - 2; }
            prev_x = std::floor(x);
            next_x = prev_x + 1;

            if (y < 0.5) { y = 0.5; }
            if (y > size + 0.5) { y = size - 2 ; }
            prev_y = std::floor(y);
            next_y = prev_y + 1;

            s1 = x - prev_x;
            s0 = 1 - s1;
            t1 = y - prev_y;
            t0 = 1 - t1;

            //TODO double check
            density(i, j) = s0 * (t0 * prev_density(prev_x, prev_y) + t1 * prev_density(prev_x, next_y))
                            + s1 * (t0 * prev_density(next_x, prev_y) + t1 * prev_density(next_x, next_y));

        }
    }
    SetBoundaryConditions(bound, density, size);
}

/**
 * @brief Set boundaries near the box edges
 * @param bound on which edge boundaries will be set
 * @param velocity field to set boundaries
 * @param size size of the box
 */
void fluid::SetBoundaryConditions(BoundarySymbol bound, Array2D<double> &velocity, int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (bound == BoundarySymbol::DOWN) {
            velocity(i, 0) = -velocity(i, 1);
            velocity(i, size - 1) = -velocity(i, size - 2);
        } else {
            velocity(i, 0) = velocity(i, 1);
            velocity(i, size - 1) = velocity(i, size - 2);
        }
    }
    for (int j = 0; j < size - 1; ++j) {
        if (bound == BoundarySymbol::UP) {
            velocity(0, j) = -velocity(1, j);
            velocity(size - 1, j) = -velocity(size - 2, j);
        } else {
            velocity(0, j) = velocity(1, j);
            velocity(size - 1, j) = velocity(size - 2, j);
        }
    }

    //boundaries at the corners
    velocity(0, 0) = 0.5f * (velocity(1, 0) + velocity(0, 1));
    velocity(0, size - 1) = 0.5f * (velocity(1, size - 1) + velocity(0, size - 2));
    velocity(size - 1, 0) = 0.5f * (velocity(size - 2, 0) + velocity(size - 1, 1));
    velocity(size - 1, size - 1) = 0.5f * (velocity(size - 2, size - 1) + velocity(size - 1, size - 2));


}
