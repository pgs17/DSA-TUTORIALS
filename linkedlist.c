#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
};

struct node *first=NULL;


void create(int A[],int n){
    struct node *t,*last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;

for(int i=1;i<n;i++){
    t=(struct node *)malloc(sizeof(struct node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
}
}

void display(struct node *p){
    while (p!=NULL)
    {
        printf("element is %d\n",p->data);
        p=p->next;
    }
    
}
void recdisplay(struct node *p){
    if(p!=NULL){
        printf("%d\n",p->data);
        recdisplay(p->next);
    }
}
int count(struct node *p){
    int c=0;
    while (p!=NULL)
    {
        c++;
        p= p->next;
    }
    return c;
}
int reccount(struct node *p){
    if(p==NULL){
        return 0;
    }
    else {
        return reccount(p->next)+1;
    }
}

int add(struct node *p){
    int sum=0;
    while(p!=NULL){
        sum = sum + p->data;
        p=p->next;
    }
    return sum;
}
int recadd(struct node *p){
    if(p==NULL){
        return 0;
    }
    else{
        return recadd(p->next) + p->data;
    }
}
int maxi(struct node *p){
    int m=-3;
    while (p!=NULL)
    {
        if(p->data>m){
            m=p->data;
        }
        p=p->next;
    }
    return m;
}
struct node * search(struct node *p,int key){
    while (p!=NULL)
    {
        if(key==p->data){
            return p;
        }
       p = p->next;
    }
    return NULL;
    
}
struct node * lsearch(struct node *p,int key){
    struct node *q=NULL;
    while(p!=NULL){
        if(key==p->data){
q->next=p->next;
p->next=first;
first=p;
return first;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void insert(struct node *p,int index,int x){
    struct node *t;
    if( index <0 || index >count(p) ){
        return ;
    }
    else{
        t= (struct node *)malloc(sizeof(struct node));
        t->data=x;
        if(index==0){
            t->next=first;
            first=t;
        }
        else{
            for(int i =0;i<index-1;i++){
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
        }

    }
}
void insertsort(struct node *p,int x){
    struct node *t,*q;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=t;
    }
    else{
        while (p!=NULL && p->data < x)
        {
        q=p;
        p=p->next;
        }
        if(p==first){    // if stopped at first node 
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }

        }
        
    }
int delete(struct node *p,int index){
    if(index <0 || index >count(p)){
        return -1;
    }
    else{
        struct node *p,*q;
        int x;
        if(index==1){
            p=first;
            first =first->next;
            x=p->data;
            free(p);
        }
        else{
            p=first;
            q=NULL;
            for (int i = 0; i < index-1 && p ; i++)
            {
                q=p;
                p=p->next;
            }
            if(p){
                q->next=p->next;
                x=p->data;
                free(p);
            }
        }
        return x;
    }
}
int issorted(struct node *p){
    int x=0;
    while (p!=NULL)
    {
        if(p->data < x){
            return -1;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
    
}
void removeduplicate(struct node *p){
    struct node *q;
    q=first->next;
    while (q!=NULL)
    {
    if(p->data!=q->data){
        p=q;
        q=q->next;
    }
    else{
        p->next=q->next;
        free(q);
        q=p->next;
    }
    }
    
}
void reverse1(struct node *p){
    struct node *q=NULL;
    struct node *r=NULL;
while(p!=NULL){
    r=q;
    q=p;
    p=p->next;
    q->next=r;
}
first=q;
}
void revrec(struct node *q,struct node *p){
    if(p!=NULL){
        revrec(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}
int main(int argc, char const *argv[])
{
    struct node *s;
    int A[]={10,20,40,40,50};
    create(A,5);
    /*s=lsearch(first,7);
    if(s!=NULL){
        printf("key is found");
    }
    else{
        printf("key not found");
    } */
   revrec(NULL,first);
   display(first);
    
    return 0;
}
