#include <iostream>
#include <memory>

#include "alvironment/WorldSetUp.h"

#include "./Samples/LinearInterpolation/LinearInterpolation.h"
#include "./Samples/SolarSystem/SolarSystem.h"
#include "./Samples/Dvd/Dvd.h"
#include "./Samples/Arkanoid/Arkanoid.h"

#include "debug_helper/print.h"

/**
 * This is a main method sample for setting up your own simulations. In this case, you will encounter a few simple simulations in order to illustrate
 * what this engine is capable of. Though, by and large this will not be what it is needed to do to set up a world.
 * 
 * To set up your own environments, you will just have to create an instance of the class of your world and put it as a parameter in the method setUp
 * you can see at the end of the main method, which is imported with #include "alvironment/WorldSetUp.h".
 * 
 * To know more about this, visit the project's repository in https://github.com/ZaneDevv/Alvironment/, where there are a lot of useful information in
 * case you wanted to use this code engine.
 * 
 * @file main.cpp
 * @version 4.5
 * @date 2026-09-02
 * @author Álvaro Fernández Barrero
 */


/**
 * @brief Gets the simulation's index to run
 * @param Chosen simulation's index
 * @version 1.0
 * @since 4.4
 * @version 1.0
 * @author Álvaro Fernández Barrero
 */
void getSimulationIndex(short&);

/**
 * @brief Gets the simulation's index to run
 * @param Chosen simulation
 * @param Chosen simulation's index
 * @version 1.0
 * @since 4.4
 * @version 1.0
 * @author Álvaro Fernández Barrero
 */
void getSimulationByIndex(std::unique_ptr<AbstractWorld>&, short);

int main()
{
	std::cout << RESET_COLOR;

	short simulationIndex = 0;
	getSimulationIndex(simulationIndex);

	std::unique_ptr<AbstractWorld> worldToRun;
	getSimulationByIndex(worldToRun, simulationIndex);

	if (worldToRun.get() != nullptr)
	{
		setUp(*worldToRun.get());
	}

	std::cin.get();
	return 0;
}

void getSimulationIndex(short& index)
{
	PRINT(BACKGROUND_RED << "[Alvironment]:" << RESET_COLOR  << " Choose the simulation you want to run:");

	PRINT("\t1. Linear interpolation");
	PRINT("\t2. 2D solar system");
	PRINT("\t3. DVD");
	PRINT("\t4. Arkanoid");

	do
	{
		std::cout << "\nSend the number of the simulation you want to run:\n" << YELLOW;
		std::cin >> index;
		std::cout << RESET_COLOR;
	}
	while (index < 1 || index > 4);

	std::cout << "\n";
}

void getSimulationByIndex(std::unique_ptr<AbstractWorld>& world, short simulationIndex)
{
	switch (simulationIndex)
	{
	case 1:
		world = std::make_unique<LinearInterpolation>();
		break;

	case 2:
		world = std::make_unique<SolarSystem>();
		break;

	case 3:
		world = std::make_unique<Dvd>();
		break;

	case 4:
		world = std::make_unique<Arkanoid>();
		break;

	default:
		WARNING_PRINT("Unknown simulation!");
		break;
	}
}