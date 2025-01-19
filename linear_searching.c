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
    printf("Enter an element you wnat to search: ");
    int key; 
    scanf("%d", &key);
    for (int i = 0; i < n; i++)
    {
        if (key == a[i])
        {
            printf("Element is found at index: %d\n", i);
            count++;
        }
    }
    if (count == 0)
        printf("Element is not in the array\n");
}