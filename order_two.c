#include "./libft/libft.h"
#include "push_swap.h"

int	calculate_needed(int min, int max, int size)
{
    int	i;

    if (min > (size / 2))
        min = min - size;
    if (max > (size / 2))
        max = max - size;
    i = min_number(max, min);
    return (i);
}

int	calculate_needed_b(int max, int size)
{
    if (max > (size / 2))
        max = max - size;
    return (max);
}

int	calculate_needed_a(t_list *stack_a, int cont, int size)
{
    t_list	*tmp;
    int		i;

    tmp = stack_a;
    i = max_or_min(stack_a, cont, size);
    if (i != size + 1)
        return (calculate_needed_b(i, size));
    while (tmp->next != NULL)
        tmp = tmp->next;
    if (cont < stack_a->content && cont > tmp->content)
        return (0);
    i = 1;
    while (!(cont > stack_a->content && cont < (stack_a->next)->content))
    {
        stack_a = stack_a->next;
        i++;
    }
    return (calculate_needed_b(i, size));
}

int	*copy_stack_content(t_list *stack_a, int size)
{
    int	*arr;
    int	i;

    i = 0;
    arr = (int *) malloc (sizeof(int) * size + 1);
    if (!arr)
        write_error();
    while (stack_a != NULL)
    {
        arr[i++] = (stack_a)->content;
        stack_a = (stack_a)->next;
    }
    return (arr);
}

int	*copy_int_array(int	*arr, int size)
{
    int	i;
    int	*cpy;

    i = 0;
    cpy = (int *) malloc (sizeof(int) * size);
    if (!arr || !cpy)
        write_error();
    while (i < size)
    {
        cpy[i] = arr[i];
        i++;
    }
    return (cpy);
}