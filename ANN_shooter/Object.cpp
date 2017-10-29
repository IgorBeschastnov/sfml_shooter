#include "Object.h"

void Object::Calculate()
{
	float scale = field->GetScale();
	auto size = field->GetWindow()->getSize();
	std::cout << position.x << "" << position.y << std::endl;
	sprite.setPosition(position/scale);
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

void Object::Resize()
{
	float scale = field->GetScale();
	sprite.setScale((size.x / scale) / sprite.getLocalBounds().width, (size.y / scale) / sprite.getLocalBounds().height);
}

//FIFNISHING FIELD CLASS
void Field::HandleObjects()
{
	for (auto obj : objects)
		window->draw(obj->GetSprite());
}
