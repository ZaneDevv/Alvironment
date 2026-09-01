#include "./WindowProperties.h"

WindowProperties::WindowProperties(u16_t width, u16_t height, const char* title, bool resizeable)
{
	this->width = width;
	this->height = height;
	this->title = title;
	this->resizeable = resizeable;
}