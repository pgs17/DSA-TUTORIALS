#include <stdio.h>
#include <stdlib.h>
struct stack{
int size;
int top;
int *A;
};

void create(struct stack *st){
    printf("Enter size :");
    scanf("%d",&st->size);
    st->top=-1;
    st->A=(int*)malloc(st->size*sizeof(int));
}
void push(struct stack *st,int x){
    if(st->top==st->size-1){
        printf("stack is full");
    }
    else{
        st->top++;
        st->A[st->top]=x;

    }
}
int pop(struct stack *st){
int x=-1; 
    if(st->top==-1){
        printf("stack is empty");
    }
    else{
x=st->A[st->top];
st->top--;
    }
    return x;
}
int peek(struct stack st,int index){
    int x=-1;
    if(st.top-index+1<0){
        printf("invalid index");
    }
    else{
        x=st.A[st.top-index+1];
    }
    return x;
}
void display(struct stack s){
    for(int i=s.top;i>=0;i--){
        printf("%d\t",s.A[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    struct stack st;
create(&st);
push(&st,10);    
push(&st,20);    
push(&st,30);
display(st);
printf("%d\n",pop(&st));
printf("%d\n",peek(st,2));    
    return 0;
}
