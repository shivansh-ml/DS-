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
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Sorted Array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    printf("Enter an element you want to search: ");
    int item;
    scanf("%d", &item);
    int bottom = 0;
    int top = n - 1;
    int mid;
    do
    {
        mid = (bottom + top) / 2;
        if (item < a[mid])
        {
            top = mid - 1;
        }
        else if (item > a[mid])
        {
            bottom = mid + 1;
        }
    } while (item != a[mid] && bottom <= top);
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