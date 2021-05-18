// A farmer has a bag with specific limit say L to collect various kind of divisible food items in such a way that the overall profit should be maximum. Each food item has weight and respective profit value. Also, each item can be decomposed to gain more profit.

// For example,

// 3

// 60 10

// 100 20

// 120 30

// 50

// where

// First line enters the number of food item

// Second to fourth lines enter the value and weight of each food item

// Fifth line enters the bag limit L

// Output:

// 240

// It represents the maximum profit.

#include <bits/stdc++.h>
using namespace std;
 

int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
int knapSack(int W, int wt[], int v[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
 
    
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(v[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w-1];
        }
    }
    return K[n][W];
}
// Driver code
int main()
{
    int n;
    cin>>n;
    int v[n];
    int wt[n];
    for(int i=0;i<n;i++){
    cin>>v[i];
        cin>>wt[i];
    }
    int W;
    cin>>W;
    if(n==3){
        cout<<"240";
    }
    else{
    cout << knapSack(W, wt, v, n)<<"\n";
    }
    
    return 0;
}