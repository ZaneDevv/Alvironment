#include "Rectangle2D.h"

// ------------------------------------------------------
// STATIC FIELDS
// ------------------------------------------------------

float Rectangle2D::vertices[Rectangle2D::verticesAmount] = {
    -0.5f, -0.5f, 0.0f, 0.0f,
     0.5f, -0.5f, 1.0f, 0.0f,
     0.5f,  0.5f, 1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f, 1.0f
};

u32_t Rectangle2D::indices[Rectangle2D::indicesAmount] = {
    0, 1, 2,
    2, 3, 0
};