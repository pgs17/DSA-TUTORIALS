#include <stdio.h>
#include <stdlib.h>

struct array
{
    // int *A;
    int A[20];
    int size;
    int length;
};
void display(struct array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d", arr.A[i]);
    }
}
void append(struct array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}
void insert(struct array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length){
        for(int i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}
void delete(struct array *arr,int index){
    int temp;
    if(index>=0 && index<arr->length){
temp=arr->A[index];
for(int i=index;i<arr->length-1;i++){
arr->A[i]=arr->A[i+1];
    }
    arr->length--;
}}
int linearsearch(struct array arr,int key){
    for(int i=0;i<arr.length;i++){
        if(key==arr.A[i]){
            /* to improve time complexity
            swap the key element with previous element and return i-1 index
            or swap with first element directly and return that index
            */
            return i;
        }
    }
    return -1;// -1 = invalid index
}
int binarysearch(struct array arr,int key){
    int mid;
    int low=0;
   int high=arr.length-1;
 while(low<=high){
    mid=(low+high)/2;
    if(key==arr.A[mid]){
        return mid;
    }
    else if(key<arr.A[mid]){
        high=mid-1;
    }
    else
    low=mid+1;
}
return -1;
}
int get(struct array arr,int index){
    if(index>=0&&index<arr.length){
        return arr.A[index];
    }
    return -1;
}
void set(struct array *arr,int index,int x){
    if(index>=0 && index<arr->length){
        arr->A[index]=x;
    }
}
int max(struct array arr){
    int max=arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}
void reverse(struct array *arr){

    int i,j,temp;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
}
void insertsort(struct array *arr,int x){
    int i=arr->length-1;
    while(i>=0 && arr->A[i]>x){
    arr->A[i+1]=arr->A[i];
    i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}
int issort(struct array arr){
for(int i=0;i<arr.length-1;i++){
    if(arr.A[i]<arr.A[i+1]){
    return 1;  // 1=true
}
return 0;
}}
struct array*  merge(struct array *arr1,struct array *arr2){

    struct array *arr3=(struct array *) malloc(sizeof(struct array));
    int i,j,k;
    i=j=k=0;
    while(i<arr1->length && arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k]=arr1->A[i];
            k++;
            i++;
        }
        else{
            arr3->A[k]=arr2->A[j];
            k++;
            j++;
        }
    }
        for(;i<arr1->length;i++){
            arr3->A[k]=arr1->A[i];
            k++;
        }
        for(;j<arr2->length;j++){
            arr3->A[k]=arr2->A[j];
            k++;
        }
    arr3->length=arr1->length+arr2->length;
    arr3->size=20;
    return arr3;
}
struct array* Union ( struct array *arr1,struct array *arr2){
struct array *arr3=(struct array*) malloc(sizeof(struct array));
int i,j,k;
i=j=k=0;
while(i=arr1->length&& j<arr2->length){
    if(arr1->A[i]<arr2->A[j]){
        arr3->A[k]=arr1->A[i];
i++;
k++;
    }
    else if(arr2->A[j]<arr1->A[i]){
        arr3->A[k]=arr2->A[j];
        k++;
        j++;
    }
    else {
        arr3->A[k]=arr1->A[i];
        k++;
        i++;
    }
}
for(;i<arr1->length;i++){
    arr3->A[k]=arr1->A[i];
    k++;
}
for(;j<arr2->length;j++){
    arr3->A[k]=arr2->A[j];
    k++;
}
arr3->length=k;
arr3->size=20;
return arr3;
}



int main()
{
    struct array arr1 = {{1, 2, 3, 4, 5}, 20, 5}; // do when elements known
                                                 /*   printf("enter size of array:");
                                                    scanf("%d",&arr.size);
                                                    arr.A=(int*)malloc(arr.size*sizeof(int));
                                                    arr.length=0;
                                                    int n;
                                                    printf("enter number of elements:");
                                                    scanf("%d",&n);
                                                    for (int i = 0; i < n; i++)
                                                    {
                                                        scanf("%d",&arr.A[i]);
                                                    }
                                                    arr.length=n; */
    struct array arr2 ={{5,7,8,9,10},20,5};
    struct array *arr3;
    arr3=merge(&arr1,&arr2);
display(*arr3);// pointer he arr3 for value its *
    return 0;
}
