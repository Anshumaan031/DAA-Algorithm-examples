// John has city details of N cities along with one-ways paths only. He has to find all the shortest paths using the concept of dynamic programming.

 
// Example: 

// Input:

//        V[][] = { {0,   5,  INF, 10},

//                     {INF,  0,  3,  INF},

//                     {INF, INF, 0,   1},

//                     {INF, INF, INF, 0} }

// which represents the following city

//              10

//        (0)------->(3)

//         |         /|\

//       5 |          |

//         |          | 1

//        \|/         |

//        (1)------->(2)

//             3      

// Value of V[i][j] is 0 if i is equal to j.

// V[i][j] is INF (infinite) if there is no directed path from city i to j.

// Output:

// Shortest distance matrix is

//       0      5      8      9

//     INF      0      3      4

//     INF    INF      0      1

//     INF    INF    INF      0

#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999
void printSolution(int dist[][V]);
void floydWarshall (int graph[][V])
{
	int dist[V][V], i, j, k;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}

void printSolution(int dist[][V])
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				cout<<"INF"<<"  ";
			else
				cout<<dist[i][j]<<"  ";
		}
		cout<<endl;
	}
}

int main()
{
	int graph[V][V] = { {0, 5, INF, 10},
						{INF, 0, 3, INF},
						{INF, INF, 0, 1},
						{INF, INF, INF, 0}
					};

	floydWarshall(graph);
	return 0;
}