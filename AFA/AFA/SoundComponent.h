#pragma once
#include "stdafx.h"
#include <ECS.h>

class SoundComponent : public jk::Component
{
public:
	SoundComponent()
	{

	}
	
	void PlaySound(string tag)
	{
		AssetHandler * temp = AssetHandler::getInstance();
		Mix_PlayChannel(-1, temp->getSound(tag), 0);
	}

	void PlaySound(string tag, int Channel)
	{
		AssetHandler * temp = AssetHandler::getInstance();
		if (!Mix_Playing(Channel))
		{
			Mix_PlayChannel(Channel, temp->getSound(tag), 0);
		}
	}

private:
	
};