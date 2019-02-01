#pragma once


struct Point
{
	float X, Y;

	Point(float Xin, float Yin);
};

float l2norm(Point pt1, Point pt2);


float l2norm(Point pt1, int pt2);