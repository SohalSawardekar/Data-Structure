#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char info[50];
    struct node* link;
};

struct node *top = NULL;

int isOperator(char c)  {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int isAlpha(char c)  {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void push(char item[]) {
    struct node* tmp;

    tmp = (struct node*)malloc(sizeof(struct node));

    if (tmp == NULL) {
        printf("Stack overflow");
        return;
    }
    strcpy(tmp->info, item);
    tmp->link = top;
    top = tmp;
}

char* pop() {
    static char item[50];
    struct node* tmp;

    if (top == NULL) {
        printf("Stack underflow");
    }
    strcpy(item, top->info);
    tmp = top;
    top = top->link;
    free(tmp);
    return item;
}

char* postfix_to_infixA(char postfix[]) {
    int len = strlen(postfix);
    int i;

    for (i = 0; i < len; i++) {
        if (postfix[i] == ' ') {
            continue;
        }

        if (isAlpha(postfix[i])) {
            char variable[50];
            sprintf(variable, "%c", postfix[i]);
            push(variable);
        } 

		else if (isOperator(postfix[i])) {
            char op2[100];
            char op1[100];
            strcpy(op2, pop());
            strcpy(op1, pop());
            char expression[200]; 

            sprintf(expression,"(%s%c%s)",op1,postfix[i], op2);
            push(expression);
        }
    }
    return top->info;
}

int main() {
    char postfixExpression[50];

    printf("Enter postfix expression: \n");
    scanf("%s",postfixExpression);

    char* infixExpressionA = postfix_to_infixA(postfixExpression);

    printf("\n");
    printf("infix expression: %s\n", infixExpressionA);

    printf("\n");
    return 0;
}

/*

Enter postfix expression: 
BFCE/EF+A+^^^FE^/

infix expression: ((B^(F^((C/E)^((E+F)+A))))/(F^E))

*/