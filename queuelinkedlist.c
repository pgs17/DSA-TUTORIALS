#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
}*front =NULL,*rear=NULL;

void enqueue(int x){
    struct node*t;
    t=(int*)malloc(sizeof(struct node));
    if(t==NULL){
        printf("queue overflow");
    } 
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front = rear=t;
        }
        else{
            rear->next=t;
            rear =t;
        }
    }
}

int dequeue(){
    int x=-1;
struct node *p; 
    if(front ==NULL){
        printf("stack underflow");
    }
    else{
p=front;
front =front ->next;
x=p->data;
free(p);
    }
    return x;
}
void display(){
    struct node *P=front;
    while (P)
    {
        printf("%d\t",P->data);
        P=P->next;
    }
}

int main(int argc, char const *argv[])
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    printf("%d",dequeue());
    return 0;
}
