#include<stdio.h>

void f(int k)
{
    if(k==0)
        return;
        printf("%d", k);
        f(k-1);
        printf("%d", k);
        f(k-1);
        printf("%d", k);

}

void main()
{
    int i = 4;
    f(i);
}