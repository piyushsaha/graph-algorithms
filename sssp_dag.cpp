#include<bits/stdc++.h>
using namespace std;

void topologicalSort(int, stack<int>&);

int V;
int **adj;
bool *visited;
int *parent;

void insertEdge(int u, int v, int w) {
	adj[u][v] = w;
}

void sssp_DAG(int s=0) {
	int dist[V];
	for(int i=0; i<V; i++) {
		dist[i] = INT_MAX;
	}
	stack<int> st;
	topologicalSort(s, st);
	dist[s] = 0;
	while(st.empty() == false) {
		int f = st.top();
		st.pop();
		cout << "TOP: " << f << endl;
		for(int i=0; i<V; i++) {
			if(adj[f][i]!=0) {
				if(dist[i] > dist[f] + adj[f][i]) {
					dist[i] = dist[f] + adj[f][i];
				}
			}
		}
	}
	
	for(int i=0; i<V; i++) {
		if(dist[i] == INT_MAX) {
			cout << "Distance from " << s << " to " << i << ": INFINITY" << endl;
		}
		else {
			cout << "Distance from " << s << " to " << i << ": " << dist[i] << endl;
		}	
	}
}

void DFSRec(int s, stack<int>& st) {
	visited[s] = true;
	
	for(int a=0; a<V; a++) {
		if(adj[s][a]!=0) {
			int adjacent = a;
			if(visited[adjacent] == false) {
				DFSRec(adjacent, st);
			}	
		}	
	}
	st.push(s);
}

void topologicalSort(int s, stack<int> &st) {
	
//	for(int i=0; i<V; i++) {
//		if(visited[i] == false) {
			DFSRec(s, st);
//		}
//	}
	
//	cout << "Topological sort: ";
//	while(st.empty() == false) {
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
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
	int s;
	cout << "Enter source: ";
	cin >> s;
	sssp_DAG(s);
	
	return 0;	
}
