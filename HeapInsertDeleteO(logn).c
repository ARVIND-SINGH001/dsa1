#include<stdio.h>
#include<stdlib.h>


struct heap{
    int *arr;
    int capacity;
    int size ;
};



struct heap *CreateMaxH(struct heap *maxh, int capacity);
void insert(struct heap *maxh , int x);
void print(struct heap *maxh);

int main()
{
    struct heap * maxh = NULL;
    int capacity ;
    printf("Enter the no. of the elements in the Heap :\n");
    scanf("%d",&capacity);
    maxh = CreateMaxH(maxh,capacity);


    printf("Enter the elements  of the Heap:\n");
    for(int i = 0 ; i <maxh->capacity ; i++)
    {
        int x ;
        scanf("%d",&x);
        insert(maxh,x);
    }

print(maxh);
    


 return 0 ;   
}


struct heap *CreateMaxH(struct heap *maxh, int capacity)
{
    maxh = (struct heap *)malloc(sizeof(struct heap));
    maxh->capacity = capacity;
    maxh->size = 0 ;
    maxh->arr = (int *)malloc(maxh->capacity * sizeof(int));
    return maxh ;
}
void  insert(struct heap  *maxh , int x)
{
    maxh->size++;
    int i = maxh->size-1 ;
    maxh->arr[i] = x;

    while(i != 0 && maxh->arr[(i-1)/2]  < maxh->arr[i])
    {

int temp = maxh->arr[i];
maxh->arr[i] = maxh->arr[(i-1)/2] ;
maxh->arr[(i-1)/2] = temp ;
i = (i-1)/2 ;

    }

}

void print(struct heap *maxh)
{
    for(int i = 0 ; i < maxh->size ; i++)
    {
        printf("%d ",maxh->arr[i]);
    }
}