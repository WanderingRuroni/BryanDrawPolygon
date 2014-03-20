#include "Polygon.h"
#include <math.h>
#include <GL\glut.h>

#define PI 3.14159

Polygon::Polygon(const float r, Point const& c, const int s, const float t, const GLenum _mode, Color const& fc) :
				 radius(r), center(c), numSides(s), thickness(t), typeMode(_mode), color(fc)
{
}


void Polygon::draw() const {
	// set color of the polygon - same for all right now
	glColor3f(color.r, color.g, color.b);
	// if the polygon is tagged as hollow, you will draw GL_LINE_LOOP
	// Otherwise use GL_POLYGON

	float angle;
	// set the desired line thickness of the polygon
	glLineWidth(thickness);
	// GLenum is set by the variable passed into Polygon so it can be hollow or not
	glBegin(typeMode);
		// places the beginning vertex of the polygon to be drawn
		glVertex3f((center.x + radius), center.y, center.z);

		// loop through the other vertices of the polygon based on the number of sides
		for( int i = 1; i < numSides; i++)
		{
			// calculate the angle at which the vertex will be placed.
			angle = (2 * PI * i) / numSides;
			glVertex3f((center.x + radius*cos(angle)), (center.y + radius*sin(angle)), center.z);
		}

		// place a vertex back at the first point to close the polygon
		glVertex3f((center.x + radius), center.y, center.z);
	glEnd();

	// not sure of the exact reason, but the gl drawing calls here will not work inside of an
	// if statement
	/*if(hollow) {
		glLineWidth(thickness);
		glBegin(GL_LINE_LOOP);
			glVertex3f((center.x + radius), center.y, center.z);

			for( int i = 1; i < numSides; i++)
			{
				angle = (2 * PI * numSides) / numSides;
				glVertex3f(center.x + radius*cos(angle), center.y + radius*sin(angle), center.z);
			}

			glVertex3f((center.x + radius), center.y, center.z);
		glEnd();
	}
	else {
		glBegin(GL_POLYGON);
			glVertex3f((center.x + radius), center.y, center.z);

			for(int j = 1; j < numSides; j++)
			{
				angle = (2 * PI * numSides) / numSides;
				glVertex3f(center.x + radius*cos(angle), center.y + radius*sin(angle), center.z);
			}

			glVertex3f((center.x + radius), center.y, center.z);
		glEnd();
	}*/
}
