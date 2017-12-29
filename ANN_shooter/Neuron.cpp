#pragma once
#include "Neuron.h"

Vector2f DodgeNeuron::ActivationFunc(Vector2f inp) const
{
	return Vector2f(-inp.y, inp.x);
}

DodgeNeuron::DodgeNeuron()
{}

Vector2f DodgeNeuron::Process(Vector2f input) const
{
	return ActivationFunc(input);
}

DodgeNeuron::~DodgeNeuron()
{
}