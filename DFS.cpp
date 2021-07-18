#include<bits/stdc++.h>
using namespace std;

int V;
vector<int> *adj;
char *labels;
bool *visited;
int size=0;

void insertEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}


void DFSRec(int s=0) {
//	visited
	visited[s] = true;
	cout << s << " ";
	for(int i=0; i<adj[s].size(); i++) {
		int adjacent = adj[s][i];
		if(!visited[adjacent]) {
			DFSRec(adjacent);
		}
	}
}

int DFS(int s=0) {
//	visited = {false};
	visited = new bool[V];
	for(int i=0; i<V; i++) {
		visited[i] = false;
	}
	int count = 0;
	cout << "DFS: " << endl;
	for(int i=0; i<V; i++) {
		if(!visited[i]) {
			count++;
			DFSRec(i);
		}
	}
	cout << endl;
	return count;
}

int main() {
	cout << "Enter no. of nodes: ";
	cin >> V;
	adj = new vector<int>[V];
	visited = new bool[V];
	labels = new char[V];
	
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
		cout << "Enter edge from and to: ";
		cin >> u >> v;
		if(u!=-1 && v!=-1) {
			insertEdge(u, v);
		}
	}
	
//	cout << "DFS of the graph:" << endl;
	cout << "Islands: " << DFS() << endl;;
	
	return 0;	
}
