#pragma once

#include <deque>
#include <string>

#include "Sprite.h"
#include "label.h"
#include "Math/Vector4.h"

namespace talga
{
	const int LUA_DEBUG_MAX_LINES = 1000;
	const int LUA_DEBUG_BORDER = 5;
	class LuaDebugPrompt : public Sprite
	{
	public:
		LuaDebugPrompt(cpTex mainBody, cpFont font);
		virtual ~LuaDebugPrompt();
		
		virtual void render(Renderer* renderer, const Camera* camera) const override;

		void print(const std::string& line);
	protected:
		std::deque<std::string> mTextLines;
		std::deque<std::string>::iterator mStartAt;
		cpFont mFont;
		vec4 mColor;
		size_t mMaxVisibleLines;
		size_t mMaxLinePixelWidth;
		I32 borderSize;
	};

}