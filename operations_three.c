#include "./libft/libft.h"

void	reverse_rotate(t_list **stack)
{
    t_list	*last;
    t_list	*second_last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    last = *stack;
    second_last = NULL;
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    last->next = *stack;
    *stack = last;
    second_last->next = NULL;
}

void	reverse_rotate_a(t_list **stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **stack_b)
{
    reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    write(1, "rrr\n", 4);
}