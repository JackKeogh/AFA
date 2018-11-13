/// <summary>
/// This class will be used as a camera system.
/// </summary>

#pragma once
#include "stdafx.h"
#include <ECS.h>

class CameraSystem
{
public:
	/// <summary>
	/// CameraSystem
	/// 
	/// Default constructor of the object.
	/// </summary>
	CameraSystem();

	/// <summary>
	/// ~CameraSystem
	/// 
	/// Default deconstructor of the object.
	/// </summary>
	~CameraSystem();

	/// <summary>
	/// Initialiser
	/// 
	/// This function is to initialise the camera system.
	/// </summary>
	static void Initialiser();

	/// <summary>
	/// Update
	/// 
	/// This function will be used to update the camera
	/// to follow an entity.
	/// </summary>
	/// <param name="e">Entity to follow.</param>
	static void Update(jk::Entity * e);

private:
	static SDL_Rect m_camera;
};