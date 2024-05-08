//Use calloc to read n numbers and find the mode.

#include <stdio.h>
#include <stdlib.h>
int main() 
{
    printf("Enter number of elements: ");
    int n, i, *p, max_count = 0, mode, *count_array;
    scanf("%d", &n);
    p = (int *)malloc(sizeof(int) * n);
    count_array = (int *)calloc(1000, sizeof(int)); 
    if (p == NULL || count_array == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        count_array[p[i]]++;
    }
    for (i = 0; i < n; i++) 
    {
        if (count_array[p[i]] > max_count) 
        {
            max_count = count_array[p[i]];
            mode = p[i];
        }
    }
    printf("Mode = %d (occurs %d times)\n", mode, max_count);
    free(p);
    free(count_array);
    return 0;
}
