//Binary Search tree using recursive method
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lchild;
    struct node *rchild;
};

struct node* insert(struct node* ptr, int skey);
struct node* search(struct node* ptr, int ikey);
struct node* delete(struct node* ptr, int dkey);
void inorder(struct node* ptr);
void preorder(struct node* ptr);
void postorder(struct node* ptr);
struct node* min_key(struct node *ptr);
struct node* max_key(struct node *ptr);

int main() {
    struct node *root = NULL, *ptr;
    int data;
    unsigned short int x;

    while(1) {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Preorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Display Min and Max values\n");
        printf("8. Exit\n");
        scanf("%hd",&x);

        switch (x) {
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter the data: ");
                scanf("%d",&data);
                root = delete(root, data);
                break;
            
            case 3:
                printf("Enter the element: ");
                scanf("%d",&data);
                ptr = search(root, data);
                if(ptr == NULL)
                    printf("Element not found\n");
                else
                    printf("Element found\n");
                break;

            case 4:
                printf("Preorder: \n");
                preorder(root);
                printf("\n");
                break;
            
            case 5:
                printf("Inorder: \n");
                inorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder: \n");
                postorder(root);
                printf("\n");
                break;
            
            case 7:
                ptr = min_key(root);
                if(ptr != NULL)
                    printf("Min value: %d\n",ptr->info);
                printf("\n");
                ptr= max_key(root);
                if(ptr != NULL)
                    printf("Min value: %d\n",ptr->info);
                printf("\n");   
                break;

            case 8:
                printf("Exitted code...\n");
                exit(1);
            
            default:
                printf("Invalid choice...\n");
                break;
        }
    }

    return 0;
}

void inorder(struct node* ptr) {
    if(ptr == NULL) 
        return ;
    inorder(ptr->lchild);
    printf(" %d ",ptr->info);
    inorder(ptr->rchild);
}

void preorder(struct node* ptr) { 
    if(ptr == NULL)
        return;
    printf(" %d ",ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void postorder(struct node* ptr) {
    if(ptr == NULL) 
        return;
    
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf(" %d ",ptr->info);   
}

struct node* insert(struct node* ptr, int ikey) {
    if(ptr == NULL) {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = ikey;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    } else if(ikey < ptr->info) {
        ptr->lchild = insert(ptr->lchild, ikey);
    }else if(ikey > ptr->info) {
        ptr->rchild = insert(ptr->rchild, ikey);
    } else {
        printf("Duplicate Key\n");
    }

    return ptr;
}

struct node* search(struct node* ptr, int skey) {
    if(ptr == NULL) {
        printf("Key Not found\n");
        return ptr;
    } 
    
    else if(skey < ptr->info)
        return search(ptr->lchild,skey);
    else if(skey > ptr->info) 
        return search(ptr->rchild,skey);
    else 
        return ptr; 
}

struct node* delete(struct node* ptr, int dkey) {
    struct node *temp, *succ;
    if(ptr == NULL) {
        printf("key not present in the tree\n");
        return ptr;
    }

    if(dkey < ptr->info) 
        ptr->lchild = delete(ptr->lchild,dkey);
    else if(dkey > ptr->info)
        ptr->rchild = delete(ptr->rchild,dkey);
    else {
        if(ptr->lchild != NULL && ptr->rchild != NULL) {
            succ = ptr->rchild;
            while(succ->lchild != NULL)
                succ = succ->lchild;
            ptr->info = succ->info;
            ptr->rchild = delete(ptr->rchild,succ->info);     
        } else {
            temp = ptr;
            if(ptr->lchild != NULL) 
                ptr = ptr->lchild;
            else if(ptr->rchild != NULL)
                ptr = ptr->rchild;
            else
                ptr = NULL;
            free(temp);
        }
    }

    return ptr;
}

struct node* min_key(struct node *ptr) {
    if(ptr == NULL)
        return NULL;
    else if(ptr->lchild == NULL) 
        return ptr;
    else
        return min_key(ptr->lchild);   
}

struct node* max_key(struct node *ptr) {
    if(ptr == NULL) 
        return NULL;
    else if(ptr->rchild == NULL) 
        return ptr;
    else
        return max_key(ptr->rchild);
}


/*

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 43

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 52

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 86

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
88
Invalid choice...

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 81

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 57

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 62

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 25

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 10

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 73

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 19

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 45

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 61

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 12

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
1
Enter the data: 95

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
4
Preorder:
 43  25  10  19  12  52  45  86  81  57  62  61  73  95

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
5
Inorder:
 10  12  19  25  43  45  52  57  61  62  73  81  86  95

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
6
Postorder:
 12  19  10  25  45  61  73  62  57  81  95  86  52  43

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
7
Min value: 10

Min value: 95


1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
3
Enter the element: 62
Element found

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
3
Enter the element: 95
Element found

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
3
Enter the element: 100
Key Not found
Element not found

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
2
Enter the data: 81

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
4
Preorder:
 43  25  10  19  12  52  45  86  57  62  61  73  95

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
5
Inorder:
 10  12  19  25  43  45  52  57  61  62  73  86  95

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
6
Postorder:
 12  19  10  25  45  61  73  62  57  95  86  52  43

1. Insert
2. Delete
3. Search
4. Preorder Traversal
5. Inorder Traversal
6. Postorder Traversal
7. Display Min and Max values
8. Exit
8
Exitted code...

*/