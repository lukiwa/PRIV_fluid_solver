//
// Created by Lukasz on 02.06.2020.
//

#pragma once

#include "BoundarySymbol.h"
#include "Array2D.h"

namespace fluid {


    void Diffuse(BoundarySymbol bound, Array2D<double> &medium, Array2D<double> &prev_medium,
                 double spread_speed, double dt, int iterations, int size);

    void LinearSolve(BoundarySymbol bound, Array2D<double> &medium, Array2D<double> &prev_medium,
                     double a, double c, int iterations, int size);

    void Project(Array2D<double> &velocity_x, Array2D<double> &velocity_y, Array2D<double> &p,
                 Array2D<double> &divergence, int iterations, int size);

    void Advect(BoundarySymbol bound, Array2D<double> &density, Array2D<double> &prev_density,
                Array2D<double> &velocity_x, Array2D<double> &velocity_y, double dt, int size);

    void SetBoundaryConditions(BoundarySymbol bound, Array2D<double> &velocity, int size);


}




