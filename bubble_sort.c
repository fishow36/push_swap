#include "push_swap.h"

int    *bubble_sort(int  *arr, int len)
{
    int i;
    int j;

    i = 0;
    while(i < len - 1)
    {
        j = i + 1;
        while (j < len)
        {
            if (arr[i] >= arr[j])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
            j++;
        }
        i++;
    }
    return(arr);
}
