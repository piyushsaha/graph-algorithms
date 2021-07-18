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

void calculateIndegrees(int *indegrees) {
	for(int i=0; i<V; i++) {
		indegrees[i] = 0;
	}
	for(int i=0; i<V; i++) {
		for(int j=0; j<adj[i].size(); j++) {
			indegrees[adj[i][j]]++;
		}
	}
}

bool isCycle() {
	queue<int> q;
	int *indegrees = new int[V];
	calculateIndegrees(indegrees);
	for(int i=0; i<V; i++) {
		if(indegrees[i]==0) {
			q.push(i);
		}
	}
	int count = 0;
	while(q.empty() == false) {
		int f = q.front();
		q.pop();
//		cout << f << " ";
		for(int a=0; a<adj[f].size(); a++) {
			int adjacent = adj[f][a];
			indegrees[adjacent]--;
			if(indegrees[adjacent] == 0) {
				q.push(adjacent);
			}
		}
		count++;
	}
	return count!=V;
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
