#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int x;
} data;

data *Input(data *s, unsigned short int n);
void display(data *s, unsigned short int n);
void search(data *s, unsigned short int n);
void sort(data *s, unsigned short int n);

int main() {
    data *s;
    unsigned short int n, x;

    while(1) {
        printf("\n");
        printf("1. Enter Details\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%hd",&x);

        switch(x) {
            case 1: 
                printf("Enter the no of values: ");
                scanf("%hd",&n);
                s = (data *)malloc(n * sizeof(data));
                s = Input(s, n);
                sort(s, n); 
                break;

            case 2: 
                search(s, n);
                break;

            case 3: 
                display(s, n);
                break;

            case 4: 
                printf("...Exitted code...\n");
                free(s); 
                exit(0);

            default:
                printf("\n...Invalid choice...\n");
                break;
        }
    }
    return 0;   
}   

data *Input(data *s, unsigned short int n) {
    char temp[100];

    for(int i = 0; i < n; i++) {
        printf("\n");
        printf("Enter the value %d: ",i+1);
        scanf("%d",&s[i].x);
    }

    return s;
}

void search(data *s, unsigned short int n) {
    int temp;
    printf("Enter the value to be searched: ");
    scanf("%d",&temp);


    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (s[mid].x == temp) {
            printf("\n...value found...\n");
            printf("Value: %d\n",s[mid].x);
            return;
        } else if (temp > s[mid].x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("\n...Value Not Found...\n");
}

void display(data *s, unsigned short int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", s[i].x);
    }
    printf("\n");
}  

void sort(data *s, unsigned short int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].x > s[j + 1].x) {
                data temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

/* 

Output: 

1. Enter Details
2. Search
3. Display
4. Exit
1
Enter the no of values: 9

Enter the value 1: 48

Enter the value 2: 54

Enter the value 3: 95

Enter the value 4: 47

Enter the value 5: 96

Enter the value 6: 18

Enter the value 7: 64

Enter the value 8: 86

Enter the value 9: 21

1. Enter Details
2. Search
3. Display
4. Exit
3

18 21 47 48 54 64 86 95 96

1. Enter Details
2. Search
3. Display
4. Exit
2
Enter the value to be searched: 21

...value found...
Value: 21

1. Enter Details
2. Search
3. Display
4. Exit
2
Enter the value to be searched: 57

...Value Not Found...

1. Enter Details
2. Search
3. Display
4. Exit
4
...Exitted code...

*/