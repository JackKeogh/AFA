/// <summary>
/// AssetHandler
/// 
/// An external library that works with the SDL2.0 image, mixer
/// and font libraries. The library will be used to load and store
/// textures, sounds and fonts. This is to prevent multiples of the
/// same file continously being loaded in and causing memory leaks.
/// It is a singleton class so that there will only ever be one
/// instance of the class.
/// </summary>
/// <author> Jack Keogh </author>

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class AssetHandler
{
public:
	/// <summary>
	/// getInstance
	/// 
	/// Checks if an instance of the asset handler exists and creates one
	/// if it doesn't. 
	/// </summary>
	/// <returns>A ptr to the instance of the asset handler.</returns>
	static AssetHandler * getInstance()
	{
		if (!m_instance)
		{
			m_instance = new AssetHandler;
		}

		return m_instance;
	}

	/// <summary>
	/// addTexture
	/// 
	/// Loads in a SDL_Texture ptr and stores it.
	/// </summary>
	/// <param name="tag">A tag to reference the texture later.</param>
	/// <param name="filepath">The location of the desired image.</param>
	/// <param name="renderer">SDL_Renderer used to load in the image.</param>
	void addTexture(string tag, string filepath, SDL_Renderer * renderer);

	/// <summary>
	/// getTexture
	/// 
	/// Used to retreive a ptr to a specific texture.
	/// </summary>
	/// <param name="tag">A string value of the desired texture.</param>
	/// <returns>A SDL_Texture ptr.</returns>
	SDL_Texture * getTexture(string tag);

	/// <summary>
	/// addSound
	/// 
	/// Loads in a Mix_Chunk ptr and stores it.
	/// </summary>
	/// <param name="tag">A tag to reference the sound later.</param>
	/// <param name="filepath">The location of the desired sound.</param>
	void addSound(string tag, string filepath);

	/// <summary>
	/// getSound
	/// 
	/// Used to retrevie a ptr of a specific sound.
	/// </summary>
	/// <param name="tag">A string value of the desired sound.</param>
	/// <returns>A Mix_Chunk ptr.</returns>
	Mix_Chunk * getSound(string tag);

	/// <summary>
	/// addMusic
	/// 
	/// Loads in a Mix_Music ptr and stores it.
	/// </summary>
	/// <param name="tag">A tag to reference the track later.</param>
	/// <param name="filepath">The location of the desired track.</param>
	void addMusic(string tag, string filepath);

	/// <summary>
	/// getMusic
	/// 
	/// Used to retrevie a ptr of a specific music track.
	/// </summary>
	/// <param name="tag">A string value of the desired track.</param>
	/// <returns>A Mix_Music ptr.</returns>
	Mix_Music * getMusic(string tag);

	/// <summary>
	/// addFont
	/// 
	/// Loads in a TTF_Font ptr and stores it.
	/// </summary>
	/// <param name="tag">A tag to reference the font later.</param>
	/// <param name="filepath">The location of the desired font.</param>
	/// <param name="size">The size of the desired font.</param>
	void addFont(string tag, string filepath, int size);

	/// <summary>
	/// getFont
	/// 
	/// Used to retrevie a ptr of a specific font.
	/// </summary>
	/// <param name="tag">A string value of the desired font.</param>
	/// <returns>A TTF_Font ptr.</returns>
	TTF_Font * getFont(string tag);

	/// <summary>
	/// ClearTextures
	/// 
	/// Clears the AssetHandler of all SDL_Texture ptrs.
	/// </summary>
	void ClearTextures();

	/// <summary>
	/// ClearSounds
	/// 
	/// Clears the AssetHandler of all Mix_Chunk ptrs.
	/// </summary>
	void ClearSounds();

	/// <summary>
	/// ClearSounds
	/// 
	/// Clears the AssetHandler of all Mix_Chunk ptrs.
	/// </summary>
	void ClearMusic();

	/// <summary>
	/// ClearFonts
	/// 
	/// Clears the AssetHandler of all TTF_Font ptrs.
	/// </summary>
	void ClearFonts();

	/// <summary>
	/// Clear
	/// 
	/// Clears the AssetHandler of all SDL_Texture, Mix_Chunk and
	/// TTF_Font ptrs.
	/// </summary>
	void Clear();

private:
	AssetHandler()
	{
		m_textures = map<string, SDL_Texture*>();
		m_sounds = map<string, Mix_Chunk*>();
		m_fonts = map<string, TTF_Font*>();
		m_tracks = map<string, Mix_Music*>();
	}

	static AssetHandler * m_instance;

	map<string, SDL_Texture*> m_textures;
	map<string, Mix_Chunk*> m_sounds;
	map<string, Mix_Music*> m_tracks;
	map<string, TTF_Font*> m_fonts;
};