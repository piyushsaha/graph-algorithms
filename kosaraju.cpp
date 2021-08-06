#include<bits/stdc++.h>
using namespace std;

int **adj;
int V;

void addEdge(int u, int v) {
	adj[u][v] = 1;
}

int** transposeGraph() {
	int **transpose;
	transpose = new int*[V];
	for(int i=0; i<V; i++) {
		transpose[i] = new int[V];
	}
	
	for(int i=0; i<V; i++) {
		for(int j=0; j<V; j++) {
			transpose[j][i] = adj[i][j];
		}
	}
	return transpose;
}

void finishTimes(int s, bool visited[], stack<int> &st) {
	visited[s] = true;
	for(int i=0; i<V; i++) {
		if(adj[s][i] != 0 && !visited[i]) {
			finishTimes(i, visited, st);
		}
	}
	st.push(s);
}

void DFS( int **G, int s, bool visited[]) {
	visited[s] = true;
	cout << s << " ";
	for(int i=0; i<V; i++) {
		if(G[s][i] != 0 && !visited[i]) {
			DFS(G, i, visited);
		}
	}
}

void kosaraju() {
	stack<int> st;
	bool visited[V];
	for(int i=0; i<V; i++) {
		visited[i] = false;
	}
	
	// Finding the decreasing order of finish times of DFS using topological sort
	for(int i=0; i<V; i++) {
		if(!visited[i]) {
			finishTimes(i, visited, st);
		}
	}
	
	// Reversing the edge directions by doing the transpose of the matrix
	int **tr = transposeGraph();


	for(int i=0; i<V; i++) {
		visited[i] = false;
	}
	
	int count = 0;
	// Doing DFS in the order of decreasing finish times of DFS
	while(st.empty() == false) {
		int s = st.top();
		st.pop();
		
		if(!visited[s]) {
			count++;
			cout << "SCC: ";
			DFS(tr, s, visited);
			cout << endl;
		}
	}
	
	cout << "Number of SCCs: " << count << endl;
	
	
	// Releasing dynamically allocated memory
	for(int i=0; i<V; i++) {
		delete [] tr[i];
	}
	delete [] tr;
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
	
	int u, v;
	while(u != -1) {
		cout << "Enter edge from and to: ";
		cin >> u >> v;
		if(u!=-1) {
			addEdge(u, v);
		}	
	}
	
	kosaraju();
	
	// Releasing dynamically allocated memory
	for(int i=0; i<V; i++) {
		delete [] adj[i];
	}
	delete [] adj;
	
	return 0;
}
