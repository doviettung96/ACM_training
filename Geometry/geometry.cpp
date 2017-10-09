#include <iostream>
#include "geometry.h"

#define INF 10000

using namespace std;

// The orientation of the triplet(p, q, r)
// 0: colinear
// 1: clockwise
// 2: counter clockwise
int orientation(Point p, Point q, Point r) {
	int crossProduct = (q.x - p.x) * (r.y - q.y) - (r.x - q.x) * (q.y - p.y);
	if (crossProduct == 0) return 0;
	return crossProduct < 0 ? 1 : 2;
}

// whether q is on pr segment or not
bool onSegment(Point p, Point q, Point r) {
	return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
	       q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q2, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4) return true; // p1, q1 are orientally different, as well as p2, q2
	if (o1 == 0 && onSegment(p1, p2, q1)) return true; // p2 is on p1q1
	if (o2 == 0 && onSegment(p1, q2, q1)) return true; // q2 is on p1q1
	if (o3 == 0 && onSegment(p2, p1, q2)) return true; // p1 is on p2q2
	if (o4 == 0 && onSegment(p2, q1, q2)) return true; // q1 is on p2q2

	return false;
}

// whether p is inside the n-polygon or not
bool isInside(Point polygon[], int n, Point p) {
	if (n < 3) return false;

	int nIntersections = 0;
	Point infinitePoint = {INF, p.y};
	for (int i = 0; i < n; ++i) {
		int next = (i + 1) % n;
		if (doIntersect(p, infinitePoint, polygon[i], polygon[next])) {
			if (orientation(polygon[i],  polygon[next], p) == 0) return onSegment(polygon[i], p, polygon[next]);
			++nIntersections;
		}
	}
	return nIntersections % 2 == 1;
}