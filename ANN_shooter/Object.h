#pragma once
#include "WorldConstants.h"
#include "Field.h"
class Object
{
protected:
	Field* field;
	Sprite sprite;
	Vector2f size;
	Vector2f position;
	Vector2f rotation;
	virtual void Calculate();

	Object(Field&, Vector2f);
public:
	Vector2f GetPosition();
	virtual Sprite GetSprite() = 0;
	void Resize();
	virtual ~Object();
};

