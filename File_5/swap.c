//Swap Adjacent elements
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node *addNode(struct Node* start, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
    } else {
        struct Node* p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
        newNode->prev = p;
    }

    return start;
}

void displayList(struct Node* start) {
    struct Node* p = start;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

}

struct Node *swapAdjacentElements(struct Node* start) {
    struct Node* p = start;
    
    while (p != NULL && p->next != NULL) {
        int temp = p->data;
        p->data = p->next->data;
        p->next->data = temp;
        
        p = p->next->next;
    }

    return start;
}

int main() {
    struct Node* start = NULL;
    unsigned short int n;
    int data;

    printf("Enter the number of nodes: ");
    scanf("%hd",&n);

    for(int i = 0;i < n;i++) {
        printf("\n");
        printf("Enter the element: ");
        scanf("%d",&data);
        start = addNode(start, data);
    }
    

    printf("\n");
    printf("Original List: ");
    displayList(start);
    
    start = swapAdjacentElements(start);
    
    printf("\n");
    printf("After Swapping Adjacent Elements: ");
    displayList(start);
    
    printf("\n");

    return 0;
}


/*

Enter the number of nodes: 6

Enter the element: 10

Enter the element: 20

Enter the element: 30

Enter the element: 40

Enter the element: 50

Enter the element: 60

Original List: 10 20 30 40 50 60

After Swapping Adjacent Elements: 20 10 40 30 60 50

*/