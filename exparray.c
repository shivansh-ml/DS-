#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char *a;
    int n;
    int count1 = 0, count2 = 0;
    printf("Enter the no of terms in the expression\n");
    scanf("%d", &n);
    getchar();
    a = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '(')
        {
            count1++;
        }
        else if (a[i] == ')')
        {
            count2++;
        }
        else
        {
            continue;
        }
    }
    if(count1==count2)
    {
        printf("The expression is valid\n");
    }
    else
    {
        printf("The expression is not valid\n");
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c", a[i]);
    }

    free(a);
}