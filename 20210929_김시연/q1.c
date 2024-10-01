#include<stdio.h>

void f(int k){
    if (k==0)
    {
        return;
        printf("&d \n", k);
        f(k-1);
        printf("%d \n", k);
    }
    
}

int main(){
    int i - 4;
    f(i);
}

