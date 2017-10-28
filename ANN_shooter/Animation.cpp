#include "Animation.h"

SpriteList * Animation::GetSpriteList()
{
	return list;
}

Animation::Animation(SpriteList* list_, int row_, float speed_)
{
	cycle = true;
	list = list_;
	row = row_;
	framesPerSecond = speed_;
	lastTime = CLOCK.getElapsedTime().asSeconds();
	rect.top = list->frameHeight*row;
	rect.height = list->frameHeight;
	rect.width = list->frameWidth;
}

void Animation::Start()
{
	cycle = true;
}

void Animation::Stop()
{
	cycle = false;
}

IntRect Animation::GetRect()//TODO
{
	if (cycle)
	{
		int tempFrame = (CLOCK.getElapsedTime().asSeconds() - lastTime) / (1 / framesPerSecond);
		tempFrame = tempFrame % (list->framesPerRow[row]);
		rect.left = tempFrame*list->frameWidth;
	}
	return rect;
}


Animation::~Animation()
{
}
