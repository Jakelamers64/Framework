#pragma once
#include "Graphics.h"
#include "Surface.h"
#include "Vec2.h"

class Font
{
public:
	Font(const std::string& filename, Color chroma = Colors::White);
	void DrawText(const std::string & text, const Vei2 pos, Graphics & gfx, Color color = Colors::White) const;
private:
	RectI MapGlyphRect(char c) const;
private:
	//holds font sheet bitmap data
	Surface surface;
	//this gives dimensions of a glyph in the font sheet
	int glyphWidth;
	int glyphHeight;
	//number of rows / columns in the font sheet this is fixed
	static constexpr int nColumns = 32;
	static constexpr int nRows = 3;
	//font sheet chroma color
	Color chroma;
	//start and end drawable char codes
	static constexpr char firstChar = ' ';
	static constexpr char lastChar = '~';
};