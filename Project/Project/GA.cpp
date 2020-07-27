#include "GA.h"



GA::GA()
{
}


GA::~GA()
{
}

void GA::SetInputModel(Cube* model)
{
	m_inputModel = model;
}

void GA::GenerateInitialPopulation(int populationSize)
{
	m_populationSize = populationSize;

	for (unsigned int i = 0; i < m_populationSize; i++)
	{
		Cube* newCube = new Cube(glm::vec3(i, 0, 0), glm::vec3(0.3f, 0.3f, 0.3f), glm::vec3(1.0f, 0.3f, 0.5f));
		m_vPopulation.push_back(newCube);
	}
}

void GA::DisplayPopulation(Shader* shader)
{
	for (unsigned int i = 0; i < m_populationSize; i++)
	{
		m_vPopulation[i]->Draw(shader);
	}
}

void GA::Crossover()
{
	// Loop through population and repeatedly produce new offspring
}

void GA::Mutation()
{
	// Simply loop through new population and mutate each member random num < mutationRate
}


