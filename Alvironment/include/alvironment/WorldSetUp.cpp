#include "./WorldSetUp.h"
#include "./AbstractWorld.h"

#include "debug_helper/print.h"

void setUp(AbstractWorld& world)
{
    DEBUG_PRINT("Initializing the world");

    world.initialize();

    if (!world.environment.has_value())
    {
        ERROR_PRINT("The initialize method has not created an environment! It is neccessary to create a world, be sure you are setting it up");
        throw "The world has not created an environment. It is not possible to run a world without it";
    }

    SUCCESS_PRINT("World initializated successfully. Running the update method");

    world.environment->initialize([&world](double deltaTime)
    {
        world.update(deltaTime);
    });
}