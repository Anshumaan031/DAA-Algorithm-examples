// Utilize dynamic programming to count the number of ways to cover a distance with 1, 2 and 3 steps. 

#include<iostream>
#include<cstdio>
using namespace std;

void Sol(int arr[],int n){
        for(int i=3;i<=n;i++){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }
        cout<<arr[n];
}
int main()
{
    int N;
    cin>>N;
    int arr[N];
    arr[0]=arr[1]=1;
    arr[2] = 2;
    Sol(arr,N);
}