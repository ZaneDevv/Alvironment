#pragma once

#include "debug_helper/print.h"

class World2D;
class World3D;

/**
 * @brief Set ups the given 2D world and makes it alive
 * @param The world to set up
 * @version 1.2
 * @since 1.0
 * @date 2026-09-01
 * @author Álvaro Fernández Barrero
 */
void setUp(const World2D& world);

/**
 * @brief Set ups the given 4D world and makes it alive
 * @param The world to set up
 * @version 1.0
 * @since 1.0
 * @date 2026-09-07
 * @author Álvaro Fernández Barrero
 */
void setUp(const World3D& world);