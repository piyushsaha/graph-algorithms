#include<bits/stdc++.h>
using namespace std;

int V;
int E;

struct Edge {
	int src, dest, w;
	Edge(int s, int d, int ew) {
		src = s;
		dest = d;
		w = ew;
	}
};
Edge **Edges;
bool sortEdge(Edge *a, Edge *b) {
	return a->w < b->w;
}

struct disjointSet {
	int *parent;
	int n;
	disjointSet(int size) {
		n = size;
		parent = new int[n];
		for(int i=0; i<n; i++) {
			parent[i] = i;
		}
	}
	int _find(int x) {
		if(parent[x] == x) {
			return x;
		}
		return _find(parent[x]);
	}
	void _union(int x, int y) {
		int x_rep = _find(x);
		int y_rep = _find(y);
		if(x_rep == y_rep) {
			return;
		}
		parent[y_rep] = x_rep;
	}
	~disjointSet() {
		delete [] parent;
	}
};

void kruskalsMST() {
	sort(Edges, Edges+E, sortEdge);
	disjointSet *dSet = new disjointSet(V);
	int res = 0;
	
	for(int i=0, s=0; s<V-1; i++) {
		Edge *e = Edges[i];
		int x = dSet->_find(e->src);
		int y = dSet->_find(e->dest);
		if(x != y) {
			cout << e->src << " to " << e->dest << ": " << e->w << endl;
			dSet->_union(x, y);
			res += e->w;
			s++;
		}
	}
	delete dSet;
	cout << "Kruskal's MST cost: " << res << endl;
}

int main() {
	cout << "Enter no. of nodes: ";
	cin >> V;
	cout << "Enter no. of edges: ";
	cin >> E;
	Edges = new Edge*[E];
	int u, v, w;
	for(int i=0; i<E; i++) {
		cout << "Enter edge from, to and weight (enter either as -1 to stop entering edges): ";
		cin >> u >> v >> w;
		Edges[i] = new Edge(u, v, w);
		Edge *a = Edges[i];
		cout << a->src << " " << a->dest << " " << a->w << endl;
	}
	
	kruskalsMST();
	return 0;	
}
