#pragma once

#include <vector>

#include "alvironment/GenericObject.h"

#include "math/Vector3D.h"
#include "math/Quaternion.h"

#include "../Camera.h"

/**
 * @brief Class for creating 3D objects
 * @version 2.1
 * @date 2026-09-07
 * @author Álvaro Fernández Barrero
 */
class Object3D : public GenericObject
{
private:
	Vector3D scale = Vector3D::one;
	Vector3D position = Vector3D::zero;
	Quaternion rotation = Quaternion::identity;

	Camera* camera = nullptr;

	u32_t* actualIndices;
	u32_t actualIndicesAmount = 0;

	std::vector<u32_t> indicesToRenderVector;
	std::vector<double> depthVertices;

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Updates the object's indices according to the transformed vertices
	 * @version 1.0
	 * @since 1.3
	 * @date 2026-09-08
	 * @author Álvaro Fernández Barrero
	 */
	void updateIndices();

	/**
	 * @brief Checks if the given z coordinate from a vertex is within the frustrum's limits
	 * @param Vertex's z axis
	 * @return True if the z axis is within the camera's frustrum, false otherwise
	 * @version 1.0
	 * @since 1.3
	 * @date 2026-09-08
	 * @author Álvaro Fernández Barrero
	 */
	bool isVertexZWithinFrustrum(float);

	/**
	 * @brief Sets up the indices list
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-09-09
	 * @author Álvaro Fernández Barrero
	 */
	inline void setUpIndicesList();

public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a brand new 3D object with the given vertices, indices and shaders
	 * @param Vertices's positions list
	 * @param Vertices amount
	 * @param Indices's list
	 * @param Indices amount
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @param Texture's path
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-09-10
	 * @author Álvaro Fernández Barrero
	 */
	Object3D(float*, u32_t, u32_t*, u32_t, const char*, const char*, const char*);

	/**
	 * @brief Creates a brand new 3D object with the given vertices, indices and shaders
	 * @param Vertices's positions list
	 * @param Vertices amount
	 * @param Indices's list
	 * @param Indices amount
	 * @param Texture's path
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-09-10
	 * @author Álvaro Fernández Barrero
	 */
	Object3D(float*, u32_t, u32_t*, u32_t, const char*);

	/**
	 * @brief Creates a brand new 3D object with the given vertices, indices and shaders
	 * @param Vertices's positions list
	 * @param Vertices amount
	 * @param Indices's list
	 * @param Indices amount
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Object3D(float*, u32_t, u32_t*, u32_t, const char*, const char*);

	/**
	 * @brief Creates a brand new 3D object with the given vertices, indices and shaders
	 * @param Vertices' positions list
	 * @param Indices' list
	 * @version 1.1
	 * @since 2.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Object3D(float*, u32_t, u32_t*, u32_t);

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Updates the object's vertices according to the transformation evolved
	 * @version 2.6
	 * @since 1.4
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void updateVertices() override;

	/**
	 * @brief Gets the scale of the object
	 * @return The object's scale
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Vector3D getScale() const;

	/**
	 * @brief Sets the scale of the object
	 * @param The new object's scale
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setScale(const Vector3D&);

	/**
	 * @brief Gets the position of the object
	 * @return The object's position
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Vector3D getPosition() const;

	/**
	 * @brief Sets the position of the object
	 * @param The new object's position
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setPosition(const Vector3D&);

	/**
	 * @brief Gets the rotation of the object
	 * @return The object's rotation
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Quaternion getRotation() const;

	/**
	 * @brief Sets the rotation of the object
	 * @param The new object's rotation
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setRotation(const Quaternion&);

	/**
	 * @brief Sets the camera that is going to view the object
	 * @param Camera that is going to view the object
	 * @version 1.0
	 * @since 1.1
	 * @date 2026-09-08
	 * @author Álvaro Fernández Barrero
	 */
	void setCamera(Camera*);
};