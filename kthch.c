#include <stdio.h>
#include <limits.h>

#define INFINITY INT_MAX
int i = 0;
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char arr[], int low, int high) {
    char pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot)
            right--;

        if (left <= right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }

    swap(&arr[low], &arr[right]);
    return right;
}

void select(char arr[], int n, int k) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int pivotIndex = partition(arr, low, high);
        
        printf("Pass %d: ",++i);
        for (int i = 0; i < n; i++) {
            if (i == pivotIndex)
                printf("\e[1m|%c| \e[0m", arr[i]);
            else
                printf("%c ", arr[i]);
        }
        printf(" Pivot Index: %d\n", pivotIndex);

        if (k - 1 == pivotIndex) {
            return;
        } else if (k - 1 < pivotIndex) {
            high = pivotIndex - 1;
        } else {
            low = pivotIndex + 1;
        }
    }
}

int main() {
    int n;
    printf("\n");
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    char arr[n];

    printf("\n");
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf(" %c", &arr[i]);

    int k;
    printf("\n");
    printf("Enter the value of k to find the kth smallest element: ");
    scanf("%d", &k);
    printf("\n");

    select(arr, n, k);
    printf("\n");
    printf("The %d smallest element is %c\n", k, arr[k - 1]);
    printf("\n\n");

    return 0;
}
