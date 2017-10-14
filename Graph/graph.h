#include <stack>
#include <list>
#include <limits.h>

#define NINF INT_MIN

using namespace std;

class Vertex {
	int val;
	int weight;
public:
	Vertex(int v, int w) {val = v; weight = w; }
	int getV() { return val; }
	int getWeight() { return weight; }
};

class Graph {
	int V;
	list<Vertex> *adjList;
	void topologicalSortUtil(int v, bool visited[], stack<int> &s);
public:
	Graph(int V);
	void addEdge(int u, int v, int weight); // add edge uv
	void longestPath(int s); // longest path from source
};