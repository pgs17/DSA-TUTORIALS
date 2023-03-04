#include <stdio.h>
#include <stdlib.h>

struct element {
int i;
int j;
int x;
};

struct sparse {
int n;
int m;
int num;
struct element *ele;
};

void create(struct sparse *s){
    printf("enter dimensions:");
    scanf("%d %d",&s->n,&s->m);
    printf("enter number of non zero elements:");
    scanf("%d",&s->num);
    s->ele=(struct element*)malloc(s->num*sizeof(struct element));
    printf("enter non zero elements:");
    for(int i=0;i<s->num;i++){
        scanf("%d %d %d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
    }
}

struct sparse *add(struct sparse *s1,struct sparse *s2){
    struct sparse *sum;
    sum= (struct sparse*)malloc(sizeof(struct sparse));
    sum->ele=(struct element*)malloc((s1->num + s2->num)*sizeof(struct element));
    int i,j,k;
    i=j=k=0;
    while(i<s1->num && j<s2->num){
        if (s1->ele[i].i<s2->ele[j].i)
        {
            sum->ele[k++]=s1->ele[i++];
        }
        else if(s2->ele[j].i<s1->ele[i].i){
sum->ele[k++]=s2->ele[j++];
        }
        else{
            if(s1->ele[i].j<s2->ele[j].j){
                sum->ele[k++]=s1->ele[j++];
            }
            else if(s2->ele[j].j < s1->ele[i].j){
                sum->ele[k++]=s2->ele[j++];
            }
            else{
                sum->ele[k]=s1->ele[i];
                sum->ele[k++].x=s1->ele[i++].x + s2->ele[j++].x;
            }
        }
        
    }
    for ( ; i < s1->num; i++)
    {
        sum->ele[k++]=s1->ele[i];
    }
    for ( ; i < s2->num ; i++)
    {
        sum->ele[k++]=s2->ele[j];
    }
    sum->n=s1->n;
    sum->m=s1->m;
sum->num=k;
    return sum;
    
}
void display(struct sparse s){
    int i,j,k=0;
    for(i=0;i<s.n;i++){
        for(j=0;j<s.m;j++){
            if(i==s.ele[k].i && j==s.ele[k].j){
                printf("%d",s.ele[k].x);
                k++;
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
    struct sparse s1,s2,*s3;
    create(&s1);
    create(&s2);
    s3=add(&s1,&s2);
    display(*s3);
    return 0;
}
