#pragma once

#include "./Object2D.h"
#include "data_types/numbers.h"

/**
 * @brief Class for creating 2D circles
 * @version 2.4
 * @date 2026-09-01
 * @author Álvaro Fernández Barrero
 */
class Circle2D : public Object2D
{
private:
	static const double DEFAULT_SMOOTHNESS;
	static const double MAXIMUM_SMOOTHNESS;
	static const double MINIMUM_SMOOTHNESS;

	u32_t verticesAmount = 0;
	u32_t indicesAmount = 0;

	float* vertices = nullptr;
	u32_t* indices = nullptr;

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Adjusts the smoothness value to fit a proper interval
	 * @param Smoothness to adjust
	 * @version 1.0
	 * @since 2.3
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	static void adjustSmoothness(double&);

	/**
	 * @brief Computes the vertices' position of the circle according to the given smoothness
	 * @param Circle's smoothness (the lower this number is, the smoother the circle is)
	 * @return The vertices' position
	 * @version 1.0
	 * @since 2.1
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	static float* computeVertices(double);

	/**
	 * @brief Computes the indices' of the circle according to the given smoothness
	 * @param Circle's smoothness (the lower this number is, the smoother the circle is)
	 * @return The circle's indices
	 * @version 1.0
	 * @since 2.1
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	static u32_t* computeIndices(double);

	/**
	 * @brief Computes circle's vertices amount by its smoothness
	 * @param Circle's smoothness (the lower this number is, the smoother the circle is)
	 * @return The circle's vertices amount
	 * @version 1.0
	 * @since 2.1
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	static u32_t computeVerticesAmount(double);

	/**
	 * @brief Computes circle's indices amount by its smoothness
	 * @param Circle's smoothness (the lower this number is, the smoother the circle is)
	 * @return The circle's indices amount
	 * @version 1.0
	 * @since 2.1
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	static u32_t computeIndicesAmount(double);

	/**
	 * @brief Gets the amount of vertices this circle has
	 * @return The circle's vertices amount
	 * @version 1.0
	 * @since 2.1
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	u32_t getVerticesAmount();

	/**
	 * @brief Gets the amount of indices this circle has
	 * @return The circle's indices amount
	 * @version 1.0
	 * @since 2.1
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	u32_t getIndicesAmount();

public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a brand new 2D circle with the given shaders
	 * @param Circle's smoothness (the lower this number is, the smoother the circle is)
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Circle2D(double smoothness, const char* vertexShader, const char* fragmentShader)
		: Object2D(
			Circle2D::computeVertices(smoothness), Circle2D::computeVerticesAmount(smoothness),
			Circle2D::computeIndices(smoothness), Circle2D::computeIndicesAmount(smoothness),
			vertexShader, fragmentShader
		) {};

	/**
	 * @brief Creates a brand new 2D circle
	 * @param Circle's smoothness (the lower this number is, the smoother the circle is)
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Circle2D(double smoothness)
		: Object2D(
			Circle2D::computeVertices(smoothness), Circle2D::computeVerticesAmount(smoothness), 
			Circle2D::computeIndices(smoothness), Circle2D::computeIndicesAmount(smoothness)
		) {};

	/**
	 * @brief Creates a brand new 2D circle with the given shaders
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Circle2D(const char* vertexShader, const char* fragmentShader) : Circle2D(Circle2D::DEFAULT_SMOOTHNESS, vertexShader, fragmentShader) {};

	/**
	 * @brief Creates a brand new 2D circle
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Circle2D() : Circle2D(Circle2D::DEFAULT_SMOOTHNESS) {};

	// ------------------------------------------------------
	// DESCTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Removes the circle and frees the memory
	 * @version 1.0
	 * @since 2.4
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	~Circle2D();
};