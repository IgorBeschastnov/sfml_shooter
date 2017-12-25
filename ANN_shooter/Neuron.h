#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
using namespace sf;

class DodgeNeuron
{
private:
	Vector2f ActivationFunc(Vector2f) const;
public:
	DodgeNeuron();
	Vector2f Process(Vector2f) const;
	~DodgeNeuron();
};