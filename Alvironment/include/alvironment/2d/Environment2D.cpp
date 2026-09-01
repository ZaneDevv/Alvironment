#include "Environment2D.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "debug_helper/print.h"

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Environment2D::Environment2D(WindowProperties* windowProperties)
{
    if (!glfwInit())
    {
        ERROR_PRINT("GLFW could not be initialized!");
        throw "GLFW could not be initialized";
    }

    this->window = std::make_unique<Window>(
        windowProperties->width,
        windowProperties->height,
        windowProperties->title,
        windowProperties->resizeable
    );

    if (glewInit() != GLEW_OK)
    {
        ERROR_PRINT("Glew could not be initialized!");
        throw "Glew could not be initialized!";
    }
}

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

void Environment2D::initialize(void(*update)())
{
    DEBUG_PRINT("Environment has just initialized");
    DEBUG_PRINT("Starting simulation loop");

    while (!this->window->shouldWindowClose())
    {
        this->window->prepareWindowForRendering();

        update();
        this->renderObjects();

        this->window->finishRendering();
    }
}

void Environment2D::renderObjects()
{
    for (Object2D* object : this->objectsInEnvironment)
    {
        object->render();
    }
}

inline bool Environment2D::shouldGoToNextRenerIteration()
{
    return !this->window->shouldWindowClose();
}

void Environment2D::addObject(Object2D* object)
{
    DEBUG_PRINT("A new object was added to the 2D enviroment!");

    object->setUpBuffers();
	this->objectsInEnvironment.push_back(object);
}