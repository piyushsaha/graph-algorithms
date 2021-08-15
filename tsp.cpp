#include<bits/stdc++.h>
using namespace std;

int **adj;
int V;

void addEdge(int u, int v, int w) {
	adj[u][v] = w;
	adj[v][u] = w;
}

void tsp(int s=0) {
	vector<int> v;
	int ans[V-1];
	
	// Storing the vertices except the source vertex in a vector
	for(int i=0; i<V; i++) {
		if(i!=s) {
			v.push_back(i);
		}
	}
	
	int minCost = INT_MAX;
	
	// Calculating the minimum path for all the permutations
	do {
		// Starting from source node
		int k=s;
		int currPath = 0;
		
		// Calculating the distance to last vertex in this permutation
		for(int i=0; i<v.size(); i++) {
			currPath += adj[k][v[i]];
			k = v[i];
		}
		// Coming back to source vertex
		currPath += adj[k][s];
		
		if(currPath < minCost) {
			minCost = currPath;
			for(int i=0; i<v.size(); i++) {
				ans[i] = v[i];
			}
		}
		
	} while(next_permutation(v.begin(), v.end()));
	
	cout << "Minimum travel cost: " << minCost << endl;
	cout << "The path: " << s << " -> ";
	for(int i=0; i<V-1; i++) {
		cout << ans[i] << " -> ";
	}
	cout << s << endl;	
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
	
	int u, v, w;
	while(u != -1) {
		cout << "Enter edge from, to and weight: ";
		cin >> u >> v >> w;
		if(u!=-1) {
			addEdge(u, v, w);
		}	
	}

	tsp();
	
	// Releasing dynamically allocated memory
	for(int i=0; i<V; i++) {
		delete [] adj[i];
	}
	delete [] adj;
	
	return 0;
}
