// Given a route map of hill side area, utilize the concept of minimum spanning tree and Kruskal’s algorithm to evaluate the connected locations in the hill side area.

// For example,

// Input:

// 9 12

// 0 1 4

// 0 7 8

// 1 2 8

// 1 7 11

// 2 3 7

// 2 8 2

// 2 5 4

// 3 4 9

// 3 5 14

// 4 5 10

// 5 6 2

// 6 7 1

// 6 8 6

// 7 8 7      

// First line enters the number of vertices and edges

// Second line enters the edges from u to v and third parameter is weight of edge.

// Output:

// 6 - 7

// 2 - 8

// 5 - 6

// 0 - 1

// 2 - 5

// 2 - 3

// 0 - 7

// 3 - 4

// It represents the connected locations.

#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
	int src, dest, weight;
};
class Graph {
public:
	int V, E;
	Edge* edge;
};
Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];

	return graph;
}
class subset {
public:
	int parent;
	int rank;
};
int find(subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent
			= find(subsets, subsets[i].parent);

	return subsets[i].parent;
}
void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}
int myComp(const void* a, const void* b)
{
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return a1->weight > b1->weight;
}
void tree(Graph* graph)
{
	int V = graph->V;
	Edge result[V]; 
	int e = 0; 
    int i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),myComp);
	subset* subsets = new subset[(V * sizeof(subset))];
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	while (e < V - 1 && i < graph->E)
	{
		Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
		if (x != y) {
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}
	int minimumCost = 0;
	for (i = 0; i < e; ++i)
	{
		cout << result[i].src << " - " << result[i].dest<< endl;
		minimumCost = minimumCost + result[i].weight;
	}
}
int main()
{
	int v,e;
    cin>>v>>e; 
	Graph* graph = createGraph(v,e);
    
    int s,d,w;
    for(int i=0;i<e;i++)
    {    cin>>s>>d>>w;
        graph->edge[i].src = s;
	    graph->edge[i].dest = d;
	    graph->edge[i].weight = w;
    }
    tree(graph);
}