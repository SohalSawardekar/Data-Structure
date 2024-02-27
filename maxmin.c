#include<stdio.h>
int a[100];
int count = 1;

void MaxMin(int i, int j, int *max, int *min)
{
    int max1, min1;
    if(i == j)
        *max = *min = a[i];
    else if(i == j-1)
    {
        if(a[i] < a[j])
        {
            *max = a[j];
            *min = a[i];
        }
        else
        {
            *max = a[i];
            *min = a[j];
        }
    }
    else
    {
        int mid = ((i + j)/2);
        MaxMin(i, mid, max, min);
        MaxMin(mid+1, j, &max1, &min1);
        if(*max < max1)
            *max = max1;
        if(*min > min1)
            *min = min1;
    }
    printf("\e[1m\ni = %d\tj = %d\t Max = %d\t Min = %d\e[m",i, j, *max, *min);
    count++;
}
int main()
{
    int n, i, max, min;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    MaxMin(0, n-1, &max, &min);
    printf("\n\nMaximum element is: \e[1m%d\e[m ", max);
    printf("\nMinimum element is: \e[1m%d\e[m \n", min);
    return 0;
}
