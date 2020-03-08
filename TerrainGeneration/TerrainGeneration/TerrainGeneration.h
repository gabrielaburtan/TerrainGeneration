#ifndef TERRAINGEN_H
#define TERRAINGEN_H

#include "Terrain.h"
#include "Shader.h"
#include "Helper.h"


class TerrainGen {
private:
	unsigned int seed, chunkSize;
	float vertexInterval;
	unsigned int biomeSize, borderLen;
	Shader sProgram;
public:
	Terrain* terrain;

	TerrainGen(unsigned int pSeed, unsigned int psp) :sProgram(psp) {
		this->seed = pSeed;
		this->vertexInterval = 0.5;
		this->chunkSize = 1024 * 2;
		this->biomeSize = 512;
		this->borderLen = 64;
		terrain = new Terrain(this->seed, this->vertexInterval, this->chunkSize, this->chunkSize / 2.0f * -1.0f, this->chunkSize / 2.0f * -1.0f, this->biomeSize, this->borderLen);
	}
	void drawTerrain()
	{
		this->sProgram.Use();
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, terrain->getInitialXZ());
		this->sProgram.SetMat4("model", model);
		terrain->Draw();
	}
	void rebuild(glm::vec3 cpos)
	{
		double offsetxz = this->chunkSize / 2.0;

	}

	void shutDown()
	{
		terrain->shutDown();
	}

};
#endif