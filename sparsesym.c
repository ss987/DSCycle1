#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int row;
    int col;
    int val;
}sparse;
void readSparse(sparse a[])
{
    int m,n,spar=0,element,nz,ri,ci;    
    printf("Enter no. of rows of matrix: ");
    scanf("%d",&m);
    printf("Enter no. of columns of matrix: ");
    scanf("%d",&n);
    if (m!=n)
    {
    	printf("Symmetry cannot be checked\n");
    	exit(0);
    }
    printf("Enter number of non-zero elements of matrix: \n");
    scanf("%d",&nz);
    a[0].row = m;
    a[0].col = n;
    a[0].val = nz;
    for(int i =1;i<=nz;i++)
    {	
    	printf("Enter row index: \n");
        scanf("%d",&ri);
        printf("Enter column index: \n");
        scanf("%d",&ci);
        printf("Enter element: \n");
        scanf("%d",&element);
        a[i].row = ri;
        a[i].col = ci;
        a[i].val = element;       
    }
}
void printSparse(sparse a[])
{
    printf("\nRows Column Value");
    for(int i = 0;i <= a[0].val;i++)
    {
        printf("\n%d\t%d\t%d",a[i].row,a[i].col,a[i].val);
    }
}
void sym(sparse a[])
{
    int flag=0;
    int i,j;
    for(i=1;i<=a[0].val;i++)
    {
        
        for(j=1;j<=a[0].val;j++)
        {
            if(a[i].col == a[j].row && a[i].row == a[j].col)
             {
                if(a[i].val != a[j].val)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    break;
                }
             }
        }
        printf("\n");
        
    }
    if(flag == 0)
        {
            printf("Symmetric\n");
            return;
        }
     
    else
    	printf("Not Symmetric\n");
}
void main()
{
    sparse a[100],b[100];
    readSparse(a);
    printSparse(a);
    sym(a);
    
}
