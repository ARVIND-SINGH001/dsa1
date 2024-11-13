#include <stdio.h>
#include <stdlib.h>

struct Minheap
{
    int *arr;
    int size;
};

void BuildMinHeap(struct Minheap *mh);
void minHeapify(struct Minheap *mh , int i);
void swap(int *a , int *b);
void printHeap(struct Minheap *mh);


struct Minheap *CreateMinH(struct Minheap *mh, int size);

int main()
{
    struct Minheap *mh = NULL;
    int n;
    printf("Enter the size of the min heap\n");
    scanf("%d", &n);
    mh = CreateMinH(mh, n);


    printf("Enter the elements for the heap one by one\n");
    for (int i = 0 ; i < mh->size; i++)
    {
        scanf("%d", &mh->arr[i]);
    }
BuildMinHeap(mh);
printHeap(mh);




    return 0;
}

struct Minheap *CreateMinH(struct Minheap *mh, int size)
{
    mh = (struct Minheap *)malloc(sizeof(struct Minheap));

    mh->size = size;
    mh->arr = (int *)malloc(sizeof(int) * size);

    return mh;
}


void BuildMinHeap(struct Minheap *mh)
{

  for (int i = (mh->size / 2) - 1; i >= 0; i--)
   {
        minHeapify(mh, i);
   }


}

void minHeapify(struct Minheap *mh , int i)
{

int smallest = i ;
int leftchild = 2*i + 1;
int rightchild = 2*i + 2 ;

if(leftchild < mh->size && mh->arr[leftchild] < mh->arr[smallest])
{
    smallest = leftchild ;
}

if(rightchild < mh->size && mh->arr[rightchild] < mh->arr[smallest])
{
    smallest = rightchild ;
}

if(smallest != i)
{

swap(&mh->arr[i] ,&mh->arr[smallest]);
minHeapify(mh, smallest);

}

}


void swap(int *a , int *b)
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;

}


void printHeap(struct Minheap *mh)
{
    for(int i = 0 ; i < mh->size ; i++)
    {
        printf("%d ",mh->arr[i]);
    }
    printf("\n");
}