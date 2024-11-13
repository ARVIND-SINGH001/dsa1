#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coef;
    int expo;
    struct node *next;
};

struct node *create(struct node *head);
struct node *insert(struct node *head, float coef, int expo);
struct node *Second(struct node *head);
struct node *Add(struct node *head, float coef, int expo);
void display(struct node *head);

int main()
{
    struct node *head = NULL;

    head = create(head);
    head = Second(head);
    display(head);

    return 0;
}

struct node *create(struct node *head)
{
    int n;
    float coef;
    int expo;

    printf("Enter the Number of terms in the 1st polynomial :\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficiant of the term %d :\n ", i + 1);
        scanf("%f", &coef);
        printf("Enter the exponent of the term %d :\n ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coef, expo);
    }

    return head;
}

struct node *insert(struct node *head, float coef, int expo)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
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

        while (temp->next != NULL && temp->next->expo > expo)
        {
            temp = temp->next;
        }

        ptr->next = temp->next;
        temp->next = ptr;
    }

    return head;
}

struct node *Second(struct node *head)
{
    int n;
    float coef;
    int expo;

    printf("Enter the Second polynomial to be added :\n");
    printf("Enter the number of terms in the 2nd :\n ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficiant of the  term %d :\n", i + 1);
        scanf("%f", &coef);
        printf("Enter the exponent  of the term %d :\n", i + 1);
        scanf("%d", &expo);
        head = Add(head, coef, expo);
    }

    return head;
}

struct node *Add(struct node *head, float coef, int expo)
{
    struct node *temp = head;

    if (head->expo < expo)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->coef = coef;
        new->expo = expo;
        new->next = head;
        head = new;
        return head;
    }
    else
    {

        while (temp != NULL)
        {
            if (temp->expo == expo)
            {
                temp->coef = temp->coef + coef;
                return head;
            }

            temp = temp->next;
        }

        temp = head;
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->coef = coef;
        new->expo = expo;
        new->next = NULL;

        while (temp->next != NULL && temp->next->expo > expo)
        {
            temp = temp->next;
        }

        new->next = temp->next;
        temp->next = new;
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    printf("The Final polynomial after Addition is : \n");

    while (temp != NULL)
    {
        printf(" %.1fx^%d", temp->coef, temp->expo);
        temp = temp->next;
        if (temp != NULL)
        {
            printf(" + ");
        }
    }
}