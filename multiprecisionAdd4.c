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
    char A[n + 1], R[n + 1]; // Add 1 for null terminator
    printf("Enter the number: ");
    scanf("%s", A);

    // Reverse the input string
    for (int i = n - 1, j = 0; i >= 0 && j < n; i--, j++)
    {
        R[j] = A[i];
    }
    R[n] = '\0'; // Add null terminator

    // Insert nodes into linked list, grouping digits in sets of four
    int i = 0;
    while (i < n)
    {
        int num = 0;
        int multiplier = 1000;
        // Process up to 4 digits
        for (int k = 0; k < 4 && i < n; k++, i++)
        {
            num += (R[i] - '0') * multiplier;
            multiplier /= 10;
        }
        head = insert(head, num);
    }

    return head;
}

struct node *insert(struct node *head, int n)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    ptr->number = n;
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

struct node *Add(struct node *head1, struct node *head2, struct node *result) {
    int carry = 0;
    int sum = 0;

    
    struct node *temp1 = head1, *temp2 = head2;
    
    // Traverse both linked lists and add corresponding digits
    while (temp1 != NULL || temp2 != NULL || carry != 0) {
        sum = carry;

        if (temp1 != NULL) {
            sum += temp1->number;
            temp1 = temp1->next;
        }

        if (temp2 != NULL) {
            sum += temp2->number;
            temp2 = temp2->next;
        }

        carry = sum / 10000;  // Calculate carry for the next position
        sum = sum % 10000;    // Keep only the last 4 digits

        // Add the sum as a new node to the result list
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
    int arr[100]; // Assuming the maximum number of nodes won't exceed 100
    int i = 0;

    // Collect all node values in an array
    while (temp != NULL)
    {
        arr[i] = temp->number;
        temp = temp->next;
        i++;
    }

    // Print the numbers in reverse order
    for (int j = i - 1; j >= 0; j--)
    {
        if (j < i - 1)
        {
            printf("%04d", arr[j]); // Print with leading zeros for intermediate nodes
        }
        else
        {
            printf("%d", arr[j]); // Print without leading zeros for the first number
        }
    }
    printf("\n");
}
