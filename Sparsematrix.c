#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int row;
    int coulumn;
    struct node *next;
};

struct node *sparse(struct node *head);
struct node *insert(struct node *head, int x, int i, int j);
void print(struct node *head);
struct node *Add(struct node *head1, struct node *head2, struct node *result);

int main()
{

    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *result = NULL;

    printf("Matrix 1 :\n");
    head1 = sparse(head1);
    printf("Matrix 2 :\n");
    head2 = sparse(head2);

    result = Add(head1, head2, result);
    print(result);

    return 0;
}

struct node *sparse(struct node *head)
{

    int n, m, x;
    printf("Enter the size of the matrix NxM (one by one): \n");
    scanf("%d", &n);
    scanf("%d", &m);

    printf("Enter the matrix : \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Enter element at position : (%d,%d)\n", i, j);
            scanf("%d", &x);

            if (x != 0)
            {
                head = insert(head, x, i, j);
            }
        }
    }

    return head;
}

struct node *insert(struct node *head, int x, int i, int j)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    ptr->row = i;
    ptr->coulumn = j;
    ptr->data = x;
    ptr->next = NULL;

    if (head == NULL)
    {

        head = ptr;
    }
    else
    {

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = ptr;
    }

    return head;
}




void print(struct node *head)
{

     struct node *temp = head;
    while (temp != NULL) {
        printf("Element at (%d, %d) : %d\n", temp->row, temp->coulumn, temp->data);
        temp = temp->next;}
}




struct node *Add(struct node *head1, struct node *head2, struct node *result)
{

    struct node *temp1 = head1;
    struct node *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {

        if (temp1->row == temp2->row && temp1->coulumn == temp2->coulumn)
        {

            result = insert(result, temp1->data + temp2->data, temp1->row, temp1->coulumn);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {

            if (temp1->row < temp2->row)
            {
                result = insert(result, temp1->data, temp1->row, temp1->coulumn);
                temp1 = temp1->next;
            }
            else if (temp1->row == temp2->row)
            {

                if (temp1->coulumn < temp2->coulumn)
                {
                    result = insert(result, temp1->data, temp1->row, temp1->coulumn);
                    temp1 = temp1->next;
                }
                else
                {
                    result = insert(result, temp2->data, temp2->row, temp2->coulumn);
                    temp2 = temp2->next;
                }
            }
            else
            {
                result = insert(result, temp2->data, temp2->row, temp2->coulumn);
                temp2 = temp2->next;
            }
        }
    }

    while (temp1 != NULL)
    {
        result = insert(result, temp1->data, temp1->row, temp1->coulumn);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        result = insert(result, temp2->data, temp2->row, temp2->coulumn);
        temp2 = temp2->next;
    }


    return result;
}