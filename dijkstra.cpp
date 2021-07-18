#include<bits/stdc++.h>
using namespace std;

int V;
int **adj;
bool *visited;
//int *parent;

void insertEdge(int u, int v, int w) {
	adj[u][v] = w;
//	adj[v][u] = w;
}

void dijkstra(int s=0) {
	int dist[V];
	bool spt[V];
	for(int i=0; i<V; i++) {
		dist[i] = INT_MAX;
		spt[i] = false;
	}
	
	dist[s] = 0;

	for(int i=0; i<V; i++) {
		int m = INT_MAX, u;
		for(int j=0; j<V; j++) {
			if(!spt[j] && dist[j] < m) {
				m = dist[j];
				u = j;
			}
		}
		spt[u] = true;
		
		for(int j=0; j<V; j++) {
			if(adj[u][j]!=0 && !spt[j]) {
				if(dist[j] > dist[u] + adj[u][j]) {
					dist[j] = dist[u] + adj[u][j];
				}
			}
		}
	}
	
	for(int i=0; i<V; i++) {
		cout << dist[i] << " ";
	}
}

int main() {
	cout << "Enter no. of nodes: ";
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
	visited = new bool[V];


	for(int i=0; i<V; i++) {
		visited[i] = false;
	}
	
	int u, v, w;
	while(u!=-1) {
		cout << "Enter edge from, to and weight (enter either as -1 to stop entering edges): ";
		cin >> u >> v >> w;
		if(u!=-1 && v!=-1) {
			insertEdge(u, v, w);
		}
	}
	
//	for(int i=0; i<V; i++) {
//		for(int j=0; j<V; j++) {
//			cout << adj[i][j] << " ";
//		}
//		cout << endl;
//	}
	int s;
	cout << "Enter source: ";
	cin >> s;
	dijkstra(s);
	
	return 0;	
}
