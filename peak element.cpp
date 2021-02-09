//for element od an array with minimum time complexity

#include<iostream>
#include<cstdio>
using namespace std;



int count = 0;
void Pwc(int list[],int num,int it,int rt){

    
    
    int mid = (it+rt)/2;
   
        if(mid==0 || mid==num){
            cout<<"Peak day: "<<mid<<endl; 
            
        }   
        else if(list[mid-1]<list[mid-2]){
            Pwc(list,num,it,mid-1); count++;
        }
        else if(list[mid-1]<list[mid]){
            Pwc(list,num,mid+1,rt); count++;
         }
    
        else if(list[mid-1]>list[mid-2] && list[mid-1]>list[mid]){
            cout<<"Peak day: "<<mid<<endl; 
        }    
    

    
    
}

int main()
{
    int num;
    cin >> num;
    int list[num];
    int it=1,rt=num;
    for(int i=0;i<num;i++){
        cin>>list[i];
    }
    Pwc(list,num,it,rt);
    cout<<"number of comparisons taken: "<<count+1<<endl;
    return 0;
}