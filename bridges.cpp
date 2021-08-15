#include<bits/stdc++.h>
using namespace std;

int V;
vector<int> *adj;
bool *visited;
int *timeIn;
int *low;

void insertEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void bridgeDFS(int v, int parent, int &timer) {
	visited[v] = true;
	timeIn[v] = low[v] = ++timer;
	
	for(int i=0; i<adj[v].size(); i++) {
		int adjacent = adj[v][i];
		// If the adjacent is the parent in DFS, ignore it
		if(adjacent == parent) {
			continue;
		}
		
		// If adjacent is unvisited, do DFS of it and update low of current vertex
		if(!visited[adjacent]) {
			bridgeDFS(adjacent, v, timer);
			low[v] = min(low[v], low[adjacent]);
			
			// Condition for bridge
			if(low[adjacent] > timeIn[v]) {
				cout << "Bridge: " << v << " --- " << adjacent << endl;
			}			
		}
		
		// If adjacent is visited, simply update low as lowest between low of this vertex and time of adjacent 
		else {
			low[v] = min(low[v], timeIn[adjacent]);
		}
	}
}

void bridges() {
	int timer = 0;
	for(int i=0; i<V; i++) {
		if(!visited[i]) {
			bridgeDFS(i, -1, timer);
		}
	}
}

int main() {
	cout << "Enter no. of nodes: ";
	cin >> V; 
	adj = new vector<int>[V];
	visited = new bool[V];

	for(int i=0; i<V; i++) {
		visited[i] = false;
	}
	
	timeIn = new int[V];
	low = new int[V];
	
	int u, v;
	while(u!=-1) {
		cout << "Enter edge from and to (-1 to stop): ";
		cin >> u >> v;
		if(u!=-1 && v!=-1) {
			insertEdge(u, v);
		}
	}
	bridges();
	
	return 0;	
}
