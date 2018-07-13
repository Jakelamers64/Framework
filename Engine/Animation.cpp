#include "Animation.h"

Animation::Animation(int x, int y, int width, int height, int count,
	const Surface & sprite, float holdTime, Color chroma)
	:
	sprite(sprite),
	holdTime(holdTime),
	chroma(chroma)
{
	for (int i = 0; i < count; ++i)
	{
		frames.emplace_back(x + i * width, x + (i + 1) * width, y, y + height);
	}
}

void Animation::Draw(const Vei2 & pos, Graphics & gfx) const
{
	gfx.DrawSpriteGhost(pos.x, pos.y, frames[iCurFrames], gfx.GetScreenRect(),sprite, chroma);
}

void Animation::Draw(const Vei2 & pos, Graphics & gfx, const RectI & clip) const
{
	gfx.DrawSprite(pos.x, pos.y, frames[iCurFrames], clip, sprite, chroma);
}

void Animation::Update(float dt)
{
	curFrameTime += dt;
	while (curFrameTime >= holdTime)
	{
		Advance();
		curFrameTime -= holdTime;
	}
}

void Animation::Advance()
{
	if (++iCurFrames >= frames.size())
	{
		iCurFrames = 0;
	}
}
