#include <stdio.h>
#include <stdlib.h>

struct term {
int coeff;
int exp;
};

struct poly{
int n;
struct term *t;
};

void create(struct poly *p){
    printf("enter number of non zero terms:");
    scanf("%d",&p->n);
    p->t = (struct term *)malloc(p->n*sizeof(struct term));
    printf("enter polynomial terms :\n");
    for(int i=0;i<p->n;i++){
        printf("enter term %d\n",i+1);
        scanf("%d%d",&p->t[i].coeff,&p->t[i].exp);
    }
}
void display(struct poly p){
    for(int i=0;i<p.n;i++){
        printf("%dx%d+",p.t[i].coeff,p.t[i].exp);
        
    }
    printf("\n");
}
struct poly *add(struct poly *p1,struct poly *p2){
    struct poly *p3;
    p3=(struct poly*)malloc(sizeof(struct poly));
    p3->t=(struct term*)malloc((p1->n+p2->n)*sizeof(struct term));
    int i,j,k;
    i=j=k=0;
    while(i<p1->n && j<p2->n){
if(p1->t[i].exp>p2->t[j].exp){
    p3->t[k++]=p1->t[i++];
}
else if(p2->t[j].exp>p1->t[i].exp){
p3->t[k++]=p2->t[j++];
}
else{
    p3->t[k].exp=p1->t[i].exp;
    p3->t[k++].coeff=p1->t[i++].coeff + p2->t[j++].coeff;
}
    }
for(;i<p1->n;i++){
    p3->t[k++]=p1->t[i++];
}
for(;j<p2->n;j++){
    p3->t[k++]=p2->t[j++];
}
    
    p3->n=k;
    return p3;
}

int main()
{
    struct poly p1,p2, *p3;
    create(&p1);
    create(&p2);
    p3 = add(&p1,&p2);
    display(*p3);
    return 0;
}
