// Program to take array as input and make heap of  it in O(n);
#include <stdio.h>
#include <stdlib.h>

struct heap
{
    int *arr;
    int size;
    int capacity;
};

void BuildMinHeap(struct heap *minh);
void minHeapify(struct heap *minh, int i);
void swap(int *a, int *b);
void printHeap(struct heap *heap);
struct heap *CreateMinH(struct heap *minh, int size);

void insert(struct heap *minh, int value);

int main()
{
    struct heap *minh = NULL;
    int n;
    printf("Enter the no. of elements of the min heap\n");
    scanf("%d", &n);
    minh = CreateMinH(minh, n);

    printf("Enter the elements for the min heap one by one\n");
    for (int i = 0; i < minh->capacity; i++)
    {
        scanf("%d", &minh->arr[i]);
        minh->size++;
    }
    BuildMinHeap(minh);
    printf("MIN Heap : \n");
    printHeap(minh);
   


    return 0;
}

struct heap *CreateMinH(struct heap *minh, int capacity)
{
    minh = (struct heap *)malloc(sizeof(struct heap));

    minh->capacity = capacity;
    minh->arr = (int *)malloc(sizeof(int) * capacity);
    minh->size = 0 ;

    return minh;
}

void BuildMinHeap(struct heap *minh)
{

    for (int i = (minh->size / 2) - 1; i >= 0; i--)
    {
        minHeapify(minh, i);
    }
}


// heavify the array by it
void minHeapify(struct heap *minh, int i)
{

    int smallest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    if (leftchild < minh->size && minh->arr[leftchild] < minh->arr[smallest])
    {
        smallest = leftchild;
    }

    if (rightchild < minh->size && minh->arr[rightchild] < minh->arr[smallest])
    {
        smallest = rightchild;
    }

    if (smallest != i)
    {

        swap(&minh->arr[i], &minh->arr[smallest]);
        minHeapify(minh, smallest);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printHeap(struct heap *heap)
{
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}



// insert elements in the heap one by one by it , O(logn)
void insert(struct heap *minh, int value)
{
    if (minh->size == minh->capacity)
    {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    // Insert the new element at the end
    minh->size++;
    int i = minh->size - 1;
    minh->arr[i] = value;
 
    // Heapify-up to maintain min-heap property
    while (i != 0 && minh->arr[(i - 1) / 2] > minh->arr[i])
    {
        swap(&minh->arr[i], &minh->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

