#pragma once
#include "stdafx.h"
#include <ECS.h>

class TagComponent : public jk::Component
{
public:
	/// <summary>
	/// TagComponent
	/// 
	/// Overload constructor for the Tag
	/// Component.
	/// </summary>
	/// <param name="tag">String value to be assigned to the tag.</param>
	TagComponent(string tag)
	{
		m_tag = tag;
	}

	/// <summary>
	/// Get Tag
	/// 
	/// Returns the string value of the tag.
	/// </summary>
	string getTag() { return m_tag; };

private:
	string m_tag;
};