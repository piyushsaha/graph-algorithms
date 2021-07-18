#include<bits/stdc++.h>
using namespace std;

int V;
vector<int> *adj;
//char *labels;
bool *visited;
int *parent;

void insertEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool DFSRec(int s, int parent) {
	visited[s] = true;
	for(int a=0; a<adj[s].size(); a++) {
		int adjacent = adj[s][a];
		
		// Adjacent is visited and not parent, so cycle exists
		if(visited[adjacent]==true && adjacent!=parent) {
			return true;
		}
		// Adjacent is not visited
		else if(visited[adjacent]==false) {
			// Loop exists in the adjacent vertex's DFS, so cycle exists
			if(DFSRec(adjacent, s)) {
				return true;
			}
		}
	}
	// If both above conditions fail, NO cycle exists
	return false;
}

bool BFSCycle(int s=0) {
	queue<int> q;
	q.push(s);
	visited[s] = true;
	
	while(q.empty() == false) {
		int f = q.front();
		q.pop();
		for(int a=0; a<adj[f].size(); a++) {
			int adjacent = adj[f][a];
			// If adjacent of F is unvisited, enqueue it, visited true and update parent as F
			if(visited[adjacent] == false) {
				q.push(adjacent);
				parent[adjacent] = f;
				visited[adjacent] = true;
			}
			// Else, adjacent is visited
			else {
				// If the already visited adjacent of F is NOT the parent of F, cycle found
				if(adjacent != parent[f]) {
					return true;
				}
			}
		}
	}
	return false;
}
bool isCycle() {
	visited = new bool[V];
	for(int i=0; i<V; i++) {
		visited[i] = false;
	}
	
	// For BFS based soln. only
	parent = new int[V];
	for(int i=0; i<V; i++) {
		parent[i] = -1;
	}
	for(int i=0; i<V; i++) {
		if(visited[i] == false) {
//			if(DFSRec(i, -1)) {
//				return true;
//			}
			if(BFSCycle(i)) {
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
