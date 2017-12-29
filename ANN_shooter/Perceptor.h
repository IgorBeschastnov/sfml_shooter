#pragma once
#include "Soldier.h"
#include "Neuron.h"
#include <array>
#include "VectorOperations.h"
class Perceptor :
	public Soldier
{
	const int NEURONS_PER_TASK = 7;
	float multAngle = 0;//TODO
	float multDist = 1;
	float aliveTime;
	float lastTime;
	std::vector<DodgeNeuron> dodge;
	Vector2f dodgeSummator(std::vector<std::pair<Vector2f, float>>);
	//std::vector <Neuron<float>> player;
	void Restart();
	friend void Evolve(Perceptor& ann);
public:
	Vector2f Process();
	Perceptor(Animation, Animation, Animation, Animation, Weapon, float, Field&, Vector2f);
	~Perceptor();
};

