#pragma once

#include "data_types/numbers.h"

/**
 * @brief Struct for Colors
 * @version 1.0
 * @date 2026-09-04
 * @author Álvaro Fernández Barrero
 */
struct Color4
{
	float red = 0.0f;
	float green = 0.0f;
	float blue = 0.0f;
	float alpha = 0.0f;

public:
	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a black color
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	Color4() : Color4(0.0f, 0.0f, 0.0f, 1.0f) {};

	/**
	 * @brief Creates a grey color
	 * @param Grey scale [0, 1]
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	Color4(float grey) : Color4(grey, grey, grey, 1.0f) {};

	/**
	 * @brief Creates a new RGB color
	 * @param Red value [0, 1]
	 * @param Green value [0, 1]
	 * @param Blue value [0, 1]
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	Color4(float red, float green, float blue) : Color4(red, green, blue, 1.0f) {};

	/**
	 * @brief Creates a new RGBA color
	 * @param Red value [0, 1]
	 * @param Green value [0, 1]
	 * @param Blue value [0, 1]
	 * @param Alpha value [0, 1]
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	Color4(float, float, float, float);

	/**
	 * @brief Creates a new RGBA color in hexadecimal
	 * @param Hexadecimal RGBA code
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	Color4(u32_t);

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------
	
	/**
	 * @brief Changes the color to a brand new one
	 * @param Red value [0, 1]
	 * @param Green value [0, 1]
	 * @param Blue value [0, 1]
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	void setRGB(u8_t, u8_t, u8_t);

	/**
	 * @brief Changes the color to a brand new one
	 * @param Red value [0, 1]
	 * @param Green value [0, 1]
	 * @param Blue value [0, 1]
	 * @param Alpha value [0, 1]
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	void setRGBA(u8_t, u8_t, u8_t, u8_t);

	/**
	 * @brief Gets the red channel
	 * @return Color's red channel
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	float getRed();

	/**
	 * @brief Sets the red channel
	 * @param Red value [0, 1]
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	void setRed(float);

	/**
	 * @brief Gets the green channel
	 * @return Color's green channel
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	float getGreen();

	/**
	 * @brief Sets the green channel
	 * @param Green value [0, 1]
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	void setGreen(float);

	/**
	 * @brief Gets the blue channel
	 * @return Color's blue channel
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	float getBlue();

	/**
	 * @brief Sets the blue channel
	 * @param Blue value [0, 1]
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	void setBlue(float);

	/**
	 * @brief Gets the alpha channel
	 * @return Color's alpha channel
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	float getAlpha();

	/**
	 * @brief Sets the alpha channel
	 * @param Alpha value [0, 1]
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	void setAlpha(float);
};