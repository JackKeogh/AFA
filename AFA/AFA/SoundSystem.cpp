#include "SoundSystem.h"

SoundSystem::~SoundSystem()
{
	for (int i = 0; i < m_track.size(); i++)
	{
		Mix_FreeMusic(m_track.at(i));
	}

	m_track.clear();
}

void SoundSystem::addSound(Mix_Music * track)
{
	m_track.push_back(track);
}

void SoundSystem::play()
{
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(m_track.at(m_current), 0);
	}
}

void SoundSystem::pause()
{
	Mix_PauseMusic();
}

void SoundSystem::stop()
{
	Mix_HaltMusic();
}

void SoundSystem::decreaseVolume()
{
	m_volume--;
	Mix_VolumeMusic(m_volume);
}

void SoundSystem::increaseVolume()
{
	m_volume++;
	Mix_VolumeMusic(m_volume);
}

void SoundSystem::setVolume(int vol)
{
	m_volume = vol;
	Mix_VolumeMusic(m_volume);
}


