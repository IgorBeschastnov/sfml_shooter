#pragma once
#include "General.h"
class Object;

class Field
{
	std::list<Object*> objects;
	float scale;
	Texture* background;
	Vector2f backSize;
	RenderWindow* window;
public:
	Field(float, RenderWindow&, Texture* = nullptr, Vector2f= Vector2f(0,0));
	void HandleObjects();
	bool AddObject(Object*);
	float GetScale() const;
	const RenderWindow* GetWindow();
	~Field();
};

