//  Storage of pneumonia infection record

#include<iostream>
#include<cstdio>
using namespace std;
class Node
{   public:
    int data;
    Node* next;
};
Node* first=NULL;
void insert(Node* p,int x);
void print_second(Node* first,int n);
void print_third(Node* first,int n,int c);

int main()
{  
   
   Node* var=NULL;
   int n;
   cin>>n; 
   for(int i=0;i<n;i++)
   {
       int a;
       cin>>a;
       insert(first,a);
   }
    
   print_second(first,n);
    cout<<endl;
    int c = 0;
    while(true){
        char we;
        cin>>we;
        if(we == 'Y'){    
            int w;
            cin>>w;
            c++;
            insert(first,w);
        }
        else   { 
            break;  
        }
        
    }
    
   print_third(first,n,c);
    cout<<endl;
   cout<<"complexity of this approach is O(N)";
   return 0;
}


void insert(Node* h,int x){
    Node* r = NULL;
    Node* t = new Node();
    t->data = x;
    t->next = NULL;
    if(first==NULL)    first=t;
    else{
        while(h && h->data < x){
            r=h;
            h=h->next;
        }
        if(h==first){
            t->next = first;
            first = t;
        }
        else{
            t->next = r->next;
            r->next = t;
        }
    }
}

void print_second(Node* first,int n)
{
    for(int i=0;i<n;i++)
    {
    cout<<first->data<<" ";
    first=first->next;
    }   
}
void print_third(Node* first,int n,int c)
{
    int total = n+c;
    for(int i=0;i<total;i++)
    {
    cout<<first->data<<" ";
    first=first->next;
    }   
}