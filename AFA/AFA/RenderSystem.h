#pragma once
#include "stdafx.h"
#include "CameraSystem.h"

/// <summary>
/// This struct contains a SDL_Rect and a Color variables.
/// </summary>

struct Box
{
	SDL_Rect rect;
	SDL_Color color;

	/// <summary>
	/// Default constructor
	/// </summary>
	Box()
	{
		rect = SDL_Rect{ 0, 0, 0, 0 };
		color = SDL_Color{ 0, 0, 0, 0 };
	}
};

class RenderSystem
{
private:
	static SDL_Renderer * m_renderer;
	static SDL_Window * m_window;

public:
	RenderSystem();
	~RenderSystem();

	/// <summary>
	/// An initialiser function to initialise the window and
	/// renderer.
	/// </summary>
	/// <param name="title">string variable to determine the title of the window.</param>
	/// <param name="x">int variable determining window x pos on screen. Defaults to center.</param>
	/// <param name="y">int variable determining window y pos on screen. Defaults to center.</param>
	/// <param name="w">int determines width of window. Defaults to 762.</param>
	/// <param name="h">int determines height of window. Defaults to 762.</param>
	static bool Init(string title = "Game", int x = 0, int y = 0, int w = 768, int h = 896);

	/// <summary>
	/// A static getter function to return a ptr.
	/// </summary>
	/// <returns>SDL_Renderer ptr</returns>
	static SDL_Renderer * Renderer();

	/// <summary>
	/// This method sets the clear colour of the screen.
	/// </summary>
	/// <param name="Color">SDL_Color variable determining clear color.</param>
	static void RenderColor(SDL_Color Color);

	/// <summary>
	/// This method clears the screen.
	/// </summary>
	static void Clear();

	/// <summary>
	/// This method will be used to draw a texture with no rotation.
	/// </summary>
	/// <param name="Texture">SDL_Texture ptr of the texture to render.</param>
	/// <param name="DstRect">SDL_Rect defining parameters on screen.</param>
	static void Draw(SDL_Texture * Texture, SDL_Rect DstRect);

	/// <summary>
	/// This method will be used to draw a simple rect.
	/// </summary>
	/// <param name="DstRect">SDL_Rect defining parameters on screen.</param>
	static void Draw(SDL_Rect DstRect);

	/// <summary>
	/// This method will be used to draw a texture with no rotation.
	/// </summary>
	/// <param name="Texture">SDL_Texture ptr of the texture to render.</param>
	/// <param name="SrcRect">SDL_Rect defining parameters of the image.</param>
	/// <param name="DstRect">SDL_Rect defining parameters on screen.</param>
	static void Draw(SDL_Texture * Texture, SDL_Rect SrcRect, SDL_Rect DstRect);

	/// <summary>
	/// This method will be used to draw a rectangle.
	/// </summary>
	/// <param name="box"></param>
	static void Draw(Box * box);

	/// <summary>
	/// This method will be used to draw a texture with rotation around the center of the image.
	/// </summary>
	/// <param name="Texture">SDL_Texture ptr of the texture to render.</param>
	/// <param name="SrcRect">SDL_Rect defining parameters of the image.</param>
	/// <param name="DstRect">SDL_Rect defining parameters on screen.</param>
	/// <param name="Rotation">float defining rotation of texture</param>
	static void Draw(SDL_Texture * Texture, SDL_Rect SrcRect, SDL_Rect DstRect, float Rotation);

	/// <summary>
	/// This method will be used to draw a texture with rotation around a given point.
	/// </summary>
	/// <param name="Texture">SDL_Texture ptr of the texture to render.</param>
	/// <param name="SrcRect">SDL_Rect defining parameters of the image.</param>
	/// <param name="DstRect">SDL_Rect defining parameters on screen.</param>
	/// <param name="Rotation">float defining rotation of texture</param>
	/// <param name="Origin">SDL_Point defining the point of rotation</param>
	static void Draw(SDL_Texture * Texture, SDL_Rect SrcRect, SDL_Rect DstRect, float Rotation, SDL_Point Origin);

	/// <summary>
	/// This method presents information of the renderer.
	/// </summary>
	static void Present();
};