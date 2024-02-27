#include <stdio.h>
#include <stdlib.h>

struct treenode {
    int info;
    struct treenode *lchild;
    struct treenode *rchild;
};

struct listnode {
    int info;
    struct listnode *next;
};

struct listnode *postptr = NULL;
struct listnode *inptr = NULL;

struct listnode *order(struct listnode *ptr, int c);
struct treenode *construct(struct listnode *inptr, struct listnode *postptr, int num);
int height(struct treenode *ptr);
void levelorder(struct treenode *ptr);
void display(struct treenode *ptr, int level);
int Depth(struct treenode* ptr, int skey, int d);


int main() {
    int num, depth;
    int temp;
    struct treenode *root;

    printf("Enter the number of elements: ");
    scanf("%d",&num);

    printf("\n");
    printf("Enter the inorder arrangement: \n");
    for(int i = 0;i < num;i++) {
        printf("Enter element %d: ",i+1);
        scanf("%d",&temp);
        inptr = order(inptr, temp);
    }

    printf("\n");
    printf("Enter the postorder arrangement: \n");
    for(int i = 0;i < num;i++) {
        printf("Enter element %d: ",i+1);
        scanf("%d",&temp);
        postptr = order(postptr, temp);
    }

    struct listnode *p;
    printf("\nInorder Arrangement: \n");
    p = inptr;
    while(p != NULL) {
        printf("%d  ",p->info);
        p = p->next;
    } printf("\n");

    printf("\nPostorder Arrangement: \n");
    p = postptr;
    while(p != NULL) {
        printf("%d  ",p->info);
        p = p->next;
    } printf("\n");

    root = construct(inptr,postptr,num);
    printf("\nBinary Tree created successfully...\n");
    printf("\n");

    unsigned short int x;

    while(1) {
        printf("\n");
        printf("1. Height of tree\n");
        printf("2. Depth of a node\n");
        printf("3. Level order traversal\n");
        printf("4. Exit\n");
        scanf("%hd",&x);

        switch(x) {
            case 1:
                printf("Height of Binary Tree: %d\n",height(root));
                printf("\n");
                break;
            
            case 2: 
                printf("Enter the node: ");
                scanf("%d",&temp);
                depth = Depth(root,temp,0) - 1;
                if(depth == -1)
                    printf("Element not in tree");
                else 
                    printf("\nDepth of node: %d\n",depth);
                printf("\n");
                break;

            case 3: 
                printf("\nLevel Order Traversal\n");
                levelorder(root);
                printf("\n");
                break;

            case 4:
                printf("Exitted code...\n");
                exit(1);
            
            default:
                printf("Incorrect Choice...\n");
                break;
        }
    }
    return 0;
}

struct treenode *construct(struct listnode *inptr, struct listnode *postptr, int num) {
    struct treenode *temp;
    struct listnode *q, *ptr;
    int i, j;

    if (num == 0)
        return NULL;

    ptr = postptr;

    for(i = 1; i < num; i++) 
        ptr=ptr->next;

    temp=(struct treenode *)malloc(sizeof(struct treenode));
    temp->info = ptr->info;
    temp->lchild = NULL;
    temp->rchild = NULL;

    if (num == 1)
        return temp;

    q = inptr;
    for(i = 0; q->info != ptr->info; i++)
        q = q->next;

    temp->lchild = construct(inptr, postptr, i);

    for(j = 1; j <= i; j++)
        postptr = postptr->next;

    temp->rchild = construct(q->next, postptr, num-i-1);

    return temp;
}   

struct listnode *order(struct listnode *ptr, int c) {
    struct listnode *temp, *p;

    temp = (struct listnode *)malloc(sizeof(struct listnode));
    temp->info = c;
    temp->next = NULL;

    if(ptr == NULL) {
        ptr = temp;
    } else {
        p = ptr;
        while(p->next != NULL) 
            p = p->next;
        p->next = temp;
    }

    return ptr;
}

int height(struct treenode *ptr) {
    int h_left, h_right;

    if (ptr == NULL)
        return 0;
    
    h_left = height(ptr->lchild);
    h_right = height(ptr->rchild);

    if (h_left > h_right)
        return 1 + h_left;
    else
        return 1 + h_right;

}

void levelorder(struct treenode* ptr) {
    int h = height(ptr);
    int i;
    for (i=1; i<=h; i++)
        display(ptr, i);
    printf("\n");
}

void display(struct treenode* ptr, int level){

    if (ptr == NULL)
        return;

    if (level == 1)
        printf("%d ",ptr->info);
    else if(level > 1) {
        display(ptr->lchild, level-1);
        display(ptr->rchild, level-1);
    }

}

int Depth(struct treenode* ptr, int key, int d) {
    if(ptr == NULL) 
        return -1;

    if(ptr->info == key)
        return ++d;
    else if(key < ptr->info)
        d = Depth(ptr->lchild,key,d+1);
    else if(key > ptr->info)
        d = Depth(ptr->rchild,key,d+1);
}



/* 

Enter the number of elements: 15

Enter the inorder arrangement: 
Enter element 1: 12
Enter element 2: 14
Enter element 3: 15
Enter element 4: 27
Enter element 5: 32
Enter element 6: 33
Enter element 7: 38
Enter element 8: 46
Enter element 9: 59
Enter element 10: 62
Enter element 11: 64
Enter element 12: 70
Enter element 13: 77
Enter element 14: 92
Enter element 15: 97

Enter the postorder arrangement:
Enter element 1: 15
Enter element 2: 14
Enter element 3: 12
Enter element 4: 33
Enter element 5: 32
Enter element 6: 27
Enter element 7: 46
Enter element 8: 70
Enter element 9: 64
Enter element 10: 62
Enter element 11: 92
Enter element 12: 77
Enter element 13: 59
Enter element 14: 97
Enter element 15: 38

Inorder Arrangement:
12  14  15  27  32  33  38  46  59  62  64  70  77  92  97

Postorder Arrangement:
15  14  12  33  32  27  46  70  64  62  92  77  59  97  38

Binary Tree created successfully...


1. Height of tree
2. Depth of a node
3. Level order traversal
4. Exit
1
Height of Binary Tree: 7


1. Height of tree
2. Depth of a node
3. Level order traversal
4. Exit
2
Enter the node: 64

Depth of node: 5


1. Height of tree
2. Depth of a node
3. Level order traversal
4. Exit
3

Level Order Traversal
38 27 97 12 32 59 14 33 46 77 15 62 92 64 70


1. Height of tree
2. Depth of a node
3. Level order traversal
4. Exit
4
Exitted code...

*/