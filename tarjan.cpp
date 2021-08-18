#include<bits/stdc++.h>
using namespace std;

int V;
vector<int> *adj;
bool *visited;
int *timeIn;
int *low;

void insertEdge(int u, int v) {
	adj[u].push_back(v);
}

void dfsTarjan(int v, stack<int> &st, vector<bool> &isInStack, int &timer) {
	visited[v] = true;
	timeIn[v] = low[v] = ++timer;
	isInStack[v] = true;
	st.push(v);
	
	for(int i=0; i<adj[v].size(); i++) {
		int adjacent = adj[v][i];
		
		// If adjacent is not visited
		if(!visited[adjacent]) {
			dfsTarjan(adjacent, st, isInStack, timer);
			low[v] = min(low[v], low[adjacent]);
		}
		
		// If adjacent is visited and it is in stack (back edge)
		else if(visited[adjacent] && isInStack[adjacent]) {
			low[v] = min(low[v], timeIn[adjacent]);
		}
	}
	
	// Printing the SCC
	if(low[v] == timeIn[v]) {
		cout << "SCC: ";
		while(st.top() != v) {
			cout << st.top() << " ";
			isInStack[st.top()] = false;
			st.pop();
		}
		cout << st.top() << endl;
		isInStack[st.top()] = false;
		st.pop();
	}
}

void tarjan() {
	int timer = 0;
	stack<int> st;
	vector<bool> isInStack(V, false);
	for(int i=0; i<V; i++) {
		if(!visited[i]) {
			dfsTarjan(i, st, isInStack, timer);
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
	tarjan();
	
	return 0;	
}
