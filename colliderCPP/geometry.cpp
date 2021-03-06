#include <iostream>
#include <cmath>


#include "geometry.h"

//constructors

////Points
Point::Point(float Xin, float Yin) {
	X = Xin;
	Y = Yin;
}
Point::Point( ) {}

////Lines
Line::Line(float slope, float intercept) {
	m = slope;
	c = intercept;
}
Line::Line(Point pt1, Point pt2) {
	m = (pt2.Y - pt1.Y) / (pt2.X - pt1.X);
	c = pt2.Y - m * pt2.X;
}
Line::Line(float slope, Point pt) {
	m = slope;
	c = pt.Y - m * pt.X;
}

//class methods *****WARNING***** There will be errors when vertical 
//				*****WARNING***** lines are conjured by helper functions

////Lines
void Line::print() {
	printf("I am a line with slope %f, and y intercept %f", m, c);
	std::cout << std::endl;
}
void Line::move(float dx, float dy) {
	c += dy - m * dx;
}
void Line::move(Point pt) {
	c += pt.Y - m * pt.X;
}
void Line::movePerp(float d) {
	c += d * sqrt(1 + pow(m, 2));
}
void Line::rotate(float theta, Point pivot) {
	Line newLine = Line(m, c);
	newLine.move(-pivot.X, -pivot.Y);
	newLine.rotateByOrigin(theta);
	newLine.move(pivot);
	m = newLine.m;
	c = newLine.c;
}
void Line::rotateByOrigin(float theta) {
	float newSlope = rotateSlope(theta);
	Point projection = project(Point(0, 0), Line(m, c));
	projection.rotateByOrigin(theta);
	Line newLine = Line(newSlope, projection);
	m = newLine.m;
	c = newLine.c;
}
float Line::rotateSlope(float theta) {
	float radTheta = M_PI * theta / 180;
	float t = tan(radTheta);
	float newSlope = (m + t) / (1 - m * t);
	return newSlope;
}
////Points
void Point::print() {
	printf("X : %f, Y : %f", X, Y);
	std::cout << std::endl;
}
void Point::move(float dx, float dy) {
	X += dx;
	Y += dy;
}
void Point::move(Point dp) {
	X += dp.X;
	Y += dp.Y;
}
void Point::rotateByOrigin(float theta) {
	float radTheta = M_PI * theta / 180;
	float s = sin(radTheta);
	float c = cos(radTheta);
	float newX = X * c - Y * s;
	float newY = X * s + Y * c;
	X = newX;
	Y = newY;
}
//Geometric functions
float distance(Point pt1, Point pt2) {
	float vert = pt2.Y - pt1.Y;
	float hori = pt2.X - pt1.X;
	float distance = sqrt(vert * vert + hori * hori);
	return distance;
}
float distance(Point pt, Line l) {
	float y = pt.Y;
	float x = pt.X;
	float m = l.m;
	float c = l.c;

	return abs(y - m * x - c) / sqrt(1 + m * m);
}
bool above(Point pt, Line l) {
	return (pt.Y - l.m*pt.X - l.c > 0);
}
bool below(Point pt, Line l) {
	return (pt.Y - l.m*pt.X - l.c < 0);
}
bool on(Point pt, Line l) {
	return (pt.Y - l.m*pt.X - l.c == 0);
}
Point intersect(Line l1, Line l2) {
	if (l1.m == l2.m) {
		return Point();
	}
	float x = (l1.c - l2.c) / (l2.m - l1.m);
	float y = l1.m*x + l1.c;
	return Point(x, y);
}
Point project(Point pt, Line l) {
	return intersect(Line((-1 / l.m), pt), l);
}
Point interp(Point pt1, Point pt2, float alpha) {
	return Point((alpha*pt2.X + (1 - alpha)*pt1.X), (alpha*pt2.Y + (1 - alpha)*pt1.Y));
}
Point mirror(Point pt1, Point pt2) {
	return interp(pt1, pt2, 2);
}
Point mirror(Point pt, Line l) {
	return mirror(pt, project(pt, l));
}
Point midpt(Point pt1, Point pt2) {
	return interp(pt1, pt2, 0.5);
}
Line perpBisect(Point pt1, Point pt2) {
	return Line((pt1.X - pt2.X) / (pt2.Y - pt1.Y), midpt(pt1, pt2));
}
float eval(Point pt, Line l) {
	return (pt.Y - l.m * pt.X - l.c);
}