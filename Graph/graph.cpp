#include <iostream>
#include "graph.h"

Graph::Graph(int V) {
	this->V = V;
	adjList = new list<Vertex>[V];
}

void Graph::addEdge(int u, int v, int weight) {
	Vertex newNode(v, weight);
	adjList[u].push_back(newNode);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &s) {
	visited[v] = true;

	list<Vertex> :: iterator it;
	for (it = adjList[v].begin(); it != adjList[v].end(); ++it) {
		if (!visited[it->getV()])
			topologicalSortUtil(it->getV(), visited, s);
	}
	s.push(v);
}

void Graph::longestPath(int s) {
	stack<int> st;
	bool *visited = new bool[V];

	memset(visited, 0, sizeof(bool) * V);

	for (int i = 0; i < V; ++i)
		if (!visited[i])
			topologicalSortUtil(i, visited, st);

	int dist[V];
	for (int i = 0; i < V; ++i) dist[i] = NINF;
	dist[s] = 0;

	while (!st.empty()) {
		int u = st.top();
		st.pop();

		list<Vertex>:: iterator it;
		if (dist[u] != NINF) {
			for (it = adjList[u].begin(); it != adjList[u].end(); ++it) {
				if (dist[it->getV()] < dist[u] + it->getWeight())
					dist[it->getV()] = dist[u] + it->getWeight();
			}
		}

	}

	for (int i = 0; i < V; ++i) {
		if (dist[i] == NINF) cout << "INF ";
		else cout << dist[i] << " ";
	}

}