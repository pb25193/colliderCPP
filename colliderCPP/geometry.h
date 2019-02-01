#pragma once


//structs in a 2D world
struct Point
{
	float X, Y;

	Point(float Xin, float Yin);
	Point();

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
float distance(Point pt1, Point pt2);  //distance between 2 points
float distance(Point pt, Line l);   //distance between point and line (perpendicular)

//side checking
bool above(Point pt, Line l);  //point is above line
bool below(Point pt, Line l);  //point is below line
bool on(Point pt, Line l);  //point is on line - this actually doesnt work because of precision issues.

//transforms
Point intersect(Line l1, Line l2); //point of intersection of 2 lines
Point project(Point pt, Line l);  //projection of point on a line
Point interp(Point pt1, Point pt2, float alpha);  // interpolate between points for alpha in 0-1, else extrapolate
Point mirror(Point pt1, Point pt2);  // image of pt1 across pt2
Point mirror(Point pt, Line l); // image of a point across a line
Point midpt(Point pt1, Point pt2); //midpoint of 2 points

Line perpBisect(Point pt1, Point pt2); //perpendicular bisector of 2 points
float eval(Point pt, Line l); // returns y-mx-c for a given line(m,c) and point(x,y). can be used to refactor on, above, and below. but not doing that - for performance reasons.