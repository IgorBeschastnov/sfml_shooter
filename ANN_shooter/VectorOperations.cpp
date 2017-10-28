#include "VectorOperations.h"

Vector2f VectorOperations::ReductComponentsToOne(Vector2f vector)
{
	Vector2f direction = vector;
	float maxComp = std::max<float>(abs(direction.x), abs(direction.y));
	direction.x = direction.x / maxComp;
	direction.y = direction.y / maxComp;
	return direction;
}

Vector2f VectorOperations::ReductToLength(Vector2f vector, float length)
{
	Vector2f direction = vector;
	float divSum = GetLength(direction);
	divSum = length / divSum;
	direction.x = direction.x * divSum;
	direction.y = direction.y * divSum;
	return direction;
}

float VectorOperations::VectorToRotation(Vector2f direction)
{
	float scalar = direction.x*originDirection.x + direction.y*originDirection.y;
	float lengths = GetLength(originDirection)*GetLength(direction);
	float angle = acos(scalar / lengths)*180/(3.14);
	if (direction.y < 0)
		angle += (180 - angle) * 2;
	return angle;
}

float VectorOperations::GetLength(Vector2f vector)
{
	float length = sqrt(abs(vector.x)*abs(vector.x) + abs(vector.y)*abs(vector.y));
	return length;
}
