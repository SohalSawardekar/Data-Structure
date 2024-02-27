//4*4 matrix
#include<stdio.h>

void strassen(int a[4][4], int b[4][4], int n) {
    if (n == 4) {
        int m1, m2, m3, m4, m5, m6, m7;
        int c[4][4];

        m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
        m2 = (a[1][0] + a[1][1]) * b[0][0];
        m3 = a[0][0] * (b[0][1] - b[1][1]);
        m4 = a[1][1] * (b[1][0] - b[0][0]);
        m5 = (a[0][0] + a[0][1]) * b[1][1];
        m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
        m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

        c[0][0] = m1 + m4 - m5 + m7;
        c[0][1] = m3 + m5;
        c[1][0] = m2 + m4;
        c[1][1] = m1 - m2 + m3 + m6;

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int a[4][4], b[4][4], c[4][4], i, j, n;
    printf("Enter dimensions of matrix (must be 4): ");
    scanf("%d", &n);

    printf("Enter elements of first matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    printf("Enter elements of second matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &b[i][j]);
    }

    printf("First matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("Second matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }

    printf("Multiplication\n");
    strassen(a, b, n);

    return 0;
}
