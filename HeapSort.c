//

#include <stdio.h>
#include <stdlib.h>

struct heap
{
    int *A;
    int size;
    int capacity;
};

struct heap *CreatemaxHeap(struct heap *maxh, int capacity);
void BuildHeap(struct heap *maxh);
void Heapify(struct heap *maxh, int i);       
void HeapSort(struct heap *maxh );
void print(struct heap *heap);

int main()
{

    struct heap *maxh = NULL;
    int capacity;
    printf("Enter the capacity of the max heap : \n ");
    scanf("%d", &capacity);

    maxh = CreatemaxHeap(maxh, capacity);

    printf("Enter  the elements of the max heap :\n");

    for (int i = 0; i < capacity; i++)
    {
        scanf("%d", &maxh->A[i]);
        maxh->size++;
    }

    BuildHeap(maxh);
 printf("MAX Heap : \n");
    print(maxh);
    HeapSort(maxh);
    printf("After sorting by  Heap Sort : \n");
    print(maxh);

    return 0;
}





struct heap *CreatemaxHeap(struct heap *maxh, int capacity)
{

    maxh = (struct heap *)malloc(sizeof(struct heap));
    maxh->capacity = capacity;
    maxh->A = (int *)malloc(sizeof(int) * capacity);
    maxh->size = 0;

    return maxh;
}


void BuildHeap(struct heap *maxh)
{

    for (int i = (maxh->size / 2) - 1; i >= 0; i--)
    {
        Heapify(maxh, i);
    }
}


void Heapify(struct heap *maxh, int i)
{

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < maxh->size && maxh->A[l] > maxh->A[largest])
    {
        largest = l;
    }
    if (r < maxh->size && maxh->A[r] > maxh->A[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        int temp = maxh->A[i];
        maxh->A[i] = maxh->A[largest];
        maxh->A[largest] = temp;
        Heapify(maxh, largest);
    }
}

void HeapSort(struct heap *maxh )
{

    for(int i = maxh->size - 1 ; i >= 0 ; i--)
    {
        int  temp = maxh->A[0];
        maxh->A[0] = maxh->A[i];
        maxh->A[i] = temp ;
        maxh->size--;
        Heapify(maxh,0);

    }
}

void print(struct heap *heap)
{
    for (int i = 0; i < heap->capacity; i++)
    {
        printf("%d ", heap->A[i]);
    }
    printf("\n");
}

