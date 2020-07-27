#pragma once
#include "Cube.h"
#include "Shader.h"

#include <vector>

class GA
{
public:
	GA();
	~GA();

	void SetInputModel(Cube* model);
	void GenerateInitialPopulation(int populationSize);
	void DisplayPopulation(Shader* shader);
	// Selection of population
	void Crossover();
	void Mutation();
private:
	std::vector<Cube*> m_vPopulation;
	Cube* m_inputModel;
	int m_populationSize;
};

