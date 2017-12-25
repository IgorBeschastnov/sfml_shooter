#pragma once
#include "WorldConstants.h"

static class VectorOperations
{
public:
	static Vector2f ReductComponentsToOne(Vector2f);
	static Vector2f ReductToLength(Vector2f, float);
	static float VectorToRotation(Vector2f);
	static float GetLength(Vector2f);
	static float AngleBetweenVectors(Vector2f, Vector2f);
	static float Distance(Vector2f, Vector2f);
};

