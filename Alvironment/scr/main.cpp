#include <iostream>
#include <memory>

#include "alvironment/WorldSetUp.h"

#include "./LinearInterpolation/LinearInterpolation.h"
#include "./SolarSystem/SolarSystem.h"
#include "./Dvd/Dvd.h"

#include "debug_helper/print.h"

/**
 * @file main.cpp
 * @version 4.2
 * @date 2026-09-02
 * @author Álvaro Fernández Barrero
 */

int main()
{
	short simulationIndex = 0;

	PRINT("Choose the simulation you want to run:");
	PRINT("\t1. Linear interpolation");
	PRINT("\t2. 2D solar system");
	PRINT("\t3. DVD");

	std::cout << "\nSend the number of the simulation you want to run:\n";
	std::cin >> simulationIndex;
	std::cout << "\n";

	std::unique_ptr<AbstractWorld> worldToRun;

	do
	{
		switch (simulationIndex)
		{
		case 1:
			worldToRun = std::make_unique<LinearInterpolation>();
			break;

		case 2:
			worldToRun = std::make_unique<SolarSystem>();
			break;

		case 3:
			worldToRun = std::make_unique<Dvd>();
			break;

		default:
			WARNING_PRINT("Unknown simulation!");
			break;
		}
	} while (worldToRun.get() == nullptr);

	setUp(*worldToRun.get());

	std::cin.get();
	return 0;
}