#include "Window.h"
#include "debug_helper/print.h"

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

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

// ------------------------------------------------------
// DESTRUCTORS
// ------------------------------------------------------

Window::~Window()
{
	glfwDestroyWindow(this->window);
}

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

bool Window::shouldWindowClose()
{
	return glfwWindowShouldClose(this->window);
}

void Window::prepareWindowForRendering()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::finishRendering()
{
	glfwSwapBuffers(this->window);
	glfwPollEvents();
}