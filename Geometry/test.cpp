#include <iostream>
#include "geometry.h"

using namespace std;

int main()
{
    Point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int n = sizeof(polygon1)/sizeof(polygon1[0]);
    Point p = {20, 20};
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";
 
    p.x = 5, p.y = 5;
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";
 
    Point polygon2[] = {{0, 0}, {5, 5}, {5, 0}};
    p.x = 3, p.y = 3;
    n = sizeof(polygon2)/sizeof(polygon2[0]);
    isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";
 
    p.x = 5, p.y = 1;
    isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";
 
    p.x = 8, p.y = 1;
    isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";
 
    Point polygon3[] =  {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    p.x = -1,p.y = 1;
    n = sizeof(polygon3)/sizeof(polygon3[0]);
    isInside(polygon3, n, p)? cout << "Yes \n": cout << "No \n";
    return 0;
}