#pragma once
#include "Helper.h"
#include <vector>

//Global settings
//initial screen size
const unsigned int SCR_WIDTH = 100 * 16;//WIDTH
const unsigned int SCR_HEIGHT = 100 * 9;//HEIGHT


// timing
double deltaTime = 0.0f;	// time between current frame and last frame
double lastFrame = 0.0f;

GLFWwindow* CreateWindow()
{

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "TerrainGeneration", NULL, NULL);

	// GLFW WINDOW CREATION
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return nullptr;
	}

	glfwMakeContextCurrent(window);
	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//RETURN WINDOW
	return window;
}