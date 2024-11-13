#include <stdio.h>
#include<stdlib.h>
struct poly
{
    float coef;
    int expo;
    struct poly *next;
};

struct poly *create(struct poly *head);
struct poly *insert(struct poly *head, float coef, int expo);
void print(struct poly *head);
void polyAdd(struct poly *head1 , struct poly*head2);



int main()
{
    struct poly *head1 = NULL;
    struct poly *head2 = NULL;
    struct poly *head3 = NULL;

    printf("Enter 1st polynomial :\n");
    head1 = create(head1);
    printf("Enter 2nd polynomial :\n");
    head2 = create(head2);

     
    printf("\n\n1st polynomial :\n");
    print(head1);
    printf("2nd polynomial : \n");
    print(head2);
    
      polyAdd(head1,head2);
    

    return 0;
}

struct poly *create(struct poly *head)
{
    int n;
    float coef;
    int expo;
    printf("Enter the number of terms in the polynomial:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficiant of the term %d : ", i + 1);
        scanf("%f", &coef);
        printf("Enter the exponent of the term %d : ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coef, expo);
    }

    return head;
}

struct poly *insert(struct poly *head, float coef, int expo)
{
    
    struct poly *ptr = malloc(sizeof(struct poly));
    ptr->coef = coef;
    ptr->expo = expo;
    ptr->next = NULL;

    if (head == NULL || head->expo < expo)
    {

        ptr->next = head;
        head = ptr;
    }
    else
    {
        struct poly *temp = head;
        while (temp->next != NULL && temp->next->expo > expo)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;

        return head;
    }
}



void print(struct poly * head)
{
    struct poly * ptr = head ;

    while(ptr != NULL)
    {
        printf("%.f,%d,%p\n",ptr->coef,ptr->expo,ptr->next);
        ptr = ptr->next;
    }
}





void polyAdd(struct poly *head1 , struct poly *head2)
{


struct poly *ptr1 = head1 ;
struct poly *ptr2 = head2 ;
struct poly *head3 = NULL ;


while(ptr1 != NULL && ptr2!= NULL)
{
    if(ptr1->expo == ptr2->expo)
    {
       head3 =  insert(head3,ptr1->coef + ptr2->coef,ptr1->expo);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    else if(ptr1->expo> ptr2->expo)
    {
        head3 = insert(head3,ptr1->coef,ptr1->expo );
        ptr1 = ptr1->next;


    }
    else if(ptr2->expo> ptr1->expo)
    {
        head3 = insert(head3,ptr2->coef,ptr2->expo );
        ptr2 = ptr2->next;
        

    }
}

while(ptr1 != NULL)
{
    head3 = insert(head3,ptr1->coef,ptr1->expo);
    ptr1 = ptr1->next;
}
while(ptr2 != NULL)
{
    head3 = insert(head3,ptr2->coef,ptr2->expo);
    ptr2 = ptr2->next;
}

printf("The addition of the polynomials is : \n");
print(head3);


}