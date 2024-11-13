#include <stdio.h>
#include <stdlib.h>

struct poly
{
    float coef;
    int x;
    int y;
    int z;
    int order;
    struct poly *next;
};

struct poly *create(struct poly *head);
struct poly *insert(struct poly *head, float coef, int x, int y, int z, int order);
void print(struct poly *head);


int main()
{

    struct poly *head = NULL;

    head = create(head);
 print(head);

    return 0;
}

struct poly *create(struct poly *head)
{

    float coef;
    int x, y, z, order;
    int n;
    printf("Enter the number of nodes in the multi variable polynomial");
    scanf("%d", &n);

    printf("Enter the polynomial:\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficiant of the term  : %d \n ", i + 1);
        scanf("%f", &coef);
        printf("Enter the value of x exponent of the term : %d\n", i + 1);
        scanf("%d", &x);
        printf("Enter the value of y exponent of the term : %d\n", i + 1);
        scanf("%d", &y);
        printf("Enter the value of z exponent of the term : %d\n", i + 1);
        scanf("%d", &z);
        order = x + y + z;
        head = insert(head, coef, x, y, z, order);
    }

    return head;
}

struct poly *insert(struct poly *head, float coef, int x, int y, int z, int order)
{
    struct poly *ptr = (struct poly *)malloc(sizeof(struct poly));
    ptr->coef = coef;
    ptr->x = x;
    ptr->y = y;
    ptr->z = z;
    ptr->order = order;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
        return head ;
    }
    else
    {

        struct poly *temp = head;

        if (temp->order < ptr->order)
        {
            ptr->next = temp;
            head = ptr;
            return head;
        }
        else
        {

            while (temp->next != NULL && temp->next->order > ptr->order)
            {
                temp = temp->next;
            }

            if (temp->next == NULL)
            {
                temp->next = ptr;
                return head;
            }

            ptr->next = temp->next;
            temp->next = ptr;
            return head;
        }
    }
}


void print(struct poly *head)
{
    struct poly *temp = head ;

    while(temp != NULL)
    {

printf("%.2fx^%dy^%dz^%d",temp->coef,temp->x,temp->y,temp->z);
temp = temp->next ;

if(temp != NULL)
{
    printf(" + ");
}


    }
}