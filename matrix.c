// matrix demo if req in a program 
// for different matrix just change formula of size and index
#include <stdio.h>
#include <stdlib.h>
struct matrix
{
    int *A;
    int n;
};
void set(struct matrix *m,int i,int j,int x){
    if (i==j)
    {
        m->A[i-1]=x;
    }
}
int get(struct matrix m,int i,int j){
    if(i==j){
        return m.A[i-1];
    }
    else{
        return 0;
    }
}
int display(struct matrix m){
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            if(i==j){
                printf("%d",m.A[i-1]);
            }
            else{
                printf("0");
            }
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    struct matrix m;
    int x;
    printf("Enter Dimension:");
    scanf("%d", &m.n);
    m.A=(int*)malloc(m.n*sizeof(int));
    for(int i=1;i<=m.n;i++){
        for(int j=1;j<=m.n;j++){
if(i==j){
    scanf("%d",&x);
                set(&m,i,j,x);
        }}
        
    }
    display(m);
    return 0;
}
