// Given a Directed Acyclic Graph of job scheduling problem. It represents sequence of jobs which are going to be executed on a given server. Utilize topological sorting to obtain linear combination for every directed edge uv, vertex u comes before v in the ordering.

// Input:

// 6

// 5 2

// 5 0

// 4 0

// 4 1

// 2 3

// 3 1

// Where

// First line enters the number of vertices

// Second line enters the edge from u to v.

// Output:

//        5 4 2 3 1 0

// It represents the topological sorting of the directed graph.

#include <bits/stdc++.h>
using namespace std;
 
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
 
    i = 0;
    cout <<" "<< i;
 
    for (j = 1; j < n; j++)
    {

      if (s[j] >= f[i])
      {
          cout <<" " << j;
          i = j;
      }
    }
}
 
int main()
{
    int t;
    cin>>t;
    int s[t], f[t];
    for(int i=0; i<t; i++)
    {
        cin>>s[i];
    }
    for(int i=0; i<t; i++)
    {
        cin>>f[i];
    }
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}