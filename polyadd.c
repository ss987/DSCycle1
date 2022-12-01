#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 20
typedef struct
{
    float coef;
    int expon;
}polynomial;
polynomial terms[MAX_TERMS];
int avail=0;


void attach(float coefficent,int exponent)
{
    if(avail>=MAX_TERMS)
        {printf("Too many terms in the polynomial\n");
        exit(1);}
    terms[avail].coef=coefficent;
    terms[avail].expon=exponent;
    avail++;
}


int COMPARE(int a,int b)
{
    if(a>b)
        return 1;
    if(a==b)
        return 0; 
    if(b>a)
        return -1; 
}

void padd(int startA,int finishA,int startB,int finishB,int startD,int finishD)
{
    float coefficent;
    
    while(startA<=finishA && startB<=finishB)
    {
        switch(COMPARE(terms[startA].expon,terms[startB].expon))
        {
            case -1:
            
                attach(terms[startB].coef,terms[startB].expon);
                startB++;
                
                break;
            
            case 0:
                
                coefficent=terms[startA].coef+terms[startB].coef;
                if(coefficent!=0)
                    attach(coefficent,terms[startA].expon);
                startA++;
                startB++;
                
                break;
            
            case 1:
            
                attach(terms[startA].coef,terms[startA].expon);
                startA++;
                
                
        }
        }
    for(;startA<=finishA;startA++)
            attach(terms[startA].coef,terms[startA].expon);
    for(;startB<=finishB;startB++)
            attach(terms[startB].coef,terms[startB].expon);      
    
}
void polyprint(int start,int finish)
{
    int i;
    printf("\n%.2fx^%d ",terms[start].coef,terms[start].expon);
    for(i=start+1;i<=finish;i++)
    {
         if(terms[i].expon==0)
            printf("+ %.2f ",terms[i].coef);
        else
            printf("+ %.2fx^%d ",terms[i].coef,terms[i].expon);
    }
    printf("\n");
}
void main()
{
    int n1,n2,startA,finishA,startB,finishB,startD,finishD;
    int i,j;
    
    printf("\nEnter number of terms in polynomial 1: ");
    scanf("%d",&n1);
    startA=0;
    finishA=n1-1;
    for(i=startA;i<=finishA;i++)
    {
        printf("\nCoefficient: ");
        scanf("%f",&terms[i].coef);
        printf("\nExponent: ");
        scanf("%d",&terms[i].expon);
    }
    polyprint(startA,finishA);
    printf("\nEnter number of terms in polynomial 2: ");
    scanf("%d",&n2);
    
    startB=n1;
    finishB=n1+n2-1;
    avail=n1+n2;
    
    for(i=startB;i<=finishB;i++)
    {
        printf("\nCoefficient: ");
        scanf("%f",&terms[i].coef);
        printf("\nExponent: ");
        scanf("%d",&terms[i].expon);
    }
    polyprint(startB,finishB);
    
    startD=avail;
    padd(startA,finishA,startB,finishB,startD,finishD);
    finishD=avail-1;
    printf("Polynomial sum:\n");
    polyprint(startD,finishD);
    printf("\n");
}

