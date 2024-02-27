#include <stdio.h>
#define MAX 50

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void swap(int* a, int* b);
void printArray(int arr[], int size);

int main() {
    int arr[MAX];
    unsigned short int n;

    printf("Enter the no of elements: ");
    scanf("%hd",&n);

    printf("Enter the elements: ");
    for(int i = 0;i < n;i++)
        scanf("%d",&arr[i]);

    printf("\nOriginal array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("\nSorted array: ");
    printArray(arr, n);

    return 0;
}

void heapify(int arr[], int n, int i) {
    int largest = i;    
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0);     
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*

Output:

Enter the no of elements: 16
Enter the elements: 62 46 40 89 70 95 25 51 80 43 58 56 33 35 48 97

Original array: 62 46 40 89 70 95 25 51 80 43 58 56 33 35 48 97 

Sorted array: 25 33 35 40 43 46 48 51 56 58 62 70 80 89 95 97

*/