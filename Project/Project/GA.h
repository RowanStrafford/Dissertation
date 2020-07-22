#pragma once
#include "Model.h"
#include <vector>

class GA
{
public:
	GA();
	~GA();

	void SetInputModel(Model* model);
	void GenerateInitialPopulation();
	void DisplayPopulation();
	// Selection of population
	void Crossover();
	void Mutation();
private:
	std::vector<Model*> m_vPopulation;
};

