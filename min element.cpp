
//min element in sorted and rotated array 


#include <iostream>  
#include <stdlib.h>  
using namespace std; 

int bin(int arr[],int lo,int up){
    if(up>=lo){
        int mid = lo+(up-lo)/2;
        
        if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
            return arr[mid];
        }
        if(arr[mid]<arr[mid+1]){
            return bin(arr,lo,mid-1);
        }
        else{
            return bin(arr,mid+1,up);
        }    
    }
    return -1;
}


int main(){
    int num,min;
    cin>>num;
    
    int arr[num];
    for(int i=0;i<num;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    
    min=bin(arr,0,num-1);
    cout<<"The Minimum element is:"<<min;
}
