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

void dfsAP(int v, int parent, bool isAP[], int &timer, bool &AP) {
	visited[v] = true;
	timeIn[v] = low[v] = ++timer;
	int child = 0;
	for(int i=0; i<adj[v].size(); i++) {
		int adjacent = adj[v][i];
		// If the adjacent is the parent in DFS, ignore it
		if(adjacent == parent) {
			continue;
		}
		
		if(!visited[adjacent]) {
			child++;
			dfsAP(adjacent, v, isAP, timer, AP);
			low[v] = min(low[v], low[adjacent]);
			// Condition for v to be articulation point
			if(low[adjacent] >= timeIn[v] && parent != -1) {
				isAP[v] = AP = true;
			}
		}
		else {
			low[v] = min(low[v], timeIn[adjacent]);
		}
	}
	
	// Checking condition of parent node with more than 1 DFS tree children
	if(parent == -1 && child > 1) {
		isAP[v] = AP = true;
	}
}


void articulationPoints() {
	bool isAP[V];
	for(int i=0; i<V; i++) {
		isAP[i] = false;
	}
	int timer=0;
	bool AP=false;
	for(int i=0; i<V; i++) {
		dfsAP(i, -1, isAP, timer, AP);
	}
	
	if(!AP) {
		cout << "No articulation points!" << endl;
	}
	else {
		cout << "Articulation points:" << endl;
		for(int i=0; i<V; i++) {
			if(isAP[i]) {
				cout << i << endl;
			}
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
	articulationPoints();
	
	return 0;	
}
