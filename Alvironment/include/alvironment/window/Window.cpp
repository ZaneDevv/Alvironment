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

	this->width = width;
	this->height = height;

	this->window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!this->window)
	{
		ERROR_PRINT("It was not possible to create a window!");
		throw "It was not possible to create a window";
	}

	glfwMakeContextCurrent(this->window);
	glViewport(0, 0, width, height);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glfwSetWindowUserPointer(this->window, this);
	glfwSetFramebufferSizeCallback(this->window, [](GLFWwindow* glfwWindow, int width, int height)
	{
		auto* window = static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));

		window->width = width;
		window->height = height;

		glViewport(0, 0, width, height);
	});

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

void Window::enableDepth() const
{
	glEnable(GL_DEPTH_TEST);
	this->clearBuffers |= GL_DEPTH_BUFFER_BIT;
}

bool Window::shouldWindowClose() const
{
	return glfwWindowShouldClose(this->window);
}

void Window::prepareWindowForRendering() const
{
	glClear(this->clearBuffers);
}

void Window::finishRendering() const
{
	glfwSwapBuffers(this->window);
	glfwPollEvents();
}

void Window::getDimensions(u32_t& width, u32_t& height) const
{
	width = this->width;
	height = this->height;
}

bool Window::isKeyPressed(Key key) const
{
	return glfwGetKey(this->window, static_cast<int>(key)) == GLFW_PRESS || glfwGetMouseButton(this->window, static_cast<int>(key)) == GLFW_PRESS;
}

void Window::getMousePosition(double& x, double& y) const
{
	glfwGetCursorPos(this->window, &x, &y);
}