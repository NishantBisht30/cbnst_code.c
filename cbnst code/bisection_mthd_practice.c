// giving right answer 

#include<stdio.h>
#include<math.h>

float f(float x)
{
    float fx = x*x*x - 5*x +1;
    return fx;
}

void bisection(float *x,float a,float b,int *itr)
{
    *x  = (a+b)/2;
    ++(*itr);
    printf("\nAt Itreration %d , X = %7.5f",*itr,*x);
}

void main()
{
    int itr = 0,maxtrm;
    float x,a,b,tol,x1;
    printf("Enter the assumtions values , tolerance and maximum iterations : ");
    scanf("%f%f%f%d",&a,&b,&tol,&maxtrm);
    bisection(&x,a,b,&itr);
    do
    {
        if(f(a)*f(x)<0)
            b=x;
        else    
            a = x;
        
        bisection(&x1,a,b,&itr);
        if(fabs(x1-x)<tol)
        {
            printf("\nAfter %d iterations , root = %6.4f",itr,x1);
            return 0;
        }
        x=x1;
    }while(itr<maxtrm);
     printf("The solution does not converge or iterations are not sufficient");
}