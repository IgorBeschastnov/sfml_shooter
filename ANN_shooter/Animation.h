#pragma once
#include "WorldConstants.h"
#include "SpriteList.h"

class Animation
{
protected:
	SpriteList* list;
	bool cycle;
	int row;
	float framesPerSecond;
	float lastTime;
	IntRect rect;
public:
	SpriteList* GetSpriteList();
	Animation(SpriteList*, int, float);
	Animation() = default;
	void Start();
	void Stop();
	IntRect GetRect();
	~Animation();
};

