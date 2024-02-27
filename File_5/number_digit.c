#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* addNode(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    return head;
}

void displayList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node* addNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL) {
        int sum = carry + (num1 ? num1->data : 0) + (num2 ? num2->data : 0);
        carry = sum / 10;
        sum = sum % 10;

        result = addNode(result, sum);

        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }

    if (carry > 0) {
        result = addNode(result, carry);
    }

    return result;
}

int main() {
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;

    int number1;
    int number2;

    printf("Enter number 1: ");
    scanf("%d",&number1);
    printf("Enter number 2: ");
    scanf("%d",&number2);

    while (number1 > 0) {
        int digit = number1 % 10;
        num1 = addNode(num1, digit);
        number1 /= 10;
    }

    while (number2 > 0) {
        int digit = number2 % 10;
        num2 = addNode(num2, digit);
        number2 /= 10;
    }

    printf("\n");
    printf("Number 1: ");
    displayList(num1);

    printf("\n");
    printf("Number 2: ");
    displayList(num2);

    struct Node* result = addNumbers(num1, num2);
    printf("\n");
    printf("Sum: ");
    displayList(result);

    printf("\n");
    return 0;
}

/*

Enter number 1: 12345
Enter number 2: 67893

Number 1: 5 4 3 2 1 

Number 2: 3 9 8 7 6 

Sum: 8 3 2 0 8

*/
