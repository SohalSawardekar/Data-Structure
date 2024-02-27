//Quick Sort
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void displayArray(int arr[], int n, int p, int a, int b){
    int i;
    printf("(");
    for (i = 0; i < n; i++) {
        if (p == i)
            printf("\e[1m%d\e[m%c ", arr[i], (i == n - 1) ? ')' : ',');
        else if (i == a || i == b)
             printf("%d%c ", arr[i], (i == n - 1) ? ')' : ',');
        else
            printf("%d%c ", arr[i], (i == n - 1) ? ')' : ',');
    }
    printf("\n");
}

int partition(int arr[], int n, int low, int high) {
    int v = arr[low], i = low, j = high + 1, p;
    displayArray(arr, n, low, -1, -1);
    do{
        do {
            i = i + 1;
        } while (i <= high && arr[i] <= v);
        do {
            j = j - 1;
        } while (j >= low && arr[j] > v);
        if (i < j) {
            p = arr[i];
            arr[i] = arr[j];
            arr[j] = p;
            displayArray(arr, n, low, i + 1, j - 1);
        }
    } while (i < j);
    arr[low] = arr[j];
    arr[j] = v;
    return j;
}

void quickSort(int arr[], int n, int low, int high) {
    if (low < high) {
        int pivloc = partition(arr, n, low, high);
        if (pivloc != low)
            displayArray(arr, n, pivloc, -1, -1);
        quickSort(arr, n, low, pivloc - 1);
        quickSort(arr, n, pivloc + 1, high);
    }
}

int main() {
    int n, i, *arr;
    printf("Enter number of elements in the array : ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements in the array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    arr[n] = INT_MAX;
    quickSort(arr, n, 0, n - 1);
    printf("\n");
    printf("After sorting the array is : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
