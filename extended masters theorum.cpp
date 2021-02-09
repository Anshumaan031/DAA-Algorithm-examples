#include<iostream>
#include<cstdio>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    
    int n1,n2;
    int k,p;
    cin>>n1>>n2;
    cin>>k>>p;
    cout<<"T(n)="<<n1;
    cout<<"T(n"<<"/"<<n2<<")+Theta(n^"<<k<<"(log_2^n)^"<<p<<")";
    cout<<endl;
    
    
    if(n1<pow(n2,k))
    {
    if(p>=0)
    {
    cout<<"Complexity="<<
    "Theta(n^"<<k<<"(log_2^n)^"<<p<<")";
        
    }
    else
    {
    cout<<"Theta(n^"<<k<<")";
    }
        
        
    }
    else if(n1>pow(n2,k))
    {
        cout<<"Complexity="<<"Theta(n^"<<"(log_"<<n2<<"^"<<n1<<"))";
    }
    
    
    else
    {
    if(p<-1)
    {
    cout<<"Complexity="<<"Theta(n^"<<"(log_"<<n2<<"^"<<n1<<"))";
    }
        
    else if(p>-1)
    {
    cout<<"Complexity="<<"Theta(n^"<<"(log_"<<n2<<"^"<<n1<<")(log_2^n)^"<<p+1<<")";
    }
        
    else
    {
    cout<<"Complexity="<<"Theta(n^"<<"(log_"<<n2<<"^"<<n1<<")(loglog_2^n)";
    }}
}
