#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 5
float queue[max];
int front = -1;
int rear = -1;
void insert(float);
float delete();
int isFull();
int isEmpty();
void display();

int main() {
    float value;
    unsigned short int x;
    fflush(stdin);

    while(1) {
        printf("\n");
        printf("1. add to queue\n");
        printf("2. delete from queue\n");
        printf("3. display queue\n");
        printf("4. Exit\n");
        scanf("%hd",&x);

        switch(x) {
            case 1:
                printf("Enter the value: ");
                scanf("%f",&value);
                insert(value);
                break;
            
            case 2:
                printf("Element removed: %.2f\n",delete());
                break;
            
            case 3:
                printf("Contents of Queue: \n");
                display();
                break;
            
            case 4:
                printf("Exitted code...\n");
                exit(1);

            default:
                printf("Error...\n");
                break;
        }
    }
    return 0;
}

int isFull() {
    if(front == 0 && rear == max-1 || front == rear + 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if(front == -1 && rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

void insert(float value) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    if (rear == max - 1) {
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = value;
}

float delete() {
    float item;
    if(isEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    }

    item = queue[front];

    if(front == rear) {
        front = -1;
        rear = -1;
    } else if(front == max-1) {
        front = 0;
    } else {
        front++;
    }

    return item;
}

void display() {
    if(isEmpty()) {
        printf("Empty queue\n");
        return;
    }

    int i = front;

    printf("\n");
    if(front <= rear) {
        for(;i <= rear;i++) {
            printf("%.2f\n", queue[i]);
        }
    } else {
        for(;i <= max-1;i++) {
            printf("%.2f\n",queue[i]);
        }
        i = 0;
        for(;i <= rear;i++) {
            printf("%.2f\n",queue[i]);
        }
    }
    
    printf("\n");
}


/*

output:
1. add to queue
2. delete from queue
3. display queue
4. Exit
1
Enter the value: 20

1. add to queue
2. delete from queue
3. display queue
4. Exit
1
Enter the value: 47

1. add to queue
2. delete from queue
3. display queue
4. Exit
1
Enter the value: 90

1. add to queue
2. delete from queue
3. display queue
4. Exit
3
Contents of Queue:

20.00
47.00
90.00


1. add to queue
2. delete from queue
3. display queue
4. Exit
2
Element removed: 20.00

1. add to queue
2. delete from queue
3. display queue
4. Exit
3
Contents of Queue:

47.00
90.00


1. add to queue
2. delete from queue
3. display queue
4. Exit
4
Exitted code...


*/