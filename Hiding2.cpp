// A C++ program to generate d-regular graphs of size n vertices
#include<iostream> 
#include <list> 
//#define NIL -1 
using namespace std; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 

public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    void bridge();    // prints all bridges 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 

void constructGraph (int n, int d) { 
	/*
	 This function constructs a d-regular graph on n vertices. The n-vertices lie on a circle.
	 n is the number of vertices in the regular graph, d is the degree of each vertex.
	 It is worth noting that it's not possible to construct a graph in which n and d are both odd.
	 It must also be noted, that we do not need any edge properties; we do not need to extract edges. However, we do need to extract vertices from the adjacency matrix.
	 We essentially need only vertices and their neighbors. 

	 I think that adjacency lists actually make more sense here. We need the vertices, and the vertices that are connected to them, not anything else. 
	*/	
	int adj[n][n] = {0}; // Initializing the graph to be completely disconnected in the beginning
	if (d % 2 == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < d/2; j++) {
				adj[i][i+j+1 % n] = 1; // connecting ith vertex to ith + 1 and so on vertices
				adj[i][i-j-1+n % n] = 1;
			}
		}
	}
	else if ((d % 2 != 0) && (n % 2 == 0)) { // which is the only other valid condition
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < d/2; j++) {
				adj[i][i+j+1 % n] = 1; // attaching ith vertex to either side of d/2 vertices
				adj[i][i-j-1+n % n] = 1; // attaching ith vertex to either side of d/2 vertices
			}
			adj[i][i + n/2 % n] = 1;  // attaching ith vertex to one remaining vertex through diagonal
		}
	}
		
}


int main() {
	int n, d;
	cout << "Please enter the number of vertices";
	cin >> n;
	cout << "Please enter the degree of the regular graph";
	cin >> d;
	constructGraph(n, d);

}
