#include "Perceptor.h"


Vector2f Perceptor::dodgeSummator(std::vector<std::pair<Vector2f, float>> input)
{
	float partion = 1.0 / input.size();
	Vector2f result = Vector2f(0, 0);
	//std::cout << "part: " << partion << std::endl;
	for (auto res : input)
	{
		Vector2f direction = res.first;
		float distance = res.second;
		//std::cout << "dir: " << direction.x << " " << direction.y << "dist: " << distance << std::endl;
		result += direction*multDist*partion;
	}
	return result;
}

void Perceptor::Restart()
{
	lastTime = CLOCK.getElapsedTime().asSeconds();
}


const float HIT_RADIUS = 0.42;
Vector2f Perceptor::Process()
{
	aliveTime = CLOCK.getElapsedTime().asSeconds()-lastTime;
	std::vector<Projectile*> hits;
	for (auto prj : globalProjectiles[0])
		if (VectorOperations::GetLength(prj->GetPosition() - position) < HIT_RADIUS)
			hits.push_back(prj);
	if (hits.size() != 0)
	{
		for (auto prj : hits)
		{
			prj->field->RemoveObject(prj);
			delete (prj);
		}
		Restart();
	}
	std::cout << aliveTime << std::endl;
	//(*globalProjectiles[0].begin())->rotation = position - (*globalProjectiles[0].begin())->GetPosition();
	//std::cout << dist << std::endl;
	std::vector<Vector2f> toDodge;
	auto itr = globalProjectiles[0].begin();
	for (int i = 0; i < NEURONS_PER_TASK; i++)
	{
		if (itr != globalProjectiles[0].end())
		{
			toDodge.push_back((*itr)->GetPosition());
			itr++;
		}
		else break;
	}
	if (toDodge.size() != 0)
	{
		std::vector<std::pair<Vector2f, float>> results;
		for (int i = 0; i < toDodge.size(); i++)
		{
			float dist = VectorOperations::Distance(toDodge[i], position);
			auto output = dodge[i].Process(toDodge[i]);
			output = VectorOperations::ReductComponentsToOne(output);
			results.push_back(std::pair<Vector2f, float>(output, dist));
		}
		auto result = dodgeSummator(results);
		//std::cout << result.x << " " << result.y << std::endl;
		return result;
	}
	else return Vector2f(0.1, 0.1);
}

Perceptor::Perceptor(Animation idle_, Animation walk_, Animation shoot_, Animation walkShoot_, Weapon weapon_, float speed_, Field& field_, Vector2f size) :
	Soldier(idle_, walk_, shoot_, walkShoot_, weapon_, speed_, field_, size)
{
	lastTime = CLOCK.getElapsedTime().asSeconds();
	for (int i = 0; i < NEURONS_PER_TASK; i++)
		dodge.emplace_back(DodgeNeuron());
}


Perceptor::~Perceptor()
{
}

void Evolve(Perceptor& ann)
{

}
