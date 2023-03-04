/* menu driven program for matrix 
1 create
2 get
3 set 
4 display */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *A;
    int n,ch,i,j,x;
    printf("enter dimension:");
    scanf("%d",&n);
    A=(int*)malloc(n*sizeof(int));
    do{
        printf("enter 1 for create a matrix:");
        printf("enter 2 for getting an element matrix:");
        printf("enter 3 for setting  an element matrix:");
        printf("enter 4 for display a matrix:");
        printf("enter 5 to exit:");
        scanf("%d",&ch);
        switch(ch){
case 1: printf("create an array");
for( i=1;i<=n;i++){
    scanf("%d",A[i-1]);
}
break;
case 2:printf("get value from");
printf("enter indices from value u want:");
scanf("%d %d",&i,&j);
if(i==j){
    printf("%d",A[i-1]);
}
else{
    printf("0");
}
break;
case 3:printf("enter indices and values to be set:");
scanf("%d %d %d",&i,&j,&x);
scanf("%d",&x);
if(i==j){
    A[i-1]=x;
}
break;
case 4:
printf("the matrix is:\n");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        if(i==j){
            printf("%d",A[i-1]);
        }
        else{
            printf("0");
        }
    }
    printf("\n");
}
case 5:break; // written for execution till end
default: printf("enter valid choice");
exit(0);
        }


    }while(ch!=5);
    return 0;
}

