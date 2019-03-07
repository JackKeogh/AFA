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
		m_volume(20), m_current(0)
	{
		Mix_VolumeMusic(m_volume);
	};

	/// <summary>
	/// ~SoundSystem
	/// 
	/// Default destructor for the sound system object.
	/// </summary>
	~SoundSystem();

	/// <summary>
	/// Update
	/// 
	/// This function updates the sound system.
	/// </summary>
	void Update();

	/// <summary>
	/// Add Music
	/// 
	/// This function adds music to the track list.
	/// </summary>
	/// <param name="track">Mix_Chunk pointer to the music.</param>
	void addMusic(Mix_Music * track);

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

	/// <summary>
	/// Set Volume
	/// 
	/// This function sets the volume to a specific value.
	/// </summary>
	void setVolume(int vol);

private:
	vector<Mix_Music *> m_track;
	int m_volume;
	int m_current;
};