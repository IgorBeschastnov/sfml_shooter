#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

using namespace sf;

struct SpriteList
{
	Texture atlas;
	int frameHeight;
	int frameWidth;
	int rows;
	std::vector<int> framesPerRow;
	SpriteList(Texture source_, int width_, int height_, int rows_, std::vector<int> perRow_)
	{
		atlas = source_;
		frameHeight = height_;
		frameWidth = width_;
		rows = rows_;
		framesPerRow = perRow_;
	}
};

