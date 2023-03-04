#include <stdio.h>
#include <stdlib.h>
struct node {
struct node *prev;
int data;
struct node *next;
}*first = NULL;
void create (int A[],int n){
    struct node *t,*last=NULL;
first = (struct node *)malloc(sizeof(struct node));
first->data=A[0];
first->next=first->prev=NULL;
last = first;

for(int i=1;i<n;i++){
    t=(struct node*)malloc(sizeof(struct node)); // insert at end
    t->data=A[i];
    t->next=last->next;
    t->prev=last;
    last->next=t;
    last=t;
}
}
void reverse(struct node *p){
    struct node *temp;
    while (p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL ){
            first =p;
        }
    }
}
void display(struct node *p){
    while (p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    
}
int length(struct node *p){
    int len=0;
    while (p)
    {
        len++;
        p=p->next;
    }
    return len;
    
}
void insert(struct node *p,int index,int x){
    struct node *t;
    if(index<0 || index > length(p)){
        return ;
    }
    else{
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        if(index ==0){
            t->prev=NULL;
            t->next=first;
            first->prev=t;
            first=t;
        }
        else{
            for(int i=0;i<index-1;i++){
                p=p->next;
            }
            t->next=p->next;
            t->prev=p;
            if(p->next){
                p->next->prev=t;
            }
            p->next=t;
        }

    }
}
int main(int argc, char const *argv[])
{
    int A[]={10,20,30,40,50};
    create(A,5);
    insert(first,1,24);
    display(first); 
    return 0;
}
