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

void DFSRec(int s, stack<int>& st) {
	visited[s] = true;
	
	for(int a=0; a<adj[s].size(); a++) {
		int adjacent = adj[s][a];
		if(visited[adjacent] == false) {
			DFSRec(adjacent, st);
		}
	}
	
	st.push(s);
}

void topologicalSort() {
	stack<int> st;
	
	for(int i=0; i<V; i++) {
		if(visited[i] == false) {
			DFSRec(i, st);
		}
	}
	
	cout << "Topological sort: ";
	while(st.empty() == false) {
		cout << st.top() << " ";
		st.pop();
	}
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
	topologicalSort();
	
	return 0;	
}
