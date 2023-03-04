#include <stdio.h> 
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void create (int A[],int n){
    struct node *last,*t;
head= (struct node *)malloc(sizeof(struct node));
head->data=A[0];
head->next=head;// head itself for circular
last =head;
for(int i=1;i<n;i++){
t=(struct node *)malloc(sizeof(struct node));
t->data=A[i];
t->next=last->next;
last->next=t;
last=t;
}
}
void recdisplay(struct node *p){
    static int flag=1;// flag =1 means 1st time ho raha he;
    if(p!=head || flag ==1){
        flag =2;// second time equal
        printf("%d\t",p->data);
        recdisplay(p->next);
    }
    flag=0;
}
void display(struct node *p){
 do{
    printf("%d\t",p->data);
    p=p->next;
}while(p!=head);
}
void insert(struct node *p,int index,int x){
    struct node *t;
    if(index<0 || index > length(p)){
        return ;
    }
    else {
if(index ==0){
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    if(head==NULL){
        head=t;
        head->next=head;
    }
    else{
        while(p->next!=head){
            p=p->next;
        }
        p->next=t;
        t->next=head;

    }
    
}
else{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    for(int i=0;i<index -1;i++){
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
}
    }
}
int length(struct node *p){
    int len= 0;
    do{
        len ++;
        p=p->next;
    }while(p!=head);
    return len;
}
int delete(struct node *p,int index){
    int x;
    struct node *q;
    if(index<0 || index >length(p)){
        return -1;
    }
    else{

        if( index ==1){
        x= head->data;
            while(p->next!=head){
                p=p->next;
            }
            if(p==head){
                free(p);
                head=NULL;
            }
            else{
                p->next=head->next;
                free(p);
                head=p->next;
            }
        }
        else{
            for (int i = 0; i < index-1; i++)
            {
                p=p->next;
            }
            q=p->next;
            p->next=q->next;
            x=q->data;
            free(q);
        }
        return x;
    }
}
int main(int argc, char const *argv[])
{
    int a[]={1,2,3,4,5,6};
    create(a,6);
    printf("%d",delete(head,4));
    recdisplay(head);
    return 0;
}
