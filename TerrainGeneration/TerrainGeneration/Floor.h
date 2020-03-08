#pragma once
#include "Helper.h"
#include "Shader.h"

unsigned int floorVAO = 0;
unsigned int floorVBO;
float floorVertices[] = {
	// positions        // texcoords
	5.0f, -0.5f,  5.0f, 1.0f, 0.0f,
	-5.0f, -0.5f,  5.0f, 0.0f, 0.0f,
	-5.0f, -0.5f, -5.0f,  0.0f, 1.0f,

	5.0f, -0.5f,  5.0f, 1.0f, 0.0f,
	-5.0f, -0.5f, -5.0f,  0.0f, 1.0f,
	5.0f, -0.5f, -5.0f,  1.0f, 1.0f,
};

Shader FloorShader()
{
	glGenVertexArrays(1, &floorVAO);
	glGenBuffers(1, &floorVBO);
	glBindVertexArray(floorVAO);
	glBindBuffer(GL_ARRAY_BUFFER, floorVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(floorVertices), floorVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

	Shader floorShader("floor.vs", "floor.fs");
	floorShader.SetInt("texture1", 0);

	return floorShader;
}
