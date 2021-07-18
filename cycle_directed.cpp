#include<bits/stdc++.h>
using namespace std;

int V;
vector<int> *adj;
//char *labels;
bool *visited;
int *parent;

void insertEdge(int u, int v) {
	adj[u].push_back(v);
	// Because egdes are directed from u to v
//	adj[v].push_back(u);
}


bool DFSCycle(int s, int recStack[]) {
	visited[s] = true;
	recStack[s] = true;
	
	for(int a=0; a<adj[s].size(); a++) {
		int adjacent = adj[s][a];
		if(visited[adjacent] == false && DFSCycle(adjacent, recStack)) {
			return true;
		}
		else if(recStack[adjacent] == true) {
			return true;
		}
	}
	recStack[s] = false;
	return false;
}

bool isCycle() {
	visited = new bool[V];
	for(int i=0; i<V; i++) {
		visited[i] = false;
	}
	
	int *recStack = new int[V];
	for(int i=0; i<V; i++) {
		recStack[i] = false;
	}
	
	for(int i=0; i<V; i++) {
		if(visited[i] == false) {
			if(DFSCycle(i, recStack)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	cout << "Enter no. of nodes: ";
	cin >> V;
	adj = new vector<int>[V];
	visited = new bool[V];
//	labels = new char[V];
	
//	cout << "Enter labels: " << endl;
//	for(int i=0; i<n; i++) {
//		char l;
//		cin >> l;
//		labels[size] = l;
//		size++;
//	}

	for(int i=0; i<V; i++) {
		visited[i] = false;
	}
	
	int u, v;
	while(u!=-1) {
		cout << "Enter edge from and to (enter either as -1 to stop entering edges): ";
		cin >> u >> v;
		if(u!=-1 && v!=-1) {
			insertEdge(u, v);
		}
	}
	cout << isCycle() << endl;
	
	return 0;	
}
