#include <stdio.h>
#include <math.h>

struct point {
	int x;
	int y;
};

int main() {
	struct point p1;
	struct point p2;

	p1.x = 0;
	p1.y = 0;

	p2.x = 3;
	p2.y = 4;

	// Find the distance between the two points.
	double dist = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));

	printf("dist = %f\n", dist);

	return 0;
}


