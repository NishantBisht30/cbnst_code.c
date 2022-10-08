#include<stdio.h>
#include<stdint.h>

#include<math.h>
float f(float x)
{
    return x*log(x) - 1.2;
}
float df (float x)
{
    return log(x) + 1;
}
void main()
{
    int itr, maxmitr;
    float h, x0, x1, allerr;
    printf("\nEnter x0, allowed error and maximum iterations\n");
    scanf("%f %f %d", &x0, &allerr, &maxmitr);
    for (itr=1; itr<=maxmitr; itr++)
    {
        h=f(x0)/df(x0);
        x1=x0-h;
        printf(" At Iteration no. %d, x = %f\n", itr, x1);
        if (fabs(h) < allerr)
        {
            printf("After %d iterations, root = %f\n", itr, x1);
            break;
        }
        x0=x1;
    }
    printf(" The required solution does not converge or iterations are insufficient\n");
    
}