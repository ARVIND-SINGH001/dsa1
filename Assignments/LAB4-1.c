#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};

struct node *create(struct node *head);
struct node *insert(struct node *head, int n);
struct node *Add(struct node *head1, struct node *head2, struct node *result);
struct node *resultt(struct node *result, int sum);
void display(struct node *result);

int main()
{
    struct node *head1 = NULL, *head2 = NULL, *result = NULL;

    printf("Number 1 : \n");
    head1 = create(head1);
    printf("Number 2 : \n");
    head2 = create(head2);
    result = Add(head1, head2, result);
    printf("Result : \n");

    display(result);

    return 0;
}

struct node *create(struct node *head)
{
    int n;
    printf("Enter the number of digits in the number: ");
    scanf("%d", &n);
    char A[n];
    printf("Enter the number: ");
    scanf("%s", A);

    // Insert digits in reverse order to handle LSB -> MSB
    for (int i = n - 1; i >= 0; i--)
    {
        head = insert(head, A[i] - '0');
    }

    return head;
}

struct node *insert(struct node *head, int n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->number = n;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }

    return head;
}

struct node *Add(struct node *head1, struct node *head2, struct node *result)
{
    int carry = 0, sum = 0;
    struct node *temp1 = head1, *temp2 = head2;

    // Loop through both lists
    while (temp1 != NULL || temp2 != NULL || carry != 0)
    {
        sum = carry;

        if (temp1 != NULL)
        {
            sum += temp1->number;
            temp1 = temp1->next;
        }

        if (temp2 != NULL)
        {
            sum += temp2->number;
            temp2 = temp2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        result = resultt(result, sum);
    }

    return result;
}

struct node *resultt(struct node *result, int sum)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->number = sum;
    ptr->next = result;
    result = ptr;
    return result;
}

void display(struct node *result)
{
    struct node *temp = result;
    while (temp != NULL)
    {
        printf("%d", temp->number);
        temp = temp->next;
    }
    printf("\n");
}
