#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

node* mergeSort(node* head);
node* merge(node* left, node* right);
void split(node* source, node** frontRef, node** backRef);

void printList(node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

node* push(node* head, int newData) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

int main() {
    node* head = NULL;
    int data;
    unsigned short int n;

    printf("Enter the no of nodes: ");
    scanf("%hd",&n);

    printf("\nEnter the elements: ");
    for(int i = 0;i < n;i++) {
        scanf("%d",&data);
        head = push(head, data);
    }

    printf("Original linked list: ");
    printList(head);

    head = mergeSort(head);

    printf("Sorted linked list: ");
    printList(head);

    return 0;
}

node* mergeSort(node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    node* front;
    node* back;
    split(head, &front, &back);

    front = mergeSort(front);
    back = mergeSort(back);

    return merge(front, back);
}

node* merge(node* left, node* right) {
    node* result = NULL;

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

void split(node* source, node** frontRef, node** backRef) {
    node* fast;
    node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

/*

Output: 

Enter the no of nodes: 16

Enter the elements: 62 46 40 89 70 95 25 51 80 43 58 56 33 35 48 97
Original linked list: 97 48 35 33 56 58 43 80 51 25 95 70 89 40 46 62 
Sorted linked list: 25 33 35 40 43 46 48 51 56 58 62 70 80 89 95 97 

*/