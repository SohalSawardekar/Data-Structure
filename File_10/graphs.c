#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n; 
int adj[MAX][MAX];
int state[MAX];
int queue[MAX];
int stack[MAX];
int front = -1, rear = -1, top = -1;

void create_graph();
void BF_Traversal();
void DF_Traversal();
void BFS(int v);
void DFS(int v);
void insert_queue(int vertex);
void push(int v);
int pop();
int delete_queue();
int isEmpty_queue();
int isEmpty_stack();

int main() {
    create_graph();

    printf("\nBreadth first traversal\n");
    BF_Traversal();
    
    printf("\n");

    printf("\nDepth first traversal\n");
    DF_Traversal();
    return 0;
}

int isEmpty_queue() {
    if(front == -1 || front > rear) 
        return 1;
    else 
        return 0;
}

int isEmpty_stack() {   
    if(top == -1) 
        return 1;
    else 
        return 0;
}

void create_graph() {
    int max_edges, i, origin, destin;

    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    max_edges = n*(n-1);

    for(i = 1;i <= max_edges;i++) {
        printf("Enter the Edge %d: [Enter -1 & -1 to exit]",i);
        scanf("%d%d",&origin, & destin);
        if(origin == -1 && destin == -1) 
            break;
        if(origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid Vertex!\n");
            i--;
        }
        else 
            adj[origin][destin] = 1;
    } 
}

void BF_Traversal() {
    int v;

    for(v = 0; v < n; v++) 
        state[v] = initial;
    
    printf("\nEnter the starting vertex: ");
    scanf("%d",&v);
    BFS(v);

    for(v = 0; v < n; v++) {
        if(state[v] == initial)
            BFS(v);
    }
}

void DF_Traversal() {
    int v;
    for(v = 0;v < n;v++) 
        state[v] = initial;
    
    printf("Enter the vertex for Depth first search: ");
    scanf("%d",&v);
    DFS(v);

    for(v = 0;v < n;v++) {
        if(state[v] == initial)
            DFS(v);
    }
}

void BFS(int v) {
    int i;
    insert_queue(v);
    state[v] = waiting;
    while(!isEmpty_queue()) {
        v = delete_queue();
        printf("%d ",v);
        state[v] = visited;
        for(i = 0;i < n;i++) {
            if(adj[v][i] == 1 && state[i] == initial) {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }

    printf("\n");
}

void DFS(int v) {
    int i;
    push(v);
    while(!isEmpty_stack()) {
        v = pop();
        if(state[v] == initial) {
            printf("%d ",v);
            state[v] = visited;
        }

        for(i = n-1;i >= 0;i--) {
            if(adj[v][i] == 1 && state[i] == initial)
                push(i);
        }
    } 

    printf("\n");
}

void insert_queue(int vertex) {
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else {
        if(front == -1) 
            front = 0;
        rear += 1;
        queue[rear] = vertex;
    }
}

int delete_queue() {
    int item;
    if(front == -1 && front > rear) {
        printf("Queue Overflow\n");
        exit(1);
    }

    item = queue[front];
    front += 1;
    return item;
}

void push(int v) {
    if(top == MAX-1) 
        printf("Stack Overflow\n");
    else {
        top += 1;
        stack[top] = v;
    }
}

int pop() {
    int v;
    if(top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }

    v = stack[top];
    top -= 1;
    return v;
}

/* 

Output: 

Enter the number of vertices: 8
Enter the Edge 1: [Enter -1 & -1 to exit]0 1
Enter the Edge 2: [Enter -1 & -1 to exit]0 3
Enter the Edge 3: [Enter -1 & -1 to exit]0 4
Enter the Edge 4: [Enter -1 & -1 to exit]1 2
Enter the Edge 5: [Enter -1 & -1 to exit]1 4
Enter the Edge 6: [Enter -1 & -1 to exit]2 5
Enter the Edge 7: [Enter -1 & -1 to exit]3 4
Enter the Edge 8: [Enter -1 & -1 to exit]3 6
Enter the Edge 9: [Enter -1 & -1 to exit]4 5 
Enter the Edge 10: [Enter -1 & -1 to exit]4 7
Enter the Edge 11: [Enter -1 & -1 to exit]6 4
Enter the Edge 12: [Enter -1 & -1 to exit]6 7
Enter the Edge 13: [Enter -1 & -1 to exit]-1 -1

Breadth first traversal

Enter the starting vertex: 0
0 1 3 4 2 6 5 7


Depth first traversal
Enter the vertex for Depth first search: 0
0 1 2 5 4 7 3 6

*/