#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
  
typedef struct node {
    struct node *left;
    int val;
    struct node *right;
    int balance;
} node;

node *leftRotate(node *pptr) {
    node *aptr;
    aptr = pptr->right;
    pptr->right = aptr->left;
    aptr->left = pptr;
    return aptr;
}

node *rightRotate(node *pptr) {
    node *aptr;
    aptr = pptr->left;
    pptr->left = aptr->right;
    aptr->right = pptr;
    return aptr;
}

node *del(node *, int);
node *insert(node *pptr, int x);
node *insert_right_check(node *pptr, int *ptaller);
node *insert_RightBalance(node *pptr);
node *insert_left_check(node *pptr, int *ptaller);
node *insert_LeftBalance(node *pptr);
node *del_rightbalance(node *pptr, int *pshorter);
node *del_left_check(node *pptr, int *pshorter);
node *del_leftbalance(node *pptr, int *pshorter);
node *del_right_check(node *pptr, int *pshorter);
void search(node *ptr, int skey);
void min(node *ptr);
void max(node *ptr);
void inorder(node *);

int main() {
    node *root = NULL;
    int choice, key;

    while (1) {
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. Inorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = del(root, key);
                break;
            
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(root, key);
                break;

            case 4:
                min(root);
                break;
            
            case 5:
                max(root);
                break;

            case 6:
                inorder(root);
                break;

            case 7:
               exit(1); 

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

node *insert(node *pptr, int x) {
    static int ptaller;

    if (pptr == NULL) {
        pptr = (node *)malloc(sizeof(node));
        pptr->val = x;
        pptr->left = NULL;
        pptr->right = NULL;
        pptr->balance = 0;
        ptaller = true;
    } else if (x < pptr->val) {
        pptr->left = insert(pptr->left, x);
        if (ptaller)
            pptr = insert_left_check(pptr, &ptaller);
    } else if (x > pptr->val) {
        pptr->right = insert(pptr->right, x);
        if (ptaller)
            pptr = insert_right_check(pptr, &ptaller);
    } else {
        printf("Duplicate element\n");
        ptaller = false;
    }
    
    return pptr;
    }

node *insert_right_check(node *pptr, int *ptaller)  {
    switch (pptr->balance) {
        case 1:
            pptr->balance = 0;
            *ptaller = false;
            break;

        case 0:
            pptr->balance = -1;
            break;
        
        case -1:
            pptr = insert_RightBalance(pptr);
            *ptaller = false;
            break;
    }
    return pptr;
}

node *insert_RightBalance(node *pptr) {
    node *aptr, *bptr;
    aptr = pptr->right;
    if (aptr->balance == -1) {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = leftRotate(pptr);
    } else {
        bptr = aptr->left;

        switch (bptr->balance) {
            case -1:
                pptr->balance = 1;
                aptr->balance = 0;
                break;

            case 1:
                pptr->balance = 0;
                aptr->balance = -1;
                break;

            case 0:
                pptr->balance = 0;
                aptr->balance = 0;
        }

        bptr->balance = 0;
        pptr->right = rightRotate(aptr);
        pptr = leftRotate(pptr);
    }
    return pptr;
}

node *insert_left_check(node *pptr, int *ptaller) {
    switch (pptr->balance) {
        case 0:
            pptr->balance = 1;
            *ptaller = false;
            break;

        case -1:
            *ptaller = false;
            pptr->balance = 0;
            break;
        
        case 1:
            pptr = insert_LeftBalance(pptr);
            *ptaller = false;
            break;
    }
    return pptr;
}

node *insert_LeftBalance(node *pptr) {
    node *aptr, *bptr;
    aptr = pptr->left;

    if (aptr->balance == 1) {
        aptr->balance = 0;
        bptr->balance = 0;
        pptr = rightRotate(pptr);
    } else {
        bptr = aptr->right;
        switch (bptr->balance) {
        case -1:
            pptr->balance = 0;
            aptr->balance = 1;
            break;
        
        case 1:
            pptr->balance = -1;
            aptr->balance = 0;
            break;
        
        case 0:
            pptr->balance = 0;
            aptr->balance = 0;
        }

        bptr->balance = 0;
        pptr->left = leftRotate(aptr);
        pptr = rightRotate(pptr);
    }
    return pptr;
}

node *del_rightBalance(node *pptr, int *pshorter) {
    node *bptr, *aptr;
    aptr = pptr->right;

    if (aptr->balance == 0) {
        pptr->balance = -1;
        aptr->balance = 1;
        *pshorter = false;
        pptr = leftRotate(pptr);
    } else if (aptr->balance == -1) {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = leftRotate(pptr);
    } else {
        bptr = aptr->left;
        switch (bptr->balance) {
            case 0:
                pptr->balance = 0;
                aptr->balance = 0;
                break;

            case 1:
                pptr->balance = 0;
                aptr->balance = -1;
                break;

            case -1:
                pptr->balance = 1;
                aptr->balance = 0;
                break;
        }

        bptr->balance = 0;
        pptr->right = rightRotate(aptr);
        pptr = leftRotate(pptr);
    }
    return pptr;
}

node *del_left_check(node *pptr, int *pshorter) {
    switch (pptr->balance) {
        case 0:
            pptr->balance = -1;
            *pshorter = false;
            break;

        case 1:
            pptr->balance = 0;
            break;

        case -1:
            pptr = del_rightBalance(pptr, pshorter);
            break;
    }
    return pptr;
}

node *del_leftbalance(node *pptr, int *pshorter) {
    node *bptr, *aptr;
    aptr = pptr->left;

    if (aptr->balance == 0) {
        pptr->balance = 1;
        aptr->balance = -1;
        *pshorter = false;
        pptr = rightRotate(pptr);
    } else if (aptr->balance == 1) {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = rightRotate(pptr);
    } else {
        bptr = aptr->left;

    switch (bptr->balance) {
        case 0:
            pptr->balance = 0;
            aptr->balance = 0;
            break;

        case 1:
            pptr->balance = -1;
            aptr->balance = 0;
            break;

        case -1:
            pptr->balance = 0;
            aptr->balance = 1;
            break;
    }
    
        bptr->balance = 0;
        pptr->left = leftRotate(aptr);
        pptr = rightRotate(pptr);
    }
    return pptr;
}

node *del_right_check(node *pptr, int *pshorter) {
    switch (pptr->balance) {
        case 0:
            pptr->balance = 1;
            *pshorter = false;
            break;

        case -1:
            pptr->balance = 0;
            break;

        case 1:
            pptr = del_leftbalance(pptr, pshorter);
            break;
    }
    return pptr;
}

node *del(node *pptr, int dkey) {
    node *tmp, *succ;
    static int shorter;

    if (pptr == NULL) {
        printf("Key not present\n");
        shorter = false;
        return pptr;
    }

    if (dkey < pptr->val) {
        pptr->left = del(pptr->left, dkey);
        if (shorter == true)
            pptr = del_left_check(pptr, &shorter);
    } else if (dkey > pptr->val) {
        pptr->right = del(pptr->right, dkey);
        if (shorter == true)
            pptr = del_right_check(pptr, &shorter);
    } else {
        if (pptr->left != NULL && pptr->right != NULL) {
            succ = pptr->right;
            while (succ->left)
                succ = succ->left;
            pptr->val = succ->val;
            pptr->right = del(pptr->right, succ->val);

            if (shorter == true)
                pptr = del_right_check(pptr, &shorter);
        } else {
            tmp = pptr;

            if (pptr->left != NULL)
                pptr = pptr->left;
            else if (pptr->right != NULL)
                pptr = pptr->right;
            else
                pptr = NULL;

            free(tmp);
            shorter = true;
        }
    }
    return pptr;
}

void search(node *ptr, int skey) {
    if (ptr == NULL) {
        printf("Key not found\n");
        return;
    }

    if (skey < ptr->val)
        search(ptr->left, skey);
    else if (skey > ptr->val)
        search(ptr->right, skey);
    else {
        printf("Found element\n");
        return; 
    }
}

void min(node *ptr) {
    if (ptr == NULL) {
        printf("The tree is empty. There is no minimum element.\n");
        return;
    }

    while (ptr->left != NULL) {
    ptr = ptr->left;
    }

    printf("Minimum element is: %d\n", ptr->val);
}

void max(node *ptr) {
    if (ptr == NULL) {
        printf("The tree is empty. There is no maximum element.\n");
        return;
    }

    while (ptr->right != NULL) {
        ptr = ptr->right;
    }

    printf("Maximum element is: %d\n", ptr->val);
}

void inorder(node *root) {
    if (root == NULL)
    return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

/*

Output: 

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 26

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 29

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 44

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 45

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 81

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 61

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 66

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 25

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 87

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 80

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 11

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 86

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 23

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 92

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 33

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 1
Enter key to insert: 94

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 6
11 23 25 26 29 33 44 45 61 66 80 81 86 87 92 94
AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 4
Minimum element is: 11

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 5
Maximum element is: 94

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 3
Enter key to search: 33
Found element

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 2
Enter key to delete: 66

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 6
11 23 25 26 29 33 44 45 61 80 81 86 87 92 94
AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Inorder Traversal
7. Exit
Enter your choice: 7

*/