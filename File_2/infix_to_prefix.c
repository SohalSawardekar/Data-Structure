#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50

char infix[MAX];
char prefix[MAX];
long int stack[MAX];
int top = -1;

void push(long int symbol) {
    if (top == MAX - 1) {
        printf("Stack Overflow");
        return;
    }
    stack[++top] = symbol;
}

long int pop() {
    if (top == -1) {
        printf("Stack underflow");
        exit(1);
    }
    return stack[top--];
}

int whitespace(char symbol) {
    if (symbol == BLANK || symbol == TAB)
        return 1;
    else
        return 0;
}

int instack_priority(char symbol) {
    switch (symbol) {
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 4;
    }
}

int incoming_priority(char symbol) {
    switch (symbol) {
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    }
}

void infix_to_prefix() {
    int i, p = 0, k;
    char symbol, next, temp;

    printf("Symbol\t\tStack\t\tPrefix\n");
    for (i = strlen(infix) - 1; i >= 0; i--) {
        symbol = infix[i];
        printf("%c\t\t", symbol);

        if (!whitespace(symbol)) {
            switch (symbol) {
            case ')':
                push(symbol);
                break;
            case '(':
                while ((next = pop()) != ')') {
                    prefix[p++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while ((top != -1) && instack_priority(stack[top]) > incoming_priority(symbol)) {
                    prefix[p++] = pop();
                }
                push(symbol);
                break;
            default:
                prefix[p++] = symbol;
                break;
            }
            for(int j=0; j<=top; j++) {
              printf("%c", (int)stack[j]);
            }
            printf("\t\t%s", prefix);
        }
        printf("\n");
    }
    while (top != -1) {
        prefix[p++] = pop();
    }
    prefix[p] = '\0';
    for (i = 0, k = p - 1; i < k; i++, k--) {
        temp = prefix[i];
        prefix[i] = prefix[k];
        prefix[k] = temp;
    }
}

long int power(long int b, long int a) {
    int i;
    long int ans = 1;
    for (i = 1; i <= a; i++) {
        ans = ans * b;
    }
    return ans;
}

float eval_pre() {
    long int a, b, temp, result;
    int i;
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (prefix[i] >= '0' && prefix[i] <= '9') {
            push(prefix[i] - '0');
        } else {
            a = pop();
            b = pop();
            switch (prefix[i]) {
            case '+':
                temp = a + b;
                break;
            case '-':
                temp = a - b;
                break;
            case '*':
                temp = a * b;
                break;
            case '/':
                temp = a / b;
                break;
            case '%':
                temp = (int)a % (int)b;
                break;
            case '^':
                temp = power(b, a);
                break;
            }
            push(temp);
        }
    }
    result = pop();
    return result;
}

int main() {
    float ans;
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    infix_to_prefix();
    printf("Prefix expression is: %s\n", prefix);
    ans = eval_pre();
    printf("\nThe answer is: %0.2f\n", ans);
    return 0;
}


/*

output:
Enter the infix expression:
(2*2+2/(3+2)^1-(3^2^2))
Symbol          Stack           Prefix
)               )
)               ))
2               ))              2
^               ))^             2
2               ))^             22
^               ))^             22^
3               ))^             22^3
(               )               22^3^
-               )-              22^3^
1               )-              22^3^1
^               )-^             22^3^1
)               )-^)            22^3^1
2               )-^)            22^3^12
+               )-^)+           22^3^12
3               )-^)+           22^3^123
(               )-^             22^3^123+
/               )-/             22^3^123+^
2               )-/             22^3^123+^2
+               )-+             22^3^123+^2/
2               )-+             22^3^123+^2/2
*               )-+*            22^3^123+^2/2
2               )-+*            22^3^123+^2/22
(                               22^3^123+^2/22*+-

Prefix expression is: -+*22/2^+321^3^22

The answer is: -58.00


*/