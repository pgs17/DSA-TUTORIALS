#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char data;
    struct node *next;
}*top=NULL;

void display(){
    struct node *p=top;
    while (p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    
}
void push(char x){
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL){
        printf("stack is full");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }

}
char pop(){
     struct node *p;
     int x=-1;
     if(top==NULL){
        printf("stack is empty");
     }
     else{
        p=top;
        top=top->next;
        x=p->data;
        free(p);
     }
     return x;
}
int peek(int index){
    struct node *p=top;
    for(int i=0;i<=index-1&&p!=NULL;i++){
        p=p->next;
    }
    if(p){
        return p->data;
    }
    else {
        return -1;
    }
}
int isoperand(char x){
    if(x=='+' || x=='-'||x=='*'|| x=='/'){
        return 0;
    }
    else {
        return 1;
    }
}
int pre(char x){
    if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'|| x=='/'){
        return 2;
    }
    else{
        return 0;
    }
}
int isparanthesismatching(char *exp){
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='(' || exp[i]=='{'||exp[i]=='['){
            push(exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}'|| exp[i]==']'){
            if(top==NULL){
                return 0;
            }
            else{
                char temp=top->data;
                if(top->data==temp){
                    pop();
                }
                else{
                    return 0;
                }
            }
        }
    }
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
char * inftopost(char *infix){
int len = strlen(infix);
char *postfix;
postfix=(char*)malloc((len+1)*sizeof(char));
int i=0,j=0;
while(infix[i]!='\0'){
    if(isoperand(infix[i])){
        postfix[j++]=infix[i++];
    }
    else{
        if(pre(infix[i])>pre(top->data)){
            push(infix[i++]);
            
        }
        else{
            postfix[j++]=pop();
            
        }
    }
}
while(top!=NULL){
    postfix[j++]=pop();
}
postfix[j]='\0';

return postfix;
}
int evaluate(char *postfix){
    int x1,x2,r;
    for (int  i = 0; postfix[i]!='\0'; i++)
    {
        if(isoperand(postfix[i])){
            push(postfix[i]-'0');
        }
        else{
            x2=pop();
            x1=pop();
            switch (postfix[i])
            {
            case '+': r=x1+x2; push(r); break;
            case '-': r=x1-x2; push(r); break;
            case '*': r=x1*x2; push(r); break;
            case '/': r=x1/x2; push (r); break;
            }
        }
    }
    return top->data;
    
}
int main(int argc, char const *argv[])
{char *infix ="{([a+b]*[c-d])/e}";
printf("%d",isparanthesismatching(infix));
    return 0;
}
