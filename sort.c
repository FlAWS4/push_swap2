#include "./libft/libft.h"
#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
    int		i;
    int		j;
    int		x;
    t_list	*tmp;

    tmp = NULL;
    i = 0;
    j = 0;
    x = 0;
    while (!(i < j && j < x && x > i))
    {
        tmp = *stack_a;
        i = tmp->content;
        tmp = tmp->next;
        j = tmp->content;
        tmp = tmp->next;
        x = tmp->content;
        if ((i > j && j < x && x > i)
            || (i > j && j > x && x < i) || (i < j && j > x && x > i))
            swap_a(stack_a);
        if (i > j && j < x && x < i)
            rotate_a(stack_a);
        if (i < j && j > x && x < i)
            reverse_rotate_a(stack_a);
    }
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
    int	i;

    i = 2;
    while (i-- > 0)
        push_b(stack_a, stack_b);
    sort_three(stack_a);
    move_to_a(stack_a, stack_b);
    search_min(stack_a, ft_lstsize(*stack_a));
}

void	move_to_a(t_list **stack_a, t_list **stack_b)
{
    int	i;
    int	size_a;
    int	size_b;

    i = 0;
    size_a = ft_lstsize(*stack_a);
    size_b = ft_lstsize(*stack_b);
    while (*stack_b != NULL)
    {
        i = find_best_position_b(stack_b, size_b, stack_a, size_a);
        if (i < 0)
            while (i++ < 0)
                reverse_rotate_b(stack_b);
        else if (i > 0)
            while (i-- > 0)
                rotate_b(stack_b);
        push_a(stack_b, stack_a);
        size_a++;
        size_b--;
    }
}

void	move_to_b(t_list **stack_a, t_list **stack_b, int *arr, int max)
{
    int	i;
    int	size_a;

    size_a = ft_lstsize(*stack_a);
    i = find_best_position_a(*stack_a, size_a, arr, max);
    while (i != -1)
    {
        if (i > 0)
        {
            while (i-- > 0)
                rotate_a(stack_a);
        }
        push_b(stack_a, stack_b);
        i = find_best_position_a(*stack_a, --size_a, arr, max);
    }
}