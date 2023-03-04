#include<iostream>
using namespace std;
class node {
public :
int data;
node *next;
};
class linkedlist{
private :
node *first;
public:
linkedlist(){
    first=NULL;
}
linkedlist(int A[],int n);
~linkedlist();

void display();
int length();
void insert(int index,int x);
};
linkedlist :: linkedlist(int A[],int n){
    node *t,*last;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    last = first;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last =t;
    }
}
linkedlist ::~linkedlist(){
    node *p=first;
    while (first)
    {
        first = first->next;
        delete p;
        p=first;
    }
    
}
void linkedlist ::display(){
    node *p=first;
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }
}
int linkedlist ::length(){
    node *p=first;
    int len=0;
    while (p)
    {
        len++;
        p=p->next;
    }
    cout<<"length is "<<len<<endl;
    }
void linkedlist::insert(int index,int x){
    node *p=first;
    node *t;
    if(index <0 || index > length()){
        return ;
    }
    else{
    t=new node;
    t->data=x;
    t->next=NULL;
    if(index ==0){
        t->next=first;
        first =t;
    }
    else{
        for (int i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
}
int main(int argc, char const *argv[])
{
    int A[]={10,20,30,40,50};
    linkedlist l(A,5);
    l.insert(3,35);
    l.display();
    l.length();
    return 0;
}
