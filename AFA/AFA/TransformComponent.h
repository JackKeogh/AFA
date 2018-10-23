/// <summary>
/// This component will handle the coordinates,
/// scale and velocity of an enitity.
/// </summary>
/// 
#pragma once
#include "stdafx.h"
#include <ECS.h>
#include <Vector2.h>

using namespace jk;

class TransformComponent : public Component
{
public:
	Vector2f position;
	Vector2f velocity;
	Vector2f acceleration;

	int MaxAccel;
	int width;
	int height;
	int scale;
	float speed;
	bool in_air;
	float jumpSpeed;
	float rotation;

	/// <summary>
	/// Overload contructor for transform component. All values
	/// will default to 0.
	/// </summary>
	/// <param name="p">Vector2f for position coords.</param>
	/// <param name="w">int to determine width.</param>
	/// <param name="h">int to determine height.</param>
	/// <param name="r">float to determine rotation.</param>
	/// <param name="s">int to determine scale.</param>
	/// <param name="v">int to determine speed.</param>
	/// <param name="a">int to determine max acceleration.</param>
	TransformComponent(Vector2f p = Vector2f(0, 0), int w = 0, int h = 0, float r = 0, int s = 1, int v = 0, int a = 0) :
		position(p),
		width(w),
		height(h),
		rotation(r),
		scale(s),
		speed(v),
		MaxAccel(a)
	{
		acceleration = Vector2f(0, 0);
		in_air = false;
	}

	/// <summary>
	/// Used to initialise the Transform Component
	/// </summary>
	void Init() override
	{
		velocity = Vector2f(0, 0);
	}

	/// <summary>
	/// Get Velocity
	/// 
	/// This is a getter function for velocity.
	/// </summary>
	/// <returns>A vector2f value for velocity.</returns>
	Vector2f getVelocity() { return velocity; }

	/// <summary>
	/// Get Position
	/// 
	/// This is a getter function for position.
	/// </summary>
	/// <returns>A vector2f value for position.</returns>
	Vector2f getPosition() { return position; }

	/// <summary>
	/// Set Position
	/// 
	/// This is a setter function for position.
	/// </summary>
	/// <param name="value">A vector2f value to set position to.</param>
	void setPosition(Vector2f value) { position = value; }

	/// <summary>
	/// Set Velocity
	/// 
	/// This is a setter function for velocity.
	/// </summary>
	/// <param name="value">A vector2f value to set velocity to.</param>
	void setVelocity(Vector2f value) { velocity = value; }

	/// <summary>
	/// Set Acceleration
	/// 
	/// This is a setter function for acceleration.
	/// </summary>
	/// <param name="value">A vector2f value to set acceleration to.</param>
	void setAcceleration(Vector2f value) { acceleration = value; }
};