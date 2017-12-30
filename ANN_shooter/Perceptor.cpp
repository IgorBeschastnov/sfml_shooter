#include "Perceptor.h"


Vector2f Perceptor::dodgeSummator(std::vector<std::tuple<Vector2f, float, float>> input)
{
	float partion = 1.0 / input.size();
	std::vector<float> distances;
	for (auto res : input) 
	{
		distances.push_back(std::get<1>(res));
	}
	float max_dist = *std::max_element(distances.begin(), distances.end());
	Vector2f result = Vector2f(0, 0);
	//std::cout << "part: " << partion << std::endl;
	for (auto res : input)
	{
		float angle = std::get<2>(res);
		Vector2f direction = std::get<0>(res);
		float distancePart = std::get<1>(res)/max_dist;
		result += direction*(angle/multAngle)*(distancePart/multDist)*partion;
	}
	//std::cout << result.x << " " << result.y << std::endl;
	return result;
}

struct Result
{
	float time;
	float multAngle;
	float multDist;

	Result(float time_, float multAngle_, float multDist_)
	{
		time = time_;
		multAngle = multAngle_;
		multDist = multDist_;
	}
};

const int EVOLVE_COUNT = 7;
int evolves = 1;
std::vector<Result> results;
static bool res_compare(Result a, Result b)
{
	return (a.time < b.time);
}
void Perceptor::Restart()
{
	std::cout << "ERA: " << evolves << ", step: " << results.size() << std::endl;
	results.emplace_back(aliveTime, multAngle, multDist);
	//std::cout << results[results.size()-1].multAngle << " " << results[results.size()-1].time << std::endl;
	lastTime = CLOCK.getElapsedTime().asSeconds();
	if (results.size() < EVOLVE_COUNT)
	{
		float distMin = (multDist - (multDist - multDistBound.first) / evolves) * 100.0;
		int distMax = int((multDist + (multDistBound.second - multDist) / evolves) * 100.0);
		//std::cout << distMin << " " << distMax << std::endl;
		multDist = (distMin + rand() % distMax)/100.0;
		multAngle = (multAngle - (multAngle - multAngleBound.first) / evolves) + rand() % int((multAngle + (multAngleBound.second - multAngle) / evolves));
	}
	else
	{
		evolves++;
		Result max_r = *std::max_element(results.begin(), results.end(), res_compare);
		results.clear();
		multDist = max_r.multDist;
		multAngle = max_r.multAngle;
	}
	//std::cout << multDist << " " << multAngle << std::endl;
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
		return Vector2f(0, 0);
	}
	//std::cout << aliveTime << std::endl;
	//(*globalProjectiles[0].begin())->rotation = position - (*globalProjectiles[0].begin())->GetPosition();
	//std::cout << dist << std::endl;
	std::vector<Vector2f> toDodge;
	std::vector<Vector2f> toDodgePos;
	auto itr = globalProjectiles[0].begin();
	for (int i = 0; i < NEURONS_PER_TASK; i++)
	{
	again:
		if (itr != globalProjectiles[0].end())
		{
			//std::cout << VectorOperations::AngleBetweenVectors((*itr)->GetRotation(), position - (*itr)->GetPosition()) << std::endl;
			if (VectorOperations::AngleBetweenVectors((*itr)->GetRotation(), position - (*itr)->GetPosition()) < 90)
			{
				//std::cout << "do" << std::endl;
				toDodge.push_back((*itr)->GetRotation());
				toDodgePos.push_back((*itr)->GetPosition());
				itr++;
			}
			else
			{
				itr++;
				goto again;
			}
		}
		else break;
	}
	if (toDodge.size() != 0)
	{
		std::vector<std::tuple<Vector2f, float, float>> results;
		for (int i = 0; i < toDodge.size(); i++)
		{
			float dist = VectorOperations::Distance(toDodgePos[i], position);
			auto output = dodge[i].Process(toDodge[i]);
			output = VectorOperations::ReductComponentsToOne(output);
			if (VectorOperations::AngleBetweenVectors(position - toDodgePos[i], output) > 90)
				output = -output;
			results.push_back(std::tuple<Vector2f, float, float>(output, dist, VectorOperations::AngleBetweenVectors(position - toDodgePos[i], toDodge[i])));
		}
		auto result = dodgeSummator(results);
		//std::cout << result.x << " " << result.y << std::endl;
		return result;
	}
	else return Vector2f(0,0);
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
