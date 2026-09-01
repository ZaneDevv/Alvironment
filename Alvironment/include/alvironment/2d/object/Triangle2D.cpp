#include "Triangle2D.h"

// ------------------------------------------------------
// STATIC FIELDS
// ------------------------------------------------------

float Triangle2D::vertices[Triangle2D::verticesAmount] = {
    -0.5f, -0.5f,
     0.5f, -0.5f,
     0.0f, 0.5f
};

u32_t Triangle2D::indices[Triangle2D::indicesAmount] = {
    0, 1, 2
};