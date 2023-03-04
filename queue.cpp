#include <iostream>
using namespace std;

class queue {
private:
int size;
int front;
int rear;
int *A;
public:
queue(int size);
~queue();
void enqueue(int x);
int dequeue();
void display();
};
queue::queue(int size){
    front =-1;
    rear=-1;
    this->size=size;
    A=new int[size];
}
queue::~queue(){
    delete []A;
}
void queue::enqueue(int x){
    if(rear==size-1){
        cout<<"queue overflow"<<endl;
    }
    rear++;
    A[rear]=x;
}

int queue::dequeue(){
    int x=-1;
    if(front==rear){
        cout<<"queue underflow"<<endl;
    }
    else{
        front++;
        x=A[front];
    }
    return x;
}

void queue::display(){
    for(int i=front +1;i<=rear;i++){
        cout<<A[i]<<" ";
    }
    
}
int main(int argc, char const *argv[])
{
    int p[]={10,20,30,40,50};
    queue q(sizeof(p)/sizeof(p[0]));
    for (int i = 0; i < sizeof(p)/sizeof(p[0]); i++)
    {
        q.enqueue(p[i]);
    }
    q.display();

    cout<<q.dequeue();
    return 0;
}
