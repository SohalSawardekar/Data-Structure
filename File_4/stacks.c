#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node {
    int info;
    struct node *link;
};

struct node *top = NULL;

void insert(int);
int delete();
int peek();
int isEmpty();
void display();

int main() {
    int item;
    unsigned short int x;

    while(1) {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%hd",&x);

        switch (x) {
            case 1:
                printf("\n");
                printf("Enter the value: ");
                scanf("%d",&item);
                insert(item);
                break;
            
            case 2:
                printf("\n");
                printf("Deleted value: %d\n",delete());
                break;
            
            case 3:
                printf("\n");
                printf("value: %d\n",peek());
                break;
            
            case 4:
                printf("\n");
                display();
                break;
            
            case 5:
                printf("Exitted...\n");
                exit(1);
            
            default:
                printf("Invalid input...\n");
                break;
        }
    }
    printf("\n");
    return 0;
}

int isEmpty() {
    if(top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insert(int item) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->info = item;
    temp->link = top;
    top = temp;
}

void display() {
    struct node *p;

    if(isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }

    p = top;
    while(p != NULL) {
        printf("%d\n",p->info);
        p = p->link;
    }

    printf("\n");
}

int peek() {
    if(isEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    }

    return (top->info);
}

int delete() {
    struct node *p;
    int item;

    if(isEmpty()) {
        printf("stack underflow\n");
        exit(1);
    }

    p = top;

    item = p->info;
    top = p->link;
    free(p);

    return item;
}
