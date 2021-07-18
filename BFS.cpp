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

void breadthFirstSearch(int s=0) {
	visited = new bool[V];
	for(int i=0; i<V; i++) {
		visited[i] = false;
	}
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while(q.empty() == false) {
		int a = q.front();
		q.pop();
		
		// Change labels[v] to v for number graph
		cout << a << " ";
		for(int b=0; b<adj[a].size(); b++) {
			int adjacent = adj[a][b];
			if(visited[adjacent] == false) {
				q.push(adjacent);
				visited[adjacent] = true;
				
			}
		}

//		Range based for
//		for(int x: adj[v]) {
//			if(visited[x] == false) {
//				visited[x] = true;
//				q.push(x);
//			}
//		}
	}
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
	
	cout << "BFS of the graph:" << endl;
	breadthFirstSearch();
	
	return 0;	
}
