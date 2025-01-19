#include <stdio.h>

int main()
{
    int count = 0;
    printf("Enter No of elements in the array: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter elements in the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter an element you want to search: ");
    int item;
    scanf("%d", &item);
    int bottom = 0;
    int top = n - 1;
    int mid;
    mid = (bottom + top) / 2;
    while (item != a[mid] && bottom <= top)
    {
        if (item < a[mid])
        {
            top = mid - 1;
        }
        else if (item > a[mid])
        {
            bottom = mid + 1;
        }
    }
    if (item == a[mid])
    {
        printf("Binary search successful!! located at %d\n", mid);
    }
    else
    {
        printf("Search failed\n");
    }
    return 0;
}