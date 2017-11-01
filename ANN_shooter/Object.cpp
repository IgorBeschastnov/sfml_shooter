#include "Object.h"

void Object::Calculate()
{
	float scale = field->GetScale();
	sprite.setPosition(field->WorldToScreenPoint(position));
}

Object::Object(Field & origin, Vector2f size_)
{
	size = size_;
	field = &origin;
	field->AddObject(this);
	float scale = field->GetScale();
	sprite.setScale((size.x / scale)/sprite.getLocalBounds().width, (size.y / scale) / sprite.getLocalBounds().height);
}

Object::~Object()
{
}

Vector2f Object::GetPosition()
{
	return position;
}

void Object::Resize()
{
	float scale = field->GetScale();
	sprite.setScale((size.x / scale) / sprite.getLocalBounds().width, (size.y / scale) / sprite.getLocalBounds().height);
}

//FIFNISHING FIELD CLASS
void Field::HandleObjects()
{
	if (clearOutOfBounds)//TODO part of image visible
	{
		for (auto obj = objects.begin(); obj != objects.end();)
			if (!displayedRect.contains((*obj)->GetPosition()))
			{
				delete(*obj);
				obj = objects.erase(obj);
			}
			else obj++;
	}
	for (auto obj : objects)
	{
		Sprite toDisplay = obj->GetSprite();
		toDisplay.setPosition(toDisplay.getPosition() - WorldToScreenPoint(cameraPosition));
		window->draw(toDisplay);
	}
}
