#pragma once
#include "General.h"
#include "Field.h"
class Object
{
private:
	Field* field;
protected:
	Sprite sprite;
	Vector2f size;
	Vector2f position;
	Vector2f rotation;
	virtual void Calculate();

	Object(Field&, Vector2f);
	~Object();
public:
	virtual Sprite GetSprite() = 0;
	void Resize();
};

