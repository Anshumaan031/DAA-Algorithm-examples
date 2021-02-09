#include <bits/stdc++.h>
using namespace std;
class Node 
{ 
    public:
    int data; 
    Node* link; 
}; 


void Move_Node(Node** destRef, Node** sourceRef); 
Node* Smerge(Node* x, Node* y) 
{ 
    Node temp; 
    Node* tail = &temp;
    temp.link = NULL; 
    
    while (true) 
    { 
        if (x == NULL) 
        { 
            tail->link = y; 
            break; 
        } 
        else if (y == NULL) 
        { 
            tail->link = x; 
            break; 
        } 
        if(x->data <= y->data)  {
            Move_Node(&(tail->link), &x);
        } 
        else  {
            Move_Node(&(tail->link), &y);
              }
 
        tail = tail->link; 
    } 
    return(temp.link); 
} 


void Move_Node(Node** destRef, Node** sourceRef) 
{ 
    Node* ptr = *sourceRef; 
    assert(ptr != NULL); 
    *sourceRef = ptr->link;
    ptr->link = *destRef; 
    *destRef = ptr; 
} 


void push(Node** head_ref, int new_data) 
{ 
    Node* ptr = new Node();
    ptr->data = new_data; 
    ptr->link = (*head_ref); 
    (*head_ref) = ptr; 
} 


void printList(Node *node) 
{ 
    while (node!=NULL) 
    { 
        cout<<node->data<<" "; 
        node = node->link; 
    } 
} 
 

int main() 
{ 
    Node* x = NULL; 
    Node* y = NULL; 
    Node* res = NULL; 
     int N1,N2;
    cin>>N1>>N2;
    int arr[N1],arr1[N2];
    for(int i=0;i<N1;i++)
    { 
    cin>>arr[i];
    push(&x,arr[i]); 
    }
     for(int i=0;i<N2;i++)
    { 
    cin>>arr1[i];
    push(&y, arr1[i]); 
     }
    sort(arr1 , arr1 + N2);
    sort(arr , arr + N1);
    for(int i=0;i<N1;i++)
    { 
    cout<<arr[i]<<" ";
    }
    cout<<endl;
     for(int i=0;i<N2;i++)
    { 
    cout<<arr1[i]<<" ";
     }
    cout<<endl;
    res = Smerge(x, y); 
    printList(res); 
}