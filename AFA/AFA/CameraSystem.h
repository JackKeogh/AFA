/// <summary>
/// This class will be used as a camera system.
/// </summary>

#pragma once
#include "stdafx.h"

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
	static bool Initialiser(int w, int h);

	/// <summary>
	/// Update
	/// 
	/// This function will be used to update the camera
	/// to follow an entity.
	/// </summary>
	/// <param name="e">Entity to follow.</param>
	static void Update(float px);

	/// <summary>
	/// Reset
	/// 
	/// This function will be used to reset the camera
	/// to its original position.
	/// </summary>
	static void Reset();

	/// <summary>
	/// Camera
	/// 
	/// This is a getter function to return the camera's
	/// rectangle
	/// </summary>
	static SDL_Rect Camera() { return m_camera; };

private:
	static SDL_Rect m_camera;
};