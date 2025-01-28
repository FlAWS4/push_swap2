#include "./libft/libft.h"
# include "push_swap.h"

void	swap_top_two(t_list **stack)
{
    t_list	*first;
    t_list	*second;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    *stack = second;
    first->next = second->next;
    second->next = first;
    write(1, "swap\n", 5);
}

void	swap_a(t_list **stack_a)
{
    swap_top_two(stack_a);
    write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
    swap_top_two(stack_b);
    write(1, "sb\n", 3);
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
    swap_top_two(stack_a);
    swap_top_two(stack_b);
    write(1, "ss\n", 3);
}

void	push_to_stack(t_list **src, t_list **dest)
{
    t_list	*tmp;

    if (!src || !*src)
        return ;
    tmp = *src;
    *src = (*src)->next;
    tmp->next = *dest;
    *dest = tmp;
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
    push_to_stack(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
    push_to_stack(stack_a, stack_b);
    write(1, "pb\n", 3);
}