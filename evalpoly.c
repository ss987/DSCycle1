#include<stdio.h>
#include<math.h>

typedef struct{
    int exp;
    int coeff;
}poly;
int readPoly(poly a[],int start,int end)
 {
	int i;

	
	for(i=0;i<(end-start+1);i++)
	{
		printf("   Enter Coefficient: ");
		scanf("%d",&a[i].coeff);
		printf("      Enter exponent: ");
		scanf("%d",&a[i].exp);        
	}
	
 }
 void printPoly(poly a[],int start,int end)
{
    int i;
    for(i=start;i<end;i++)
    {
        printf("%dx^%d + ",a[i].coeff,a[i].exp);
    }
    printf("%dx^%d \n",a[i].coeff,a[i].exp);
}
int evalPoly(poly a[],int start,int end,int x)
{
    int result = 0;
    while(start<=end)
    {
        result += a[start].coeff * pow(x,a[start].exp);
        start++;
    }
    return result;
}
void main()
{
    poly a[100];
    int n1,x,startA,endA;
    printf("Enter no. of terms of the polynomial: ");
    scanf("%d",&n1);
    startA = 0;
    endA = n1-1;
    readPoly(a,startA,endA);
    printf("Entered polynomial is : ");
    printPoly(a,startA,endA);
    printf("Enter value of x: ");
    scanf("%d",&x);
    printf("Value of Polynomial = %d\n",evalPoly(a,startA,endA,x));
}

    

