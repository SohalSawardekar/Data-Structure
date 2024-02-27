//2*2 martrix
#include<stdio.h>

void strasson(int a[4][4], int b[4][4], int n) {
    int p, q, r, s, t, u, v;
    int c[4][4];

    if (n <= 2) {
        p = (a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
        q = (a[1][0]+a[1][1])*b[0][0];
        r = a[0][0]*(b[0][1]-b[1][1]);
        s = a[1][1]*(b[1][0]-b[0][0]);
        t = (a[0][0]+a[0][1])*b[1][1];
        u = (a[0][1]-a[0][0])*(b[0][0]+b[0][1]);
        v = (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

        c[0][0] = p+q-t+v;
        c[0][1] = r+t;
        c[1][0] = q+s;
        c[1][1] = p+r-q+u;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                printf("%d ", c[i][j]);
            printf("\n");
        }

        printf("\n");
        printf("P: %d ",p);
        printf("Q: %d ",q);
        printf("R: %d ",r);
        printf("S: %d ",s);
        printf("T: %d ",t);
        printf("U: %d ",u);
        printf("V: %d ",v);
        printf("\n");
    }
}

int main() {
    int a[4][4], b[4][4], c[4][4], i, j, n;

    printf("\n");
    printf("Enter dimensions of matrix:");
    scanf("%d", &n);

    printf("\n");
    printf("Enter elements of first matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    printf("\n");
    printf("Enter elements of second matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &b[i][j]);
    }

    printf("\n");
    printf("First matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\n");
    printf("Second matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }

    printf("\n");
    printf("Multiplication\n");
    strasson(a, b, n);

    return 0;
}

