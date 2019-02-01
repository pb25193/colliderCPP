#include <iostream>
#include <cmath>


#include "geometry.h"

//constructors

////Points
Point::Point(float Xin, float Yin) {
	X = Xin;
	Y = Yin;
}
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

//class methods

////Lines
void Line::print() {
	printf("I am a line with slope %f, and y intercept %f", m, c);
	std::cout << std::endl;
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