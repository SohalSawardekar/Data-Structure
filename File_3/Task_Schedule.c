#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

struct TASK {
    int TaskId;
    char TaskTitle[20];
    int TaskDuration;
    char Status;
};

#define max 5
struct TASK *queue[max];
int front = -1;
int rear = -1;

void insert(struct TASK *);
struct TASK *delete();
int isFull();
int isEmpty();
void display();

int main() {
    struct TASK tasks[10];
    int taskCount = 10; 
    int taskScheduled = 0; 
    unsigned short int x, t;
    
    task: {
        printf("Enter the no of tasks: ");
        scanf("%hd",&t);
        if(t > 10) {
            printf("only 10 task avalable\nTry again...\n");
            goto task;
        }      
    }

    //  Inputing Tasks
    for (int i = 0; i < t && i < taskCount; i++) {
        printf("\n");
        printf("Enter Task ID: ");
        scanf("%d", &tasks[i].TaskId);
        printf("Enter Task Title: ");
        scanf("%s", tasks[i].TaskTitle);
        printf("Enter Task Duration (in seconds): ");
        scanf("%d", &tasks[i].TaskDuration);
        status: {
            printf("Enter Task Status (Idle/I, Queued/Q, Completed/C): ");
            scanf(" %c", &tasks[i].Status);
        }


        if(tasks[i].Status == 'Q') {
            if(taskScheduled < 5) {
                insert(&tasks[i]);
                printf("Task Added to queue\n");
                taskScheduled++;
            } else {
                printf("Queue is full put status as Idle...\n");
                goto status;
            }
        }
    }

    while (1) {
        printf("\n");
        printf("1. Add task to queue\n");
        printf("2. Run task from queue\n");
        printf("3. Display queued tasks\n");
        printf("4. Exit\n");
        scanf("%hd", &x);

        switch (x) {
            p: {
            case 1:
                if (taskScheduled < max) {
                    int taskId;
                    printf("Enter the task ID to schedule: ");
                    scanf("%d", &taskId);
                    int found = 0;

                    for (int i = 0; i < taskCount; i++) {
                        if (tasks[i].TaskId == taskId) {
                            if (tasks[i].Status != 'Q' && tasks[i].Status != 'C') {
                                insert(&tasks[i]);
                                tasks[i].Status = 'Q';
                                taskScheduled++;
                                printf("Task scheduled successfully.\n");
                            } else {
                                printf("Task is already queued or completed.\n");
                            }
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Task ID not found.\n");
                    }
                } else {
                    printf("Queue is full. Please wait for some time.\n");
                    printf("\n");
                    if (!isEmpty()) {
                    struct TASK *p = delete();
                    printf("Running Task ID: %d\n", p->TaskId);
                    printf("Task Title: %s\n", p->TaskTitle);
                    printf("Task Duration: %d seconds\n", p->TaskDuration);
                    printf("\n");
                    printf("Task Running...\n");
                    sleep(p->TaskDuration);
                    printf("Task completed.\n");
                    p->Status = 'C';
                    taskScheduled--;
                }
                goto p;
                }
                break;

            }

            case 2:
                if (!isEmpty()) {
                    struct TASK *p = delete();
                    printf("Running Task ID: %d\n", p->TaskId);
                    printf("Task Title: %s\n", p->TaskTitle);
                    printf("Task Duration: %d seconds\n", p->TaskDuration);
                    printf("\n");
                    printf("Task Running...\n");
                    sleep(p->TaskDuration);
                    printf("Task completed.\n");
                    p->Status = 'C';
                    taskScheduled--;
                } else {
                    printf("Queue is empty. No task to run.\n");
                }
                break;

            case 3:
                printf("Queued Tasks: \n");
                display();
                break;

            case 4:
                printf("Exited code...\n");
                exit(1);

            default:
                printf("Error...\n");
                break;
        }
    }
    return 0;
}

int isFull() {
    if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (front == -1 && rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

void insert(struct TASK *t) {
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

    queue[rear] = t;
}

struct TASK *delete() {
    struct TASK *item;
    if (isEmpty()) {
        printf("Queue underflow\n");
        exit(1);
    }

    item = queue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == max - 1) {
        front = 0;
    } else {
        front++;
    }

    return item;
}

void display() {
    struct TASK *p;
    if (isEmpty()) {
        printf("Empty queue\n");
        return;
    }

    int i = front;

    printf("\n");
    if (front <= rear) {
        for (; i <= rear; i++) {
            p = queue[i];
            printf("Task ID: %d\n", p->TaskId);
            printf("Task Title: %s\n", p->TaskTitle);
            printf("Task Duration: %d seconds\n", p->TaskDuration);
            printf("Task Status: %c\n", p->Status);
            printf("\n");
        }
    } else {
        for (; i <= max - 1; i++) {
            p = queue[i];
            printf("Task ID: %d\n", p->TaskId);
            printf("Task Title: %s\n", p->TaskTitle);
            printf("Task Duration: %d seconds\n", p->TaskDuration);
            printf("Task Status: %c\n", p->Status);
            printf("\n");
        }
        i = 0;
        for (; i <= rear; i++) {
            p = queue[i];
            printf("Task ID: %d\n", p->TaskId);
            printf("Task Title: %s\n", p->TaskTitle);
            printf("Task Duration: %d seconds\n", p->TaskDuration);
            printf("Task Status: %c\n", p->Status);
            printf("\n");
        }
    }

    printf("\n");
}


/*

Enter the no of tasks: 6

Enter Task ID: 1
Enter Task Title: a
Enter Task Duration (in seconds): 5
Enter Task Status (Idle/I, Queued/Q, Completed/C): Q
Task Added to queue

Enter Task ID: 2
Enter Task Title: b
Enter Task Duration (in seconds): 6
Enter Task Status (Idle/I, Queued/Q, Completed/C): I

Enter Task ID: 3
Enter Task Title: c
Enter Task Duration (in seconds): 7
Enter Task Status (Idle/I, Queued/Q, Completed/C): I

Enter Task ID: 4
Enter Task Title: d
Enter Task Duration (in seconds): 10
Enter Task Status (Idle/I, Queued/Q, Completed/C): Q
Task Added to queue

Enter Task ID: 5
Enter Task Title: e
Enter Task Duration (in seconds): 5
Enter Task Status (Idle/I, Queued/Q, Completed/C): Q
Task Added to queue

Enter Task ID: 6
Enter Task Title: f
Enter Task Duration (in seconds): 3
Enter Task Status (Idle/I, Queued/Q, Completed/C): Q
Task Added to queue

1. Add task to queue
2. Run task from queue
3. Display queued tasks
4. Exit
3
Queued Tasks:

Task ID: 1
Task Title: a
Task Duration: 5 seconds
Task Status: Q

Task ID: 4
Task Title: d
Task Duration: 10 seconds
Task Status: Q

Task ID: 5
Task Title: e
Task Duration: 5 seconds
Task Status: Q

Task ID: 6
Task Title: f
Task Duration: 3 seconds
Task Status: Q



1. Add task to queue
2. Run task from queue
3. Display queued tasks
4. Exit
1
Enter the task ID to schedule: 3
Task scheduled successfully.

1. Add task to queue
2. Run task from queue
3. Display queued tasks
4. Exit
3
Queued Tasks:

Task ID: 1
Task Title: a
Task Duration: 5 seconds
Task Status: Q

Task ID: 4
Task Title: d
Task Duration: 10 seconds
Task Status: Q

Task ID: 5
Task Title: e
Task Duration: 5 seconds
Task Status: Q

Task ID: 6
Task Title: f
Task Duration: 3 seconds
Task Status: Q

Task ID: 3
Task Title: c
Task Duration: 7 seconds
Task Status: Q



1. Add task to queue
2. Run task from queue
3. Display queued tasks
4. Exit
2
Running Task ID: 1
Task Title: a
Task Duration: 5 seconds

Task Running...
Task completed.

1. Add task to queue
2. Run task from queue
3. Display queued tasks
4. Exit
3
Queued Tasks:

Task ID: 4
Task Title: d
Task Duration: 10 seconds
Task Status: Q

Task ID: 5
Task Title: e
Task Duration: 5 seconds
Task Status: Q

Task ID: 6
Task Title: f
Task Duration: 3 seconds
Task Status: Q

Task ID: 3
Task Title: c
Task Duration: 7 seconds
Task Status: Q



1. Add task to queue
2. Run task from queue
3. Display queued tasks
4. Exit
4
Exited code...

*/