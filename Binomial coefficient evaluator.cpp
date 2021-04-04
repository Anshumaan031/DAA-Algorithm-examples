#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
    if (a < b) return a;
    else return b;
}
int binomialC(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
 
    return C[n][k];
}
 
int main()
{
    int n,k;
    cin>>n>>k;
    cout<< binomialC(n, k);
}