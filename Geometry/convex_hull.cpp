#include "convex_hull.h"
#include <stack>
#include <cstdlib>
#include <iostream>

using namespace std;

Point p0;

void swapPoint(Point &p, Point &q){
	Point temp = p;
	p = q;
	q = temp;
}

void comparePointPolorAngle(void *vp_p, void *vp_q){
	Point *p = (Point *)vp_p;
	Point *q = (Point *)vp_q;

	int o = orientation(p0, *p, *q);
	// if p0, p, q are colinear, compare their distance to p0
	if(o == 0) return calculateSquareDistance(p0, *p) < calculateSquareDistance(p0, *q) ? -1 : 1;
	return o == 2 ? -1 : 1; // if p0, p, q are counterclockwise, p will be near to p0 than q
}

Point nextToTop(stack<Point> &s){
	Point top = s.top();
	s.pop();
	Point result = s.top();
	s.push(top);

	return result;
}

void convexHull(Point points[], int n){
	int ymin = points[0].y;
	int bottomMostIndex = 0;

	for(int i = 1; i < n; ++i){
		if(ymin > points[i].y || 
			(ymin == points[i].y && points[bottomMostIndex].x > points[i].x)){
			ymin = points[i].y;
			bottomMostIndex = i;
		}
	}

	swapPoint(points[bottomMostIndex], points[0]); // now bottom most is at 0
	p0 = points[0];

	qsort(&point[1], n - 1, sizeof(Point), comparePointPolorAngle); // sort all point from 1 to n

	int newArraySize = 1; // include p0
	for(int i = 1; i < n; ++i){
		while(i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0) ++i; // if they have same angle, keep the last (farthest)
		points[newArraySize++] = points[i]; // keep the farthest
	}

	if(newArraySize < 3) return; // no polygon has < 2 vertices

	stack<Point> s;
	s.push(points[0]);
	s.push(points[1]);
	s.push(points[2]);

	for(int i = 3; i < newArraySize; ++i){
		while(orientation(nextToTop(s), s.top(), points[i]) != 2) s.pop(); // while they nextToTop, top, point-i are not counterclockwise, remove top
		s.push(points[i]);
	} 

	// print the result

	while(!s.empty()){
		Point top = s.top();
		cout << top.x << " " << top.y << endl;
		s.pop();
	}
}