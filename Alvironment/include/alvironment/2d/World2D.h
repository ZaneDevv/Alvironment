#pragma once

#include "./Environment2D.h"
#include "../AbstractWorld.h"

class World2D : public AbstractWorld
{
	friend void setUp(World2D& world);
public:
	std::optional<Environment2D> environment;
};