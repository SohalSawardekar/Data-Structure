#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node {
    int info;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

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
        printf("1. Insert item\n");
        printf("2. Delete item\n");
        printf("3. Peek item\n");
        printf("4. Display items\n");
        printf("5. Exit\n");
        scanf("%hd",&x);

        switch (x)
        {
        case 1:
            printf("Enter the item: \n");
            scanf("%d",&item);
            insert(item);
            break;
        
        case 2:
            printf("Deleted item: %d\n",delete());
            printf("\n");
            break;
        
        case 3:
            printf("First item: %d\n",peek());
            printf("\n");
            break;
        
        case 4:
            display();
            break;
        
        case 5:
            printf("Exited code...\n");
            exit(1);
        
        default:
            printf("Invalid input\n");
            break;
        }
    }
    return 0;
}

int isEmpty() {
    if(front == NULL && rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insert(int item) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("Insufficient memory\n");
        return;
    }
    
    temp->info = item;
    temp->link = NULL;

    if(front == NULL) {
        front = temp;
    } else {
        rear->link = temp;
    }
    rear = temp;
}

int delete() {
    int item;
    struct node *temp;

    if(front == NULL) {
        printf("Empty list\n");
        exit(1);
    }

    temp = front;
    item = temp->info;
    front = front->link;
    free(temp);
    
    return item;        
}

int peek() {
    if(isEmpty()) {
        printf("Queue underflow\n");
        exit(1);
    }

    return (front->info);
}

void display() {
    struct node *temp;
    if(front == NULL) {
        printf("Empty list\n");
        return;
    }

    temp = front;
    while(temp != NULL) {
        printf("%d\n",temp->info);
        temp = temp->link;
    }

    printf("\n");
}

/*

1. Insert item
2. Delete item
3. Peek item
4. Display items
5. Exit
1
Enter the item: 
85

1. Insert item
2. Delete item
3. Peek item
4. Display items
5. Exit
1
Enter the item:
107

1. Insert item
2. Delete item
3. Peek item
4. Display items
5. Exit
1
Enter the item:
105

1. Insert item
2. Delete item
3. Peek item
4. Display items
5. Exit
1
Enter the item:
25

1. Insert item
2. Delete item
3. Peek item
4. Display items
5. Exit
4
85
107
105
25


1. Insert item
2. Delete item
3. Peek item
4. Display items
5. Exit
2
Deleted item: 85


1. Insert item
2. Delete item
3. Peek item
4. Display items
5. Exit
2
Deleted item: 107


1. Insert item
2. Delete item
3. Peek item
4. Display items
5. Exit
4
105
25


1. Insert item
2. Delete item
3. Peek item
4. Display items
5. Exit
5
Exited code...

*/