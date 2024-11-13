//polymulti...2
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
void polyMult(struct poly *head1 , struct poly*head2);



int main()
{
    struct poly *head1 = NULL;
    struct poly *head2 = NULL;
    

    printf("Enter 1st polynomial :\n");
    head1 = create(head1);
    printf("Enter 2nd polynomial :\n");
    head2 = create(head2);

     
    printf("\n1st polynomial :\n");
    print(head1);
    printf("\n2nd polynomial : \n");
    print(head2);
    
    printf("\n Multiplication of them :\n");
    polyMult(head1,head2);
   

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
        printf("%.fx^%d",ptr->coef,ptr->expo);
        ptr = ptr->next;
        if(ptr != NULL){
            printf(" + ");
        }
        
    }
}





void polyMult(struct poly *head1 , struct poly*head2)
{

struct poly *temp1 = head1 ;
struct poly *temp2 = head2 ;
struct poly*result = NULL;



while(temp1 != NULL)
{
    temp2 = head2 ;
    while(temp2 != NULL)
    {
        float res1 = temp1->coef*temp2->coef;
        int res2 = temp1->expo + temp2->expo ;
        result = insert(result,res1,res2) ;
        temp2 = temp2->next;
    }
    temp1 = temp1->next;
}


print(result);



}