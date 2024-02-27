#include <stdio.h>
#include <string.h>

int BinSrch(char a[], int i, int l, char x) {
    if (l < i) {              
        return -1; 
    } else { 
        int mid = (i + l) / 2;
        printf("\e[1m%d\t%d\t%d\e[m\n", i, l, mid);
        if (x == a[mid])
            return mid;
        else if (x < a[mid])
            return BinSrch(a, i, mid - 1, x);
        else
            return BinSrch(a, mid + 1, l, x);
    }
}

int main() {
    int n;
    int x;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    char arr[n];

    printf("\nEnter the elements of the array in increasing order:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]); 
    }

    printf("\nEnter the element to search for: ");
    scanf(" %c", &x); 

    printf("\n\nlow\thigh\tmid\n");
    int result = BinSrch(arr, 0, n - 1, x);
    printf("\n\n");
    if (result != -1) {
        printf("\t\e[1m....FOUND...\e[m\n");
        printf("\nElement found at index \e[1m%d\e[m\n", result);
    }
    else
        printf("\e[1mElement not found\e[m\n");

    printf("\n\n");
    return 0;
}

