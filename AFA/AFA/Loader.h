#pragma once
#include "stdafx.h"
#include "AssetHandler.h"
#include "RenderSystem.h"
#include "JSON.h"
#include "JSONValue.h"

class Loader
{
public:
	Loader()
	{
	}

	bool Load(const char * location, const char * level)
	{
		if (!OpenFile(location))
		{
			return false;
		}

		m_value = JSON::Parse(m_data.c_str());

		if (m_value == NULL)
		{
			cout << "Failed to parse information from data." << endl;
			return false;
		}

		wstring current = string_to_wstring(level);

		if (!LoadSprites(current))
		{
			cout << "Failed to load sprites" << endl;
		}

		return true;
	}
	wstring string_to_wstring(string obj)
	{
		return wstring(obj.begin(), obj.end());
	}
	string wstring_to_string(wstring obj)
	{
		return string(obj.begin(), obj.end());
	}

private:
	JSONValue * m_value;
	string m_data;

	bool OpenFile(const char * location)
	{
		// Clear existing data
		m_data.clear();

		// Create in stream and string for each line
		ifstream file;
		string line;

		// Open File
		file.open(location, ifstream::in);

		if (file.is_open())
		{
			// Append line information to the data
			while (file >> line)
			{
				m_data.append(line);
			}

			file.close();
		}
		else
		{
			// Return false if file cannot be opened.
			cout << "Could not open file." << endl;
			return false;
		}

		return true;
	}
	JSONObject getTopLevelJSONObject()
	{
		JSONObject root;

		if (m_value->IsObject() == false)
		{
			throw std::exception("Problem with root element in json file, exiting");
		}

		root = m_value->AsObject();

		return root;
	}
	bool LoadSprites(wstring level)
	{
		// Get Asset Handler
		AssetHandler * assets = AssetHandler::getInstance();

		// Get root of Object
		JSONObject root = getTopLevelJSONObject();

		// Navigate to chosen level
		JSONObject gameData = root[L"Levels"]->AsObject();
		JSONObject levelObj = gameData[level]->AsObject();

		// Get Array of sprites
		JSONArray sprites = levelObj[L"Sprites"]->AsArray();

		if (sprites.size() == 0)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < sprites.size(); i++)
			{
				JSONObject obj = sprites[i]->AsObject();

				string tag = wstring_to_string(obj[L"Tag"]->AsString());
				string location = wstring_to_string(obj[L"Location"]->AsString());

				assets->addTexture(tag, location, RenderSystem::Renderer());
			}
		}


		return true;
	}
};