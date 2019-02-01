#pragma once


//structs in a 2D world
struct Point
{
	float X, Y;

	Point(float Xin, float Yin);

	void print();
	void move(float dx, float dy);
	void move(Point dp);
};

struct Line
{
	float m, c;

	Line(float slope, float intercept);
	Line(Point pt1, Point pt2);
	Line(float slope, Point pt);

	void print();
};

//distance evaluators
float distance(Point pt1, Point pt2);
float distance(Point pt, Line l);

//side checking
bool above(Point pt, Line l);  //point is above line
bool below(Point pt, Line l);  //point is below line
bool on(Point pt, Line l);  //point is on line

//transforms
Point intersect(Line l1, Line l2);
Point project(Point pt, Line l);
Point interp(Point pt1, Point pt2, float alpha);
Point mirror(Point pt1, Point pt2);
Point mirror(Point pt, Line l);
Point midpt(Point pt1, Point pt2);

Line perpBisect(Point pt1, Point pt2);
float eval(Point pt, Line l);