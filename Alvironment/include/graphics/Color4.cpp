#include "Color4.h"

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Color4::Color4(float red, float green, float blue, float alpha)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->blue = alpha;
}

Color4::Color4(u32_t hexadecimal)
{
	this->red = static_cast<float>((hexadecimal >> 24) & 0xFF) / (float)0xFF;
	this->green = static_cast<float>((hexadecimal >> 16) & 0xFF) / (float)0xFF;
	this->blue = static_cast<float>((hexadecimal >> 8) & 0xFF) / (float)0xFF;
	this->alpha = static_cast<float>(hexadecimal & 0xFF) / (float)0xFF;
}

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

void Color4::setRGB(u8_t red, u8_t green, u8_t blue)
{
	this->red = static_cast<float>(red / 0xFF);
	this->green = static_cast<float>(green / 0xFF);
	this->blue = static_cast<float>(blue / 0xFF);
}

void Color4::setRGBA(u8_t red, u8_t green, u8_t blue, u8_t alpha)
{
	this->setRGB(red, green, blue);
	this->alpha = alpha / 100.0f;
}

float Color4::getRed()
{
	return this->red;
}

void Color4::setRed(float red)
{
	this->red = red;
}

float Color4::getGreen()
{
	return this->green;
}

void Color4::setGreen(float green)
{
	this->green = green;
}

float Color4::getBlue()
{
	return this->blue;
}

void Color4::setBlue(float blue)
{
	this->blue = blue;
}

float Color4::getAlpha()
{
	return this->alpha;
}

void Color4::setAlpha(float alpha)
{
	this->alpha = alpha;
}