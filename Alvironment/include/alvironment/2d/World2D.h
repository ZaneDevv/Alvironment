#pragma once

#include "./Environment2D.h"
#include "../AbstractWorld.h"

/**
 * @brief Class for 2D worlds
 * @version 1.0
 * @date 2026-09-07
 * @author Álvaro Fernández Barrero
 */
class World2D : public AbstractWorld
{
	friend void setUp(World2D& world);

public:
	std::optional<Environment2D> environment;
};