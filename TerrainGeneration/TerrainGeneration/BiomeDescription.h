#ifndef BIOMEDESCRIPTION_H
#define BIOMEDESCRIPTION_H

#define BIOMESN 5

#include "Helper.h"

enum BiomeType : int {
	PLAIN = 0, MOUNTAIN = 1, WATER = 2, DESERT = 3, CANYON = 4

};

struct BiomeValues {
	double bFrequence;
	int bOctaves;
	glm::vec3 minColor;
	glm::vec3 midColor;
	glm::vec3 maxColor;

};

glm::vec3 rgbTransform(glm::vec3 inrgb) {
	return glm::vec3(inrgb.r / 255.0, inrgb.g / 255.0, inrgb.b / 255.0);
}

BiomeValues getTheBiomeDescription(BiomeType pbt) {


	BiomeValues descrip;
	//--------------------------------------------------------------------------PLAINS
	if (pbt == PLAIN) {
		descrip.bFrequence = 10.0;
		descrip.bOctaves = 4;
		descrip.minColor = rgbTransform(glm::vec3(0.0f, 100.0f, 0.0f));
		descrip.midColor = rgbTransform(glm::vec3(3.0f, 192.0f, 60.0f));
		descrip.maxColor = rgbTransform(glm::vec3(102.0f, 255.0f, 0.0f));//(143,188,143)*/

	}
	else if (pbt == MOUNTAIN) {//------------------------------------------------MOUNTAINS
		descrip.bFrequence = 38.0;
		descrip.bOctaves = 20;
		descrip.minColor = rgbTransform(glm::vec3(79.0, 58.0, 60.0));
		descrip.midColor = rgbTransform(glm::vec3(101.0, 67.0, 33.0));
		descrip.maxColor = rgbTransform(glm::vec3(160.0f, 120.0f, 90.0f));


	}
	else if (pbt == WATER) {//--------------------------------------------------VALLEY
		descrip.bFrequence = -1.0;
		descrip.bOctaves = 8;
		descrip.minColor = rgbTransform(glm::vec3(16.0, 52.0, 166.0));
		descrip.midColor = rgbTransform(glm::vec3(225.0, 169.0, 95.0));
		descrip.maxColor = rgbTransform(glm::vec3(74.0, 93.0, 35.0));


	}
	else if (pbt == DESERT) {//--------------------------------------------------DESERT
		descrip.bFrequence = 6.0;
		descrip.bOctaves = 2;
		descrip.minColor = rgbTransform(glm::vec3(125, 249, 255));
		descrip.midColor = rgbTransform(glm::vec3(244, 164, 96));
		descrip.maxColor = rgbTransform(glm::vec3(255, 255, 255));

	}
	else if (pbt == CANYON) {//-------------------------------------------------CANYONS
		descrip.bFrequence = 6.0;
		descrip.bOctaves = 4;
		descrip.minColor = rgbTransform(glm::vec3(1, 50, 32));
		descrip.midColor = rgbTransform(glm::vec3(4.0, 99.0, 7.0));
		descrip.maxColor = rgbTransform(glm::vec3(233.0, 105.0, 44.0));


	}

	return descrip;
}

#endif
