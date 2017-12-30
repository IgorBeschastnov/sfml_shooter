#pragma once
#include "Soldier.h"
#include "Neuron.h"
#include <array>
#include "VectorOperations.h"
class Perceptor :
	public Soldier
{
	const int NEURONS_PER_TASK = 7;
	float multAngle = 15;
	float multDist = 0.5;
	std::pair<int, int> multAngleBound = std::pair<int, int>(1, 30);
	std::pair<int, int> multDistBound = std::pair<int, int>(0, 1);
	float aliveTime;
	float lastTime;
	std::vector<DodgeNeuron> dodge;
	Vector2f dodgeSummator(std::vector<std::tuple<Vector2f, float, float>>);
	//std::vector <Neuron<float>> player;
	void Restart();
public:
	Vector2f Process();
	Perceptor(Animation, Animation, Animation, Animation, Weapon, float, Field&, Vector2f);
	~Perceptor();
};

