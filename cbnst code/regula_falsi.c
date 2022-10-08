#include<stdio.h>
#include<math.h>
#define e 0.001

float f(float x)
{
    float fx = x*x*x - x - 1;
    return fx;
}

int main()
{
    int itr=0;
    float a,b,c,fa,fb,fc;
    scanf("%f%f",&a,&b);
    do{
        fa = f(a);
        fb = f(b);
        c = ((a*fb) - (b*fa))/(fb-fa);
        fc = f(c);
        if(fc<0)
        {
            a=c;
            fa=fc;
        }
        else{
            b=c;
            fb = fc;
        }
        itr++;
        printf("iteration %d\n",itr);
        printf("root %f\n",c);
    }while(fabs(fc)>e);
    
    return 0;
}