#include "SpinningCube.h"

// Runs when the world sets up

void SpinningCube::initialize()
{
	// Creating the environment with the given window's parameters

	WindowProperties properties(500, 500, "Spinning cube", true);

	this->environment.emplace(&properties);
	this->environment->enableFreeCamera(true);

	// Creating the cube

	this->cube = std::make_unique<Cube3D>("src/Samples/SpinningCube/texture.jpg");
	this->cube->setPosition(Vector3D::k * 6);
	this->cube->setScale(Vector3D(3, 3, 3));
	this->cube->setShaderProperty("color4", Color4(0xFFFFFFFF));

	// Adding the objects to the environment

	this->environment->addObject(this->cube.get());
}

// Runs every frame after setting up the world

void SpinningCube::update(double deltaTime)
{
	// Adding rotation to the cube

	this->cube->setRotation(this->cube->getRotation() * Quaternion(deltaTime, this->rotationAxis));
}