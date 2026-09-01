#include "Environment2D.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "debug_helper/print.h"

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

void Environment2D::initialize()
{
    DEBUG_PRINT("Environment has just initialized");
    this->window->startRenderLoop();
}

void Environment2D::addObject(Object2D* object)
{
    DEBUG_PRINT("A new object was added to the 2D enviroment!");

	this->objectsInEnvironment.push_back(object);
	this->window->addElementToRender(object);
}