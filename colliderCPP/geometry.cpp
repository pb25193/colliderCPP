#include <iostream>
#include <cmath>
#include "geometry.h"


Point::Point(float Xin, float Yin) {
	X = Xin;
	Y = Yin;
}

float l2norm(Point pt1, Point pt2) {
	float vert = pt2.Y - pt1.Y;
	float hori = pt2.X - pt1.X;
	float distance = sqrt(vert * vert + hori * hori);
	return distance;
}


float l2norm(Point pt1, int pt2) {
	return (float) pt2;
}
