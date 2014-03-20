#pragma once
#include "Point.h"
#include "Color.h"
#include <GL\glut.h>

class Polygon
{
public:
	Polygon(const float r, Point const& c, const int s, const float t, const GLenum _mode, Color const& fc) ;
	void draw() const;
private:
	float radius;
	Point center;
	int numSides;
	float thickness;
	GLenum typeMode;
	Color color;
};

