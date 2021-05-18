// John has city-wise map, he wishes to know all the connected cities with minimum cost. So, to achieve this objective, utilize Prim’s algorithm to return the spanning tree with minimum cost.

// For example,

// Input

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

// Second line enters the edges from u to v and third parameter is w.

// Output:

// 0 - 1

// 1 - 2

// 2 - 3

// 3 - 4

// 2 - 5

// 5 - 6

// 6 - 7

// 2 - 8

// It represents spanning tree with minimum cost.

#include <bits/stdc++.h>
using namespace std;

int minKey(int key[], bool mstSet[],int V){
    int min = INT_MAX, min_index; 
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
    return min_index; 
}
int main(){
    int a,V;
    cin >> V;
    int graph[V][V];
    for(int i = 0;i < V;i++){
        for(int j = 0;j < V;j++){
            graph[i][j] = 0;
        }
    }
    cin >> a;
    for(int i = 0;i < a;i++){
        int b,c,d;
        cin >> b >> c >> d;
        graph[b][c] = d;
    }
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0; 
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++){
        int u = minKey(key, mstSet,V);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    }
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<"\n"; 
    return 0;
}