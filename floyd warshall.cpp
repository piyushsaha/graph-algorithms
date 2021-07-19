#include<bits/stdc++.h>
using namespace std;

int **adj;
int V;

void addEdge(int u, int v, int w) {
	adj[u][v] = w;
}

void floydWarshall() {
	int dist[V][V];
	// Initialising the distance matrix
	for(int i=0; i<V; i++) {
		for(int j=0; j<V; j++) {
			// Shortest distance from a vertex to itself is 0 
			if(i==j) {
				dist[i][j] = 0;
			}
			// Adding the edge length of adjacent vertices
			else if(adj[i][j] != 0) {
				dist[i][j] = adj[i][j];
			}
			// Initialise distance between non adjacent vertices as infinity
			else {
				dist[i][j] = INT_MAX;
			}
		}
	}
	
	for(int k=0; k<V; k++) {
		for(int i=0; i<V; i++) {
			for(int j=0; j<V; j++) {
				// Before comparing i -> j via with i -> k -> j, make sure i -> k and k -> j is not infinity
				if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
					continue;
				}
				// Relax the cost to reach i -> j
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	// Detecting negative weight cycle
	/* If the shortest distance from a vertex to itself is less than 0,
	the given graph contains a negative cycle. */ 
	for(int i=0; i<V; i++) {
		if(dist[i][i] < 0) {
			cout << "Negative cycle in graph!" << endl;
			return;
		}		
	}
	
	cout << "From\tTo\tDistance" << endl;
	for(int i=0; i<V; i++) {
		for(int j=0; j<V; j++) {
			cout << i << "\t" << j << "\t" << dist[i][j] << endl;
		}
	}
}

int main() {
	cout << "Enter no. of vertices: ";
	cin >> V;
	adj = new int*[V];
	for(int i=0; i<V; i++) {
		adj[i] = new int[V];
	}
	for(int i=0; i<V; i++) {
		for(int j=0; j<V; j++) {
			adj[i][j] = 0;
		}
	}
	
	int u, v, w;
	while(u != -1) {
		cout << "Enter edge from, to and weight: ";
		cin >> u >> v >> w;
		if(u!=-1)
			addEdge(u, v, w);
	}
	
	floydWarshall();
	
	// Releasing dynamically aallocated memory
	for(int i=0; i<V; i++) {
		delete [] adj[i];
	}
	delete [] adj;
		
}
