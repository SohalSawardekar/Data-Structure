#include <stdio.h>
#include <stdlib.h>

struct node {
    float coefficient;
    float power;
    struct node *link;
};

struct node *create_list(struct node *);
struct node *add_node(struct node *);
struct node *insert_term(struct node *, float, float);
struct node *modify_term(struct node *, float, float);
struct node *delete_term(struct node *, float);
struct node *compute_addition(struct node *, struct node *);
struct node *compute_multiplication(struct node *, struct node *);
struct node *display(struct node *);

unsigned short int n;

int main() {
    struct node *s[2];
    unsigned short int x;
    float coeff, power;

    for (int i = 0; i < 2; i++) {
        printf("Enter the no of terms for %dth polynomial: ", i + 1);
        scanf("%hu", &n);
        s[i] = NULL;
        s[i] = create_list(s[i]);
    }

    printf("\n");

    struct node *add_result = compute_addition(s[0], s[1]);
    printf("Addition of polynomials: ");
    display(add_result);

    printf("\n");

    struct node *mul_result = compute_multiplication(s[0], s[1]);
    printf("Multiplication of polynomials: ");
    display(mul_result);

    printf("\n");

    // Insert a term in first polynomial
    Insert: {
    printf("Enter the polynomial to be changes: 1 or 2: ");
    scanf("%hd",&x);
    if(x == 1 || x == 2) {
    printf("Enter coefficient and power to insert: ");
    scanf("%f %f", &coeff, &power);
    s[x-1] = insert_term(s[x-1], coeff, power);
    printf("Modified polynomial after insertion: ");
    display(s[x-1]);
    } else {
        printf("Error... \ntry again\n");
        goto Insert;
    }

    printf("\n");

    }

    // Modify a term in the second polynomial
    Modify: {
    printf("Enter the polynomial to be changed: 1 or 2: ");
    scanf("%hd",&x);
    if(x == 1 || x == 2) {
    printf("Enter power of term to modify: ");
    scanf("%f", &power);
    s[x-1] = modify_term(s[x-1], 2.0, power);
    printf("Modified polynomial after modification: ");
    display(s[x-1]);
    } else {
        printf("Error... \ntry again\n");
        goto Modify;
    }
    
    printf("\n");
    }

    // Delete a term 
    Delete: {
    printf("Enter the polynomial to be changed: 1 or 2: ");
    scanf("%hd",&x);
    if(x == 1 || x == 2) {
    printf("Enter power of term to delete: ");
    scanf("%f", &power);
    s[x-1] = delete_term(s[x-1], power);
    printf("Modified polynomial after deletion: ");
    display(s[x-1]);
    } else {
        printf("Error... \ntry again\n");
        goto Modify;
    }
    }


    printf("\n");

    // Free memory
    for (int i = 0; i < 2; i++) {
        struct node *current = s[i];
        while (current != NULL) {
            struct node *temp = current;
            current = current->link;
            free(temp);
        }
    }
    free(add_result);
    free(mul_result);

    return 0;
}

struct node *create_list(struct node *s) {
    struct node *temp, *current;

    if (n == 0) {
        printf("No of terms are zero\n");
        return s;
    }

    s = (struct node *)malloc(sizeof(struct node));
    current = s;

    for (int i = 0; i < n; i++) {
        temp = (struct node *)malloc(sizeof(struct node));

        printf("Enter the coefficient and power: ");
        scanf("%f %f", &temp->coefficient, &temp->power);

        temp->link = NULL;
        current->link = temp;
        current = temp;
    }

    return s;
}

struct node *add_node(struct node *s) {
     struct node *temp, *p;

    if (s == NULL) {
        printf("Empty polynomial\n");
        return s;
    }

    p = s;
    temp = (struct node *)malloc(sizeof(struct node));

    while (p->link != NULL) {
        p = p->link;
    }

    printf("Enter the coefficient & power: ");
    scanf("%f %f", &temp->coefficient, &temp->power);

    temp->link = NULL;
    p->link = temp;

    return s;
}

struct node *insert_term(struct node *s, float coeff, float power) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->coefficient = coeff;
    temp->power = power;

    // Insert at the beginning
    temp->link = s->link;
    s->link = temp;

    return s;
}

struct node *modify_term(struct node *s, float new_coeff, float power) {
    struct node *p = s->link;

    while (p != NULL) {
        if (p->power == power) {
            p->coefficient = new_coeff;
            break;
        }
        p = p->link;
    }

    return s;
}

struct node *delete_term(struct node *s, float power) {
    struct node *p = s->link;
    struct node *prev = s;

    while (p != NULL) {
        if (p->power == power) {
            prev->link = p->link;
            free(p);
            break;
        }
        prev = p;
        p = p->link;
    }

    return s;
}

struct node *compute_addition(struct node *s1, struct node *s2) {
    struct node *result = NULL;
    struct node *p1 = s1->link;
    struct node *p2 = s2->link;

    while (p1 != NULL && p2 != NULL) {
        if (p1->power == p2->power) {
            float coeff_sum = p1->coefficient + p2->coefficient;
            if (coeff_sum != 0.0) {
                struct node *temp = (struct node *)malloc(sizeof(struct node));
                temp->coefficient = coeff_sum;
                temp->power = p1->power;
                temp->link = result;
                result = temp;
            }
            p1 = p1->link;
            p2 = p2->link;
        } else if (p1->power > p2->power) {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->coefficient = p1->coefficient;
            temp->power = p1->power;
            temp->link = result;
            result = temp;
            p1 = p1->link;
        } else {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->coefficient = p2->coefficient;
            temp->power = p2->power;
            temp->link = result;
            result = temp;
            p2 = p2->link;
        }
    }

    while (p1 != NULL) {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->coefficient = p1->coefficient;
        temp->power = p1->power;
        temp->link = result;
        result = temp;
        p1 = p1->link;
    }

    while (p2 != NULL) {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->coefficient = p2->coefficient;
        temp->power = p2->power;
        temp->link = result;
        result = temp;
        p2 = p2->link;
    }

    return result;
}

struct node *compute_multiplication(struct node *s1, struct node *s2) {
    struct node *result = NULL;
    struct node *p1 = s1->link;

    while (p1 != NULL) {
        struct node *p2 = s2->link;
        while (p2 != NULL) {
            float coeff_mul = p1->coefficient * p2->coefficient;
            float power_sum = p1->power + p2->power;

            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->coefficient = coeff_mul;
            temp->power = power_sum;
            temp->link = result;
            result = temp;

            p2 = p2->link;
        }
        p1 = p1->link;
    }

    return result;
}

struct node *display(struct node *s) {
    struct node *p;

    if (s == NULL) {
        printf("Empty polynomial\n");
        return s;
    }

    p = s;
    while (p != NULL) {
        printf("%.1fx^%.1f", p->coefficient, p->power);
        p = p->link;
        if (p != NULL) {
            printf(" + ");
        }
    }

    printf("\n");

    return s;

}


/*
output:

Enter the no of terms for 1th polynomial: 3
Enter the coefficient and power: 2 5
Enter the coefficient and power: 9 3
Enter the coefficient and power: 5 2
Enter the no of terms for 2th polynomial: 4
Enter the coefficient and power: 1 6
Enter the coefficient and power: 95 5
Enter the coefficient and power: 7 3
Enter the coefficient and power: 61 2

Addition of polynomials: 66.0x^2.0 + 16.0x^3.0 + 97.0x^5.0 + 1.0x^6.0

Multiplication of polynomials: 305.0x^4.0 + 35.0x^5.0 + 475.0x^7.0 + 5.0x^8.0 + 549.0x^5.0 + 63.0x^6.0 + 855.0x^8.0 + 9.0x^9.0 + 122.0x^7.0 + 14.0x^8.0 + 190.0x^10.0 + 2.0x^11.0

Enter the polynomial to be changes: 1 or 2: 1
Enter coefficient and power to insert: 8 2 
Modified polynomial after insertion: 8.0x^2.0 + 2.0x^5.0 + 9.0x^3.0 + 5.0x^2.0

Enter the polynomial to be changed: 1 or 2: 2
Enter power of term to modify: 5
Modified polynomial after modification: 1.0x^6.0 + 2.0x^5.0 + 7.0x^3.0 + 61.0x^2.0

Enter the polynomial to be changed: 1 or 2: 2
Enter power of term to delete: 2
Modified polynomial after deletion: 1.0x^6.0 + 2.0x^5.0 + 7.0x^3.0

*/