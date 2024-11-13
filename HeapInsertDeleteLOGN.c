#include <stdio.h>
#include <stdlib.h>

struct heap
{
    int *arr;
    int capacity;
    int size;
};

struct heap *CreateMaxH(struct heap *maxh, int capacity);
void insert(struct heap *maxh, int x);
void print(struct heap *maxh);
void delete(struct heap *maxh);
void heapify(struct heap *maxh, int i);

int main()
{
    struct heap *maxh = NULL;
    int capacity;
    printf("Enter the no. of the elements in the Heap :\n");
    scanf("%d", &capacity);
    maxh = CreateMaxH(maxh, capacity);

    printf("Enter the elements  of the Heap:\n");
    for (int i = 0; i < maxh->capacity; i++)
    {
        int x;
        scanf("%d", &x);
        insert(maxh, x);
    }

    print(maxh);
    printf("\n");
    delete (maxh);
    printf("After  deletion : \n");
    print(maxh);

    return 0;
}

struct heap *CreateMaxH(struct heap *maxh, int capacity)
{
    maxh = (struct heap *)malloc(sizeof(struct heap));
    maxh->capacity = capacity;
    maxh->size = 0;
    maxh->arr = (int *)malloc(maxh->capacity * sizeof(int));
    return maxh;
}
void insert(struct heap *maxh, int x)
{
    maxh->size++;
    int i = maxh->size - 1;
    maxh->arr[i] = x;

    while (i != 0 && maxh->arr[(i - 1) / 2] < maxh->arr[i])
    {

        int temp = maxh->arr[i];
        maxh->arr[i] = maxh->arr[(i - 1) / 2];
        maxh->arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void print(struct heap *maxh)
{
    for (int i = 0; i < maxh->size; i++)
    {
        printf("%d ", maxh->arr[i]);
    }
}

void delete(struct heap *maxh)
{

    int temp = maxh->arr[maxh->size - 1];
    maxh->arr[maxh->size - 1] = maxh->arr[0];
    maxh->arr[0] = temp;

    maxh->size--;

    heapify(maxh, 0);
}

void heapify(struct heap *maxh, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < maxh->size && maxh->arr[l] > maxh->arr[largest])
    {
        largest = l;
    }
    if (r < maxh->size && maxh->arr[r] > maxh->arr[largest])
    {
        largest = r;
    }

    if (i != largest)
    {
        int temp = maxh->arr[largest];
        maxh->arr[largest] = maxh->arr[i];
        maxh->arr[i] = temp;
        heapify(maxh, largest);
    }
}