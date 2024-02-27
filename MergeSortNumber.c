#include <stdio.h>
#include <stdlib.h>

int arr_size;
int count = -1;
int pass = 0;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if(i == 0 && count != -1) {
            printf("{ ");
        }

        if(i <= count) {
            printf("\e[1m%d\e[m ", arr[i]);
        } 
        
        if(i > count)    
            printf("%d ", arr[i]);

        if(i == count) {
            printf("} ");
        }
    }
        
    if(pass > 0) 
        printf("\tPass: %d",pass);
}

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int low_arr_size = mid - low + 1;                 //Holds size of low_array
    int high_arr_size = high - mid;                   //Holds size of high_array


    // Create temporary arrays
    char low_arr[low_arr_size], high_arr[high_arr_size];


    // Copy data to temporary arrays low_arr[] and high_arr[]
    for (i = 0; i < low_arr_size; i++)
        low_arr[i] = arr[low + i];
    for (j = 0; j < high_arr_size; j++)
        high_arr[j] = arr[mid + 1 + j];


    i = 0;              // Initial index of first subarray
    j = 0;              // Initial index of second subarray
    k = low;            // Initial index of merged subarray
    while (i < low_arr_size && j < high_arr_size) {
        if (low_arr[i] >= high_arr[j]) { // Changed comparison operator to >
            arr[k] = low_arr[i];
            i++;
        } else {
            arr[k] = high_arr[j];
            j++;
        }
        k++;
    }

    // Copying the remaining elements of low_arr[]
    while (i < low_arr_size) {
        arr[k] = low_arr[i];
        i++;
        k++;
    }

    // Copying the remaining elements of high_arr[]
    while (j < high_arr_size) {
        arr[k] = high_arr[j];
        j++;
        k++;
    }

    ++count;
    ++pass;
    printArray(arr , arr_size);
    printf("\n");
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {

    printf("\n");
    printf("Enter the size of array: ");
    scanf("%d", &arr_size);

    int arr[arr_size];

    printf("\n");
    printf("Enter the array: ");
    for(int i = 0; i < arr_size; i++) 
        scanf(" %d", &arr[i]);

    printf("\n");
    printf("Original array: ");
    printArray(arr, arr_size);
    
    printf("\n\n");
    mergeSort(arr, 0, arr_size - 1);

    pass = 0;
    count = -1;

    printf("{\e[1m");
    printArray(arr, arr_size);
    printf("\e[m} \tPass: 11\n");
    

    printf("\n");
    printf("Sorted array: ");
    printArray(arr, arr_size);

    printf("\n\n");
    return 0;
}
