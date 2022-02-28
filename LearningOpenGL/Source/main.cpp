#include "Application.h"
#include "Sample/Triangle.h"
#include "Sample/TextureSample.h"

#include <iostream>

USE_LEARN_OPENGL

int main()
{
	// FTriangle Sample(800, 600, "Triangle Sample");
	FTextureSample Sample(800, 600, "Texture Sample");
	FApplication::Run(Sample);
	return 0;
}