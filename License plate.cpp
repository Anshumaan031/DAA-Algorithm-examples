// A license plate begins with K letters. If there are N letters, how many different permutations of these letters can be made if no letter is used more than once? It should be implemented using dynamic programming.

 

// Input: 

// 10

// 2

// where 

// first line enters the number of letters

// second line enters the required letters to design number plate

 

// Output:

// 90

#include<bits/stdc++.h> 
  using namespace std;
// Returns value of Permutation 
// Coefficient P(n, k) 
int permutationCoeff(int n, int k) 
{ 
    int P[n + 1][k + 1]; 
  
    // Calculate value of Permutation  
    // Coefficient in bottom up manner 
    for (int i = 0; i <= n; i++) 
    { 
        for (int j = 0; j <= std::min(i, k); j++) 
        { 
            // Base Cases 
            if (j == 0) 
                P[i][j] = 1; 
  
            // Calculate value using 
            // previosly stored values 
            else
                P[i][j] = P[i - 1][j] +  
                          (j * P[i - 1][j - 1]); 
  
            // This step is important 
            // as P(i,j)=0 for j>i 
            P[i][j + 1] = 0; 
        } 
    } 
    return P[n][k]; 
} 
  
// Driver Code 
int main() 
{ 
    int n ,k;
    cin>>n>>k;
     
            cout<< permutationCoeff(n, k)<<"\n"; 
    return 0; 
}