/// <summary>
/// This class will act as a sound system. It will store multiple tracks and
/// cycle through them. The music will be looped.
/// </summary>

#pragma once
#include "stdafx.h"

class SoundSystem
{
public:
	/// <summary>
	/// SoundSystem
	/// 
	/// Default constructor for the sound system object.
	/// </summary>
	SoundSystem() :
		m_volume(100)
	{
	};

	/// <summary>
	/// ~SoundSystem
	/// 
	/// Default destructor for the sound system object.
	/// </summary>
	~SoundSystem();

	/// <summary>
	/// Add Sound
	/// 
	/// This function adds music to the track list.
	/// </summary>
	/// <param name="sound">Mix_Chunk pointer to the music.</param>
	void addSound(Mix_Chunk * track);

	/// <summary>
	/// Play
	/// 
	/// This function plays the music.
	/// </summary>
	void play();

	/// <summary>
	/// Pause
	/// 
	/// This function pauses the music.
	/// </summary>
	void pause();

	/// <summary>
	/// Stop
	/// 
	/// This function stops the music.
	/// </summary>
	void stop();

	/// <summary>
	/// Decrease Volume
	/// 
	/// This function decreases the volume.
	/// </summary>
	void decreaseVolume();

	/// <summary>
	/// Increase Volume
	/// 
	/// This function increases the volume.
	/// </summary>
	void increaseVolume();

private:
	vector<Mix_Chunk *> m_track;
	int m_volume;
};