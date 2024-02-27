#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    return head;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

struct Node* deleteAlternateNodes(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* temp;

    do {
        temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    } while (current != head && current->next != head);

    return head;
}

int main() {
    struct Node* head = NULL;
    unsigned short int n;
    int data;

    printf("Enter the value of n: ");
    scanf("%hd",&n);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Enter the value: ");
        scanf("%d",&data);
        head = insertEnd(head, data);
    }

    printf("\n");
    printf("Original List: ");
    displayList(head);

    head = deleteAlternateNodes(head);

    printf("\n");
    printf("List after deleting alternate nodes: ");
    displayList(head);


    printf("\n");

    return 0;
}

/*

Enter the value of n: 5

Enter the value: 10
Enter the value: 20
Enter the value: 30
Enter the value: 40
Enter the value: 50

Original List: 10 20 30 40 50 

List after deleting alternate nodes: 10 30 50 


*/