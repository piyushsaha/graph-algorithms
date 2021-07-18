#include<bits/stdc++.h>
using namespace std;

int V;
int **adj;
bool *visited;
//int *parent;

void insertEdge(int u, int v, int w) {
	adj[u][v] = w;
	adj[v][u] = w;
}

void prims_MST() {
	int key[V];
	bool mstSet[V];
	int parent[V];
	for(int i=0; i<V; i++) {
		key[i] = INT_MAX;
		mstSet[i] = false;
		parent[i] = 0;
	}
	int res = 0;
	key[0] = 0;
	parent[0] = -1;
	for(int i=0; i<V; i++) {
		
		// Picking lowest key vertex from vertices not in MST
		int m = INT_MAX, u;
		for(int j=0; j<V; j++) {
			if(!mstSet[j] && key[j] < m) {
				m = key[j];
				u = j;
			}
		}
		
		// Adding it to MST and adding it's key to result
		mstSet[u] = true;
		res += key[u];
		
		// Updating the keys of adjacent nodes if they can connect through u in smaller weight
		for(int v=0; v<V; v++) {
			if(adj[u][v]!=0 && !mstSet[v]) {
//				key[v] = min(key[v], adj[u][v]);
				if(key[v] > adj[u][v]) {
					parent[v] = u;
					key[v] = adj[u][v];
				}
			}
		}
	}
	
	cout << "MST weight: " << res << endl;
	for(int i=0; i<V; i++) {
		cout << i << "--" << parent[i] << ": " << adj[i][parent[i]] << endl;
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
	
	for(int i=0; i<V; i++) {
		for(int j=0; j<V; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
	
	prims_MST();
	
	return 0;	
}
