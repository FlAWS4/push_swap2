#include "./libft/libft.h"

void	rotate(t_list **stack)
{
    t_list	*last;
    t_list	*first;

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    last = *stack;
    first = *stack;
    while (last->next != NULL)
        last = last->next;
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void	rotate_a(t_list **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}