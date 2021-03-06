#pragma once

#include "Soil.h"
#include <string>
#include <iostream>
#include "GLFW/glfw3.h"

using namespace std;

class Texture {
public:

	Texture();
	Texture(int _id);
	Texture(string path);

	int getID();
	int getWidth();
	int getHeight();

private:

	int id, width, height;

	bool getTextureParams();

};