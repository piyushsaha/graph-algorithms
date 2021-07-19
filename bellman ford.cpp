#include<bits/stdc++.h>
using namespace std;

int V, E;
int *dist;
struct Edge {
	int src, dest, w;
	Edge(int s, int d, int _w) {
		src = s;
		dest = d;
		w = _w;
	}
};
Edge **Edges;

void bellmanFord(int s=0) {
	dist = new int[V];
	for(int i=0; i<V; i++) {
		dist[i] = INT_MAX;
	}
	
	dist[s] = 0;
	
	// Relaxing every edge for V-1 times
	for(int i=0; i<V-1; i++) {
		// Relaxing all edges
		for(int j=0; j<E; j++) {
			Edge *e = Edges[j];
			if(dist[e->src]!= INT_MAX) {
				if(dist[e->dest] > dist[e->src] + e->w) {
					dist[e->dest] = dist[e->src] + e->w;
				}
				
			}
		}
		
	}
	
	// Relaxing one more time to detect negative cycle
	for(int j=0; j<E; j++) {
		Edge *e = Edges[j];
		if(dist[e->src]!= INT_MAX) {
			if(dist[e->dest] > dist[e->src] + e->w) {
				cout << "Negative cycle exists!" << endl;
				return;
			}
		}
	}
	
	// Printing the distances if no negative cycle exists
	for(int i=0; i<V; i++) {
		cout << "Distance of " << i << " from source: " << dist[i] << endl;
	}
	
	
}

int main() {
	cout << "Enter no. of vertices: ";
	cin >> V;
	cout << "Enter no. of edges: ";
	cin >> E;
	
	Edges = new Edge*[E];
	int u, v, w;
	for(int i=0; i<E; i++) {
		cout << "Enter source, destination and weight :";
		cin >> u >> v >> w;
		Edges[i] = new Edge(u, v, w);
	}
	
	
	bellmanFord();
	
	
	for(int i=0; i<E; i++) {
		delete [] Edges[i];	
	}
	delete [] Edges;
	
	
	
	return 0;
}
