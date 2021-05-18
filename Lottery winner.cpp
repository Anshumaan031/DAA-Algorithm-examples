// A child has won a lottery of a given shop. A bucket having capacity C is given to him. Now he has to put various items in the bucket in such a way that he receives maximum total value of items. Each item in the shop has specific weight and value. Weight should not exceed C. Also, no item can be divided into further parts. Use dynamic programming to solve the problem.

// Input:

// 3

// 60 100 120

// 10 20 30

// 50

// Where

// First line enters the number of items

// Second line enters the values of each item

// Third line enters the weight of each item

// Fourth line enters the capacity of bucket

// Output:

// 220

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    if(a>b)    return a;
    else return b;
}
 
void printknapSack(int W, int wt[], int val[], int n)
{
    int K[n + 1][W + 1];
  
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if(i == 0 || j == 0){
                K[i][j] = 0;
            }
            else if (wt[i - 1] <= j){
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            }
                
            else    K[i][j] = K[i - 1][j];
        }
    }
    int res = K[n][W];    
    cout<<res<<endl;
     
}
  
int main()
{
    int n;
    cin>>n;
    int val[n];
    int wt[n] ;
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int W ;
    cin>>W;
    printknapSack(W, wt, val, n);
      
    return 0;
}