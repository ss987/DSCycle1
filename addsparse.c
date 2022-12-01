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
    	printf("Enter element \n");
        scanf("%d",&element);
        printf("Enter row index: \n");
        scanf("%d",&ri);
        printf("Enter column index: \n");
        scanf("%d",&ci);
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
void sumofSparse(sparse a[],sparse b[],sparse sum[])
{
    int i=1,j=1,l=1;
    if(a[0].row != b[0].row || a[0].col != b[0].col)
    {
        printf("Cannot find sum");
        exit(0);
    }
    sum[0].row = a[0].row;
    sum[0].col = a[0].col;

        while(i<=a[0].val && j <= b[0].val){
        if(a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col))
        {
                sum[l].row = a[i].row;
		sum[l].col = a[i].col;
		sum[l].val = a[i].val;
		i++;
		l++;
        }
        else if(a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)){
                sum[l].row = b[j].row;
		sum[l].col = b[j].col;
		sum[l].val = b[j].val;
		j++;
		l++;
		}
        else if(a[i].row == b[j].row && a[i].col == b[j].col){
            sum[l].row= a[j].row;
            sum[l].col = a[i].col;
            sum[l].val = a[i].val + b[j].val;
            i++;
            j++;
            l++;
        }
    }

    while (i<=a[0].val)
    {
        sum[l].row = a[i].row;
        sum[l].col = a[i].col;
        sum[l].val = a[i].val;
        i++;
        l++;
    }

    while (j<=b[0].val)
    {
        sum[l].row = b[j].row;
        sum[l].col = b[j].col;
        sum[l].val = b[j].val;
        j++;
        l++;
    }
    sum[0].val = l-1;
}
void main()
{
    sparse a[100],b[100],sum[100];
    readSparse(a);
    readSparse(b);
    
    sumofSparse(a,b,sum);
    printf("Sum of Sparse matrices is :");
    printSparse(sum);
}
