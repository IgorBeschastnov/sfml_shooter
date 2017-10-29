#include "Field.h"


Field::Field(float scale_, RenderWindow& window_, Texture* background_, Vector2f backSize_)
{
	window = &window_;
	scale = scale_;
	background = background_;
	backSize = backSize_;
}

bool Field::AddObject(Object * object)
{
	if (std::find(objects.begin(), objects.end(), object) == objects.end())
	{
		objects.push_back(object);
		return true;
	}
	else
		return false;
}

float Field::GetScale() const
{
	return scale;
}

const RenderWindow * Field::GetWindow()
{
	return window;
}

Field::~Field()
{
}
