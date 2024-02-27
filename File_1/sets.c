#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node {
    int value;
    struct node* link;
};

struct node *create_node(struct node*);
struct node *add_node(struct node*, int);
void display(struct node*);
struct node *Union(struct node*, struct node*);
struct node *intersection(struct node*, struct node*);
struct node *difference(struct node*, struct node*);

int main() {
    struct node* set[2];
    unsigned short int x;

    //create sets
    for(int i = 0;i < 2;i++) {
        set[i] = NULL;
        set[i] = create_node(set[i]);
    }

   while (1) {
        printf("\n");
        printf("1. Union of sets\n");
        printf("2. Intersection of sets\n");
        printf("3. Difference of sets\n");
        printf("4. Exit\n");
        scanf("%hd",&x);

        switch(x) {
            case 1:
                Union(set[0],set[1]);
                break;
            
            case 2:
                intersection(set[0],set[1]);
                break;
            
            case 3:
                difference(set[0],set[1]);
                break;
            
            case 4:
                printf("Exitted code...\n");
                exit(1);

            default:
                printf("Error...\n");
                break;
        }
   }
   
    printf("\n");

    return 0;
}

struct node *create_node(struct node* s) {
    struct node* temp, *p;
    int info;
    unsigned short int n;
    printf("Enter no of terms: ");
    scanf("%hd",&n);

    if(n == 0) {
        printf("terms = 0\n");
        return s;
    }
    
    //First element
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter element 1: ");
    scanf("%d",&info);
    temp->value = info;
    temp->link = s;
    s = temp;
    
    //Rest elements
    for(int i = 0;i < n-1;i++) {
        printf("Enter element %d: ",i+2);
        scanf("%d",&info);
        add_node(s,info);
    }

    return s;
}

struct node *add_node(struct node* s, int info) {
    struct node* temp, *p;

    temp = (struct node *)malloc(sizeof(struct node));

    p = s;
    while(p->link != NULL) {
        p = p->link;
    } 

    temp->value = info;
    temp->link = NULL;
    p->link = temp;

    return s;
}

void display(struct node *s) {
    struct node *p;

    if (s == NULL) {
        printf("Empty set\n");
        return;
    }

    printf("{ ");
    p = s;
    while (p != NULL) {
        printf("%d", p->value);
        if (p->link != NULL) {
            printf(", ");
        }
        p = p->link;
    }
    printf(" }\n");

    printf("\n");
}
   

struct node *Union(struct node* s1, struct node* s2) {
    struct node *p1;            
    struct node *p2;
    struct node *U1 = NULL;
    struct node *temp;

    p1 = s1;
    p2 = s2;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->value = p1->value;
    temp->link = U1;
    U1 = temp;

    while(p1 != NULL) {
        add_node(U1,p1->value);
        p1 = p1->link;
    }

    while(p2 != NULL) {
        add_node(U1,p2->value);
        p2 = p2->link;
    }


    display(U1);
    return 0;
}

struct node *intersection(struct node* s1, struct node* s2) {
    struct node *p1;
    struct node *p2;
    struct node *I1 = NULL;
    struct node *temp;

    p1 = s1;

    while (p1 != NULL) {
        p2 = s2;
        while (p2 != NULL) {
            if (p2->value == p1->value) {
                int exists = 0;
                struct node *check = I1;
                while (check != NULL) {
                    if (check->value == p1->value) {
                        exists = 1;
                        break;
                    }
                    check = check->link;
                }

                if (!exists) {
                    temp = (struct node *)malloc(sizeof(struct node));
                    temp->value = p1->value;
                    temp->link = I1;
                    I1 = temp;
                }
                break; // Break the inner loop after finding the common element
            }
            p2 = p2->link;
        }

        p1 = p1->link;
    }

    if (I1 == NULL) {
        printf("No intersection\n");
    } else {
        printf("Intersection of sets:\n");
        display(I1);
    }

    return 0;
}

struct node *difference(struct node* s1, struct node* s2) {
    struct node *p1;
    struct node *p2;
    struct node *D1 = NULL;
    struct node *temp;

    p1 = s1;

    while (p1 != NULL) {
        p2 = s2;
        int found = 0;
        while (p2 != NULL) {
            if (p2->value == p1->value) {
                found = 1;
                break;
            }
            p2 = p2->link;
        }

        if (!found) {
            int exists = 0;
            struct node *check = D1;
            while (check != NULL) {
                if (check->value == p1->value) {
                    exists = 1;
                    break;
                }
                check = check->link;
            }

            if (!exists) {
                temp = (struct node *)malloc(sizeof(struct node));
                temp->value = p1->value;
                temp->link = D1;
                D1 = temp;
            }
        }

        p1 = p1->link;
    }

    if (D1 == NULL) {
        printf("No difference\n");
    } else {
        printf("Difference of sets:\n");
        display(D1);
    }

    return 0;
}


/*
Output:

Enter no of terms: 5
Enter element 1: 18
Enter element 2: 56
Enter element 3: 77
Enter element 4: 98
Enter element 5: 156 
Enter no of terms: 3
Enter element 1: 187
Enter element 2: 45 
Enter element 3: 67

1. Union of sets
2. Intersection of sets
3. Difference of sets
4. Exit
1
{ 18, 18, 56, 77, 98, 156, 187, 45, 67 }


1. Union of sets
2. Intersection of sets
3. Difference of sets
4. Exit
2
No intersection

1. Union of sets
2. Intersection of sets
3. Difference of sets
4. Exit
3
Difference of sets:
{ 156, 98, 77, 56, 18 }


1. Union of sets
2. Intersection of sets
3. Difference of sets
4. Exit
4
Exitted code...

*/