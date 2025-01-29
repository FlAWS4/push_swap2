#include "./libft/libft.h"
#include "push_swap.h"

int	*allocate_and_initialize(int size, int initial_value)
{
    int	*array;
    int	i;

    array = (int *)malloc(sizeof(int) * size);
    if (!array)
        write_error();
    i = 0;
    while (i < size)
    {
        array[i] = initial_value;
        i++;
    }
    return (array);
}

int	*lis_util_helper(int max)
{
    int	*val;

    val = allocate_and_initialize(max + 1, 2147483647);
    val[max - 1] = 2147483647;
    return (val);
}

int	*lis_util(int *dst, int *arr, int max, int size)
{
    int	i;
    int	j;
    int	*val;
    int	found;

    j = size;
    val = lis_util_helper(max - 1);
    while (max-- >= 1)
    {
        i = j;
        found = 0;
        while (--i >= 0)
        {
            if (arr[i] == max && (dst[i] < val[max] || val[max - 1] == 2147483647) && (dst[i] > val[max - 1] || !found))
            {
                val[max - 1] = dst[i];
                j = i;
                found = 1;
            }
        }
    }
    free(arr);
    return (val);
}

int	*define_lis(int *dst, int size, int *max)
{
    int	*arr;
    int	i;
    int	j;

    arr = allocate_and_initialize(size, 1);
    j = 0;
    while (j < size)
    {
        i = j + 1;
        while (i < size)
        {
            if (dst[j] < dst[i] && arr[j] == arr[i])
            {
                arr[i]++;
                if (arr[i] > *max)
                    *max = arr[i];
            }
            i++;
        }
        j++;
    }
    return (lis_util(dst, arr, *max + 1, size));
}