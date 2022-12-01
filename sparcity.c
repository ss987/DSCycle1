#include<stdio.h>

typedef struct{
    int row;
    int col;
    int val;
}sparse;

float readSparse(sparse a[])
{
    int m,n,spar=0,element,nz,ri,ci;
    float sparsity;
    printf("Enter no. of rows of matrix: ");
    scanf("%d",&m);
    printf("Enter no. of columns of matrix: ");
    scanf("%d",&n);
    
    printf("Enter number of non-zero elements of matrix: \n");
    scanf("%d",&nz);
    a[0].row = m;
    a[0].col = n;
    a[0].val = nz;
    for(int i =1;i<=nz;i++)
    {
    	printf("Enter element: \n");
        scanf("%d",&element);
        printf("Enter row index: \n");
        scanf("%d",&ri);
        printf("Enter column index: \n");
        scanf("%d",&ci);
        a[i].row = ri;
        a[i].col = ci;
        a[i].val = element;       
    }
    sparsity = (float)(m*n-nz)/(m*n);
    return sparsity;   
    
    
}

void printSparse(sparse a[])
{
    printf("\nRows Column Value");
    printf("\n******************");
    for(int i = 0;i <= a[0].val;i++)
    {
        printf("\n%d\t%d\t%d",a[i].row,a[i].col,a[i].val);
    }
}

void main(){
    sparse a[100];
    float sparsity = readSparse(a);
    printf("Sparse representation is :");
    printSparse(a);
    printf("\nSparsity of the matrix is : %f\n",sparsity*100);
}
