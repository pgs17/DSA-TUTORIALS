#include <stdio.h>
/* double e(int x,int n){
    static double p=1;
    static double f=1;
    double r;
    if(n==0){
        return 1;
    }
    else{
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r+ p/f; 
    }
} */
double e(double x,double n){
    static double sum=1;
    if(n==0){
        return sum;
    }
    else{
        sum=1+x/n*sum;
        return e(x,n-1);
    }
}
int main(int argc, char const *argv[])
{
    printf("%f",e(1,10));
    return 0;
}
