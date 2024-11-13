#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *insert(struct node *head, int data);
struct node *radixsort(struct node *head);
struct node *count(struct node *head, int pos);
int getmax(struct node *head);
void print(struct node *head);

int main() {
    struct node *head = NULL;
    int n;
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);

    while (n--) {
        int data;
        printf("Enter the node data:\n");
        scanf("%d", &data);
        head = insert(head, data);
    }

    head = radixsort(head);

    // Print the sorted linked list
    
    print(head);

    return 0;
}

struct node *insert(struct node *head, int data) {
    struct node *temp = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }

    return head;
}

struct node *radixsort(struct node *head) {
    int pos = 1;
    int max = getmax(head);

    for (; max / pos > 0; pos = pos * 10) {
        head = count(head, pos);
    }

    return head;
}

int getmax(struct node *head) {
    struct node *temp = head;
    int max = temp->data;

    while (temp != NULL) {
        if (max < temp->data) {
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
}

struct node *count(struct node *head, int pos) {
    struct node *count[10] = {NULL};
    struct node *output = NULL;
    struct node *temp = head;

    // Distribute the nodes into count array based on the digit at 'pos' position
    for (temp = head; temp != NULL; temp = temp->next) {
        int index = (temp->data / pos) % 10;
        count[index] = insert(count[index], temp->data);
    }

    // Merge the lists in the count array into a single list
    output = count[0];
    temp = count[0];
    for (int i = 1; i < 10; i++) {
        if (count[i] != NULL) {
            if (temp == NULL) {
                output = count[i];
                
            } else {
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = count[i];
            }
            temp = count[i];
        }
    }

    return output;
}

void print(struct node *head) {
    struct node *ptr = head;
    printf("The sorted values are: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
