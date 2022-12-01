#include<stdio.h>

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
}
void printSparse(sparse a[])
{
    printf("\nRows Column Value");
    for(int i = 0;i <= a[0].val;i++)
    {
        printf("\n%d\t%d\t%d",a[i].row,a[i].col,a[i].val);
    }
    printf("\n");
}
void transpose(sparse a[],sparse b[])
{
	int rowterms[100],startingpos[100];
	int i,j,numcol=a[0].col,numterms=a[0].val;
	b[0].row=numcol;
	b[0].col=a[0].row;
	b[0].val=numterms;
	if(numterms>0)
	{
		for(i=0;i<numcol;i++)
			rowterms[i]=0;
		for(i=1;i<=numterms;i++)
			rowterms[a[i].col]++;
		startingpos[0]=1;
		for(i=1;i<=numcol;i++)
			startingpos[i]=startingpos[i-1]+rowterms[i-1];
		for(i=1;i<=numterms;i++)
		{
			j=startingpos[a[i].col]++;
			b[j].row=a[i].col;
			b[j].col=a[i].row;
			b[j].val=a[i].val;
		}
	}
}

void main()
{
    sparse a[100],b[100];
    readSparse(a);
    printSparse(a);
    transpose(a,b);
    printf("Transpose of Sparse matrix is :");
    printSparse(b);
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
