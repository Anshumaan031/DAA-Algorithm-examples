// Assume you have given n jobs with their arrival and termination times. Select the maximum number of jobs using Greedy algorithms in such a way that can be performed by a single processor, assuming that a processor can only work on a single job at a time.

// Input:

// 6

// 1 3 0 5 8 5

// 2 4 6 7 9 9

// Where

// First line enters the number of jobs

// Second line enters the arrival time

// Third line enters the termination time

// Output:

// 0 1 3 4

// It represents the selected jobs.

// Assume you have given n jobs with their arrival and termination times. Select the maximum number of jobs using Greedy algorithms in such a way that can be performed by a single processor, assuming that a processor can only work on a single job at a time.

 

// Input:

// 6

// 1 3 0 5 8 5

// 2 4 6 7 9 9

// Where

// First line enters the number of jobs

// Second line enters the arrival time

// Third line enters the termination time

// Output:

// 0 1 3 4

// It represents the selected jobs.

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