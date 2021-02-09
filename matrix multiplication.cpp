// Matrix multiplication using D&C

#include <iostream>
 #include <stdio.h> 
using namespace std;
  
const int MAX = 100; 
  
void multiplyMatrix(int row1, int col1, int A[][MAX], 
                    int row2, int col2, int B[][MAX]) ;
void multiplyMatrixRec(int row1, int col1, int A[][MAX], 
                       int row2, int col2, int B[][MAX], 
                       int C[][MAX]);
// Driven Program 
int main() 
{ 
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int A[a][MAX];
    int B[c][MAX];
    for(int i=0;i<a;i++)
    {
    for(int j=0;j<b;j++)
    cin>>A[i][j];
    }
   for(int i=0;i<c;i++)
    {
    for(int j=0;j<d;j++)
    cin>>B[i][j];
   }
  
    int row1 = a, col1 = b, row2 = c, col2 = d; 
    multiplyMatrix(row1, col1, A, row2, col2, B); 
  
    return 0; 
}


void multiplyMatrixRec(int row1, int col1, int A[][MAX], 
                       int row2, int col2, int B[][MAX], 
                       int C[][MAX]) 
{ 
    static int i = 0, j = 0, k = 0; 
  
    // If all rows traversed. 
    if (i >= row1) 
        return; 
  
    // If i < row1 
    if (j < col2) 
    { 
      if (k < col1) 
      { 
         C[i][j] += A[i][k] * B[k][j]; 
         k++; 
  
         multiplyMatrixRec(row1, col1, A, row2, col2, 
                                               B, C); 
      } 
  
      k = 0; 
      j++; 
      multiplyMatrixRec(row1, col1, A, row2, col2, B, C); 
    } 
  
    j = 0; 
    i++; 
    multiplyMatrixRec(row1, col1, A, row2, col2, B, C); 
} 
  
// Function to multiply two matrices A[][] and B[][] 
void multiplyMatrix(int row1, int col1, int A[][MAX], 
                    int row2, int col2, int B[][MAX]) 
{ 
    if (row2 != col1) 
    { 
        printf("Not Possible\n"); 
        return; 
    } 
  
    int C[MAX][MAX] = {0}; 
  
    multiplyMatrixRec(row1, col1, A, row2, col2, B, C); 
  
    // Print the result 
    for (int i = 0; i < row1; i++) 
    { 
        for (int j = 0; j < col2; j++) 
            cout<<C[i][j]<<" "; 
  
        cout<<endl; 
    } 
}