#include "Window.h"
#include "debug_helper/print.h"

Window::Window(u16_t width, u16_t height, const char* title, bool allowResizing)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, allowResizing);

	this->window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!this->window)
	{
		ERROR_PRINT("It was not possible to create a window!");
		throw "It was not possible to create a window";
	}

	glfwMakeContextCurrent(this->window);
	glViewport(0, 0, width, height);

	glClearColor(0.1f, 0.1f, 0.125f, 1.0f);

	SUCCESS_PRINT("Window created successfully");
}

Window::~Window()
{
	glfwDestroyWindow(this->window);
}

void Window::startRenderLoop()
{
	this->isRenderLoopPaused = false;

	DEBUG_PRINT("Starting rendering loop");

	while (this->shouldGoToNextRenerIteration())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		for (GenericObject* object : this->elementsToRender)
		{
			object->render();
		}

		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}
}

void Window::pauseRenderLoop()
{
	this->isRenderLoopPaused = true;
	DEBUG_PRINT("Rendering paused");
}

inline bool Window::shouldGoToNextRenerIteration()
{
	return !this->isRenderLoopPaused && !glfwWindowShouldClose(this->window);
}

void Window::addElementToRender(GenericObject* object)
{
	DEBUG_PRINT("A new object was added to the rendering queue!");

	object->setUpBuffers();
	this->elementsToRender.push_back(object);
}