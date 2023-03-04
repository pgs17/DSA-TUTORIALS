#include <stdio.h>
/* int fibonacci(int n){
    if (n==0||n==1)
    {
        return n;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
} */

int arr[10];
int fib(int n){
if(n==0||n==1){
    arr[n]=n;
    return n;
}
else{
    if(arr[n-2]==-1){
        arr[n-2]=fib(n-2);
    }
    if(arr[n-1]==-1){
        arr[n-1]=fib(n-1);
    }
    return fib(n-1)+fib(n-2);
}
}

int main(int argc, char const *argv[])
{for(int i=0;i<10;i++){
    arr[i]=-1;
}

    for(int i=0;i<=5;i++){
    printf("%d\t",fib(i));
    }
    return 0;
}

