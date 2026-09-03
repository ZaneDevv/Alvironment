#include "Environment.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "debug_helper/print.h"

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Environment::Environment(WindowProperties* windowProperties)
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

inline bool Environment::shouldGoToNextRenerIteration()
{
    return !this->window->shouldWindowClose();
}

void Environment::initialize(updateMethod update)
{
    DEBUG_PRINT("Environment has just initialized");
    DEBUG_PRINT("Starting simulation loop");

    double lastTime = glfwGetTime();
    double deltaTime = 0;

    while (!this->window->shouldWindowClose())
    {
        this->computeDeltaTime(lastTime, deltaTime);

        this->window->prepareWindowForRendering();

        this->updateProportionsOnWindowSize();
        this->renderObjects();

        update(deltaTime);

        this->window->finishRendering();
    }
}

void Environment::computeDeltaTime(double& lastTime, double& deltaTime)
{
    deltaTime = glfwGetTime() - lastTime;
    lastTime = glfwGetTime();
}

void Environment::renderObjects()
{
    for (GenericObject* object : this->objectsInEnvironment)
    {
        object->updateWindowDimensions(this->lastWindowWidth, this->lastWindowHeight);
        object->render();
    }
}

void Environment::updateProportionsOnWindowSize()
{
    u32_t newWidth = 0;
    u32_t newHeight = 0;

    this->window->getDimensions(newWidth, newHeight);

    bool wasScreenSizeChanged = this->lastWindowWidth != newWidth || this->lastWindowHeight != newHeight;

    if (wasScreenSizeChanged)
    {
        this->lastWindowWidth = newWidth;
        this->lastWindowHeight = newHeight;
    }
}

void Environment::addObject(GenericObject* object)
{
    DEBUG_PRINT("A new object was added to the 2D enviroment!");

    object->setUpBuffers();
    object->updateVertices();

    this->objectsInEnvironment.push_back(object);
}

bool Environment::isKeyPressed(Key key)
{
    return this->window->isKeyPressed(key);
}

void Environment::getMousePosition(double& x, double& y)
{
    this->window->getMousePosition(x, y);

    x -= this->lastWindowWidth / 2;
    y -= this->lastWindowHeight / 2;

    y *= -1;
}