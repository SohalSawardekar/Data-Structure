#include <stdio.h>
#include <stdlib.h>
#define MAX 10

enum type_of_record {
    EMPTY, OCCUPIED, DELETED
};

struct employee {
    int empid;
    char name[30];
    int age;
};

struct record {
    struct employee info;
    enum type_of_record status;
};  

typedef struct employee employee;
typedef struct record record;

void insert(employee emprec, record table[]);
int search(int key, record table[]);
void delete(int key, record table[]);
void display(record table[]);
int hash(int key);
int double_hash(int key);

int main() {
    record table[MAX];
    employee emprec;
    int key, x, i;
    
    for(i = 0;i < MAX;i++) 
        table[i].status = EMPTY;

    while(1) {
        printf("\n");
        printf("1. Insert record\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d",&x);

        switch (x) {
            case 1 :
                printf("Enter empid, name, age : ");
                scanf("%d%s%d",&emprec.empid,emprec.name,&emprec.age);
                insert(emprec, table);
                break;

            case 2 :
                printf("Enter a key to be searched : ");
                scanf("%d", &key);
                i = search(key, table);
                if(i == -1)
                    printf("Key not found\n");
                else
                    printf("Key found at index %d\n", i);
                break;

            case 3:
                printf("Enter a key to be deleted\n");
                scanf("%d",&key);
                delete(key, table);
                break;

            case 4:
                display(table);
                break;

            case 5:
                exit(1);

            default:
                printf("...Invalid choice...\n");
                break;
        }
    }

    
    return 0;
}

int search(int key, record table[]){
    int i, h, h1, location;

    h = hash(key);
    h1 = double_hash(key);
    location = h;
    for( i=1; i!=MAX-1; i++ ){
        if( table[location].status == EMPTY )
            return -1;

        if( table[location].info.empid == key)
            return location;

        location = (h + i*h1)%MAX;
    }
    return -1;

}

int hash(int key){
    return (key%MAX);
}

int double_hash(int key) {
    return (7 + (key % (MAX - 7)));
}

void insert(employee emprec, record table[] ){
    int i, location, h, h1;
    int key = emprec.empid;
    
    h = hash(key);
    h1 = double_hash(key);
    location = h;
    
    for( i=1; i!=MAX-1; i++ ) {
        if(table[location].status == EMPTY || table[location].status == DELETED) {
            table[location].info = emprec;
            table[location].status = OCCUPIED;
            printf("Record inserted\n\n");
            return;
        }
        if(table[location].info.empid == key) {
            printf("Duplicate key\n\n");
            return;
        }
        location = (h + i*h1) % MAX;
    }

    printf("Record can't be inserted : Table overFlow\n\n");
}

void delete(int key, record table[]) {
    int location = search(key, table);
    if(location == -1)
        printf("Key not found\n");
    else
        table[location].status = DELETED;
}

void display(record table[]) {
    int i;
    for(i=0; i<MAX; i++){
        printf("[%d] : ",i );

        if(table[i].status==OCCUPIED) {
            printf("Occupied : %d %s",table[i].info.empid, table[i].info.name);
            printf(" %d\n", table[i].info.age);
        } else if(table[i].status==DELETED) {
            printf("Deleted\n");
        } else {
            printf("Empty\n");
        }
    }
}

/* 

Output: 

1. Insert record
2. Search
3. Delete
4. Display
5. Exit
1
Enter empid, name, age : 7515 a 19
Record inserted


1. Insert record
2. Search
3. Delete
4. Display
5. Exit
1
Enter empid, name, age : 4841 b 21
Record inserted


1. Insert record
2. Search
3. Delete
4. Display
5. Exit
1
Enter empid, name, age : 2682 c 22
Record inserted


1. Insert record
2. Search
3. Delete
4. Display
5. Exit
1
Enter empid, name, age : 4943 d 23
Record inserted


1. Insert record
2. Search
3. Delete
4. Display
5. Exit
1   
Enter empid, name, age : 7314 e 24 
Record inserted


1. Insert record
2. Search
3. Delete
4. Display
5. Exit
1
Enter empid, name, age : 8562 f 25
Record inserted


1. Insert record
2. Search
3. Delete
4. Display
5. Exit
1
Enter empid, name, age : 1836 g 26
Record inserted


1. Insert record
2. Search
3. Delete
4. Display
5. Exit
1 
Enter empid, name, age : 5733 h 27
Record inserted


1. Insert record
2. Search
3. Delete
4. Display
5. Exit
1
Enter empid, name, age : 5957 i 28
Record inserted


1. Insert record
2. Search
3. Delete
4. Display
5. Exit
1
Enter empid, name, age : 6174 j 29
Record inserted


1. Insert record
2. Search
3. Delete
4. Display
5. Exit
4
[0] : Occupied : 5733 h 27
[1] : Occupied : 4841 b 21
[2] : Occupied : 2682 c 22
[3] : Occupied : 4943 d 23
[4] : Occupied : 7314 e 24
[5] : Occupied : 7515 a 19
[6] : Occupied : 1836 g 26
[7] : Occupied : 5957 i 28
[8] : Occupied : 6174 j 29
[9] : Occupied : 8562 f 25

1. Insert record
2. Search
3. Delete
4. Display
5. Exit
2
Enter a key to be searched : 7314
Key found at index 4

1. Insert record
2. Search
3. Delete
4. Display
5. Exit
3
Enter a key to be deleted
1836

1. Insert record
2. Search
3. Delete
4. Display
5. Exit
3
Enter a key to be deleted
4841

1. Insert record
2. Search
3. Delete
4. Display
5. Exit
4
[0] : Occupied : 5733 h 27
[1] : Deleted
[2] : Occupied : 2682 c 22
[3] : Occupied : 4943 d 23
[4] : Occupied : 7314 e 24
[5] : Occupied : 7515 a 19
[6] : Deleted
[7] : Occupied : 5957 i 28
[8] : Occupied : 6174 j 29
[9] : Occupied : 8562 f 25

1. Insert record
2. Search
3. Delete
4. Display
5. Exit
5

*/