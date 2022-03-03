#include "Application.h"
#include "Sample/Triangle.h"
#include "Sample/TextureSample.h"
#include "Sample/CameraSample.h"

#include <iostream>

USE_LEARN_OPENGL

int main()
{
	// FTriangle Sample(800, 600, "Triangle Sample");
	// FTextureSample Sample(800, 600, "Texture Sample");
	FCameraSample Sample(1157, 1265, "Camera Sample");
	FApplication::Run(Sample);
	return 0;
}