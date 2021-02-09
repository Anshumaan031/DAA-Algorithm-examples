#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    
    int num;
    int arr[num+1];
    cin>>num;
    
    for(int i=1;i<=num;i++)
    {
        int num2;
        cin>>num2;
        arr[i]=num2;
    }
    
    
    int max=INT_MIN,min=INT_MAX;
    int l=(num+1)/2;
    for(int i=num;i>=l;i--)
    {
        int s=i,count=0;
        while(s>=1)
        { 
            count++;
            s=s/2;
            
        }

        if(count<min) min=count;
        if(count>max) max=count;
        
    }
    cout<<min<<" "<<max;
}