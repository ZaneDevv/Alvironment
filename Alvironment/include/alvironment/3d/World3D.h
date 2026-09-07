#pragma once

#include "./Environment3D.h"
#include "../AbstractWorld.h"

/**
 * @brief Class for 3D worlds
 * @version 1.0
 * @date 2026-09-07
 * @author Álvaro Fernández Barrero
 */
class World3D : public AbstractWorld
{
	friend void setUp(World3D& world);

public:
	std::optional<Environment3D> environment;
};