#include <stdio.h>
#include <string.h>
#define MAX 50

void insertionSort(int arr[], int n);
void printArray(int arr[], int size);

int main() {
    int arr[MAX];
    unsigned short int n;

    printf("Enter the no of elements: ");
    scanf("%hd", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);

    printf("Original array: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

void insertionSort(int arr[], int n) {
    int i, j;
    int key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("\n");
}

/*

Output: 

Enter the no of elements: 9
Enter the elements: 48 54 95 47 96 18 64 86 21 
Original array: 
48 54 95 47 96 18 64 86 21 

Sorted array: 
18 21 47 48 54 64 86 95 96 

*/
