#include <iostream>
#include <cmath>

#include "geometry.h"



void Log(const char* message) {
	std::cout << message << std::endl;
}

void Log(const float message) {
	std::cout << message << std::endl;
}

void proceed() {
	Log("press enter to continue...");
	std::cin.get();
}

void testGeometry(){
	Point P = Point(2, 3);
	Point Q = Point(7, 5);
	while (true) {
		Line L = Line(P, Q);
		Line M = perpBisect(P, Q);
		Log("P and Q are 2 points, we will look at some of their properties today");
		P.print();
		Q.print();

		proceed();

		Log("L joins P, Q and M is the perp bisector. Printing both, along with their intersection. It should match the midpoint value.");
		L.print();
		M.print();
		intersect(L, M).print();
		Log("");
		proceed();

		Log("testing interpolation: P and Q with alpha=0.6");
		interp(P, Q, 0.6).print();
		Log("");
		proceed();

		Log("testing midpoint between P and Q");
		midpt(P, Q).print();
		Log("");
		proceed();

		Log("testing mirrorring of P across Q");
		mirror(P, Q).print();
		Log("");
		proceed();

		Log("moving P by Q...");
		P.move(Q);
		P.print();
		proceed();

		Log("now P has been translated by Q, let us see where it is projecting on L and M");
		Log("projecting the new P upon M");
		project(P, M).print();
		proceed();
		Log("distance from old midpoint?");
		Log(distance(project(P, M), intersect(L, M)));
		proceed();
		Log("now projecting the new P upon L");
		project(P, L).print();
		proceed();
		Log("distance from old midpoint?");
		Log(distance(project(P, L), intersect(L, M)));
		proceed();

		Log("Is P above L? 1 means yes, 0 means no.");
		std::cout << above(P, L) << std::endl;
		proceed();

		Log("Is P below M? 1 means yes, 0 means no.");
		std::cout << below(P, M) << std::endl;
		proceed();

		Log("Is P's mirror across L above L? 1 means yes, 0 means no.");
		std::cout << above(mirror(P, L), L) << std::endl;
		proceed();

		Log("Is P's mirror across M below M? 1 means yes, 0 means no.");
		std::cout << below(mirror(P, M), M) << std::endl;
		proceed();

		Log("Sanity check for mirroring function: midpoint of P and P's mirror across M should lie on M, and same goes for L");
		Log("printing the bools corresponding to both, both should be 1");
		std::cout << on(midpt(P, mirror(P, L)), L) << std::endl;
		std::cout << on(midpt(P, mirror(P, M)), M) << std::endl;
		Log("");
		proceed();

		Log("appears that the result is wrong. Let us dive deeper");
		Log("we will evaluate the lines at the midpoints now:");
		Log("doing this for L first:");
		Log(eval(midpt(P, mirror(P, L)), L));
		Log("now doing it for M:");
		Log(eval(midpt(P, mirror(P, L)), L));
		Log("");
		proceed();

		Log("the float precision is not allowing on to evaluate at 0. we may later introduce a tolerance. or pass it as a parameter. There is room for improvement in the on function.");
		Log("The study is over. Now that P has been updated, you may repeat the study on the new value of P. Press enter to do so, or hit the cross to exit.");

		std::cin.get();
	}
}

int main() {
	//testGeometry();
	Line A = Line(1, 3);
	A.print();
	A.rotate(90);
	A.print();
	proceed();
}