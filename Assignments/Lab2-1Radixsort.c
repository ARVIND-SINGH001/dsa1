#include<stdio.h>



int getmax(int A[], int n);
void radixsort(int A[],int n);
void countsort(int A[] , int n , int pos);
void display(int A[] ,int n);


int main()
{
    int n ;
    printf("Enter the number of elements in the array :\n");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements of the array:\n");

    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&A[i]);
    }

     radixsort(A,n);
     printf("Sorted array\n");
    display(A,n);




}


void radixsort(int A[] , int n)
{

int max = getmax(A,n);

int pos = 1 ;

for(pos = 1 ; (max/pos) > 0 ; pos = pos*10)
{
    countsort(A,n,pos);
}


}



void countsort(int A[] , int n , int pos)
{
    int count[10] = {0} ;
    int B[n];


    for(int i = 0 ; i < n ; i++)
    {
        count[(A[i]/pos)%10]++;
    }

   for(int i = 1 ; i < 10 ; i++)
   {
    count[i] = count[i] + count[i-1];
   }

   
   for(int i = n-1 ; i>= 0 ; i--)
   {

    B[count[(A[i]/pos)%10] - 1] = A[i];
    count[(A[i] / pos) % 10]--;
   }


   for(int i = 0 ; i< n ; i++)
   {
    A[i] = B[i] ;
   }


}



int getmax(int A[],int n )
{
    int max = A[0];

 for(int i = 0 ; i < n ; i++)
 {
    if(A[i] > max)

    {
        max = A[i];
    }
 }

 return max ;

}

void display(int A[] , int n)
{
    for(int i = 0 ;i <n ;i++)
    {
        printf("%d ",A[i]);
    }
}