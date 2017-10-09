typedef struct {
	int x;
	int y;
} Point;

int orientation(Point p, Point q, Point r);
bool onSegment(Point p, Point q, Point r);
bool doIntersect(Point p1, Point q1, Point p2, Point q2);
bool isInside(Point polygon[], int n, Point p);