#include <stdio.h>
#include <stdlib.h>
struct queue {
int size;
int front;
int rear;
int *A;
};
void create(struct queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->A=(int*)malloc(q->size*sizeof(int));
}
void enqueue(struct queue *q,int x){
    if (q->rear==q->size-1)
    {
        printf("queue overflow");
    }
    else{
        q->rear++;
        q->A[q->rear]=x;
    }
}

int dequeue(struct queue *q){
 int x=-1;
    if(q->front==q->rear){
        printf("stack underflow");
    }
    else{
        q->front++;
        x=q->A[q->front];
    }
    return x;
}

void display(struct queue q){
    for (int i = q.front+1; i <=q.rear; i++)
    {
        printf("%d\t",q.A[i]);
    }
}
int main(int argc, char const *argv[])
{
    struct queue q;
    create (&q,6);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
display(q);
printf("%d",dequeue(&q));
    return 0;
}
