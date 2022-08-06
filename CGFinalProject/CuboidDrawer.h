#pragma once
#include <GL/glut.h>
#pragma once
#include "MaterialStruct.h"

void drawCuboid(double a, double b, double c,
	double x, double y, double z,
	MaterialStruct color);

void drawCuboid(double a, double b, double c,
	double x, double y, double z,
	MaterialStruct color,
	double theta,
	double nx, double ny, double nz);