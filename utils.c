#include "./libft/libft.h"
#include "push_swap.h"

void	delete_list(t_list **stack)
{
    t_list	*tmp;

    if (*stack == NULL)
        return ;
    tmp = *stack;
    while (*stack != NULL)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

void	check_duplicate(t_list *stack_a, int value)
{
    while (stack_a->next != NULL)
    {
        if (stack_a->content == value)
            write_error();
        stack_a = stack_a->next;
    }
}

void	check_sorted(t_list **stack_a)
{
    t_list	*current;
    t_list	*next;

    current = *stack_a;
    next = current->next;
    while (next != NULL)
    {
        if (current->content > next->content)
            return ;
        current = current->next;
        next = next->next;
    }
    exit(0);
}

void	check_inverted(t_list **stack_a)
{
    t_list	*current;
    t_list	*next;

    current = *stack_a;
    next = current->next;
    while (next != NULL)
    {
        if (current->content < next->content)
            return ;
        current = current->next;
        next = next->next;
    }
    swap_a(stack_a);
}

void	initialize_list(t_list **stack_a, int argc, char **argv, int i)
{
    t_list	*new_node;

    new_node = NULL;
    while (i < argc)
    {
        new_node = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(stack_a, new_node);
        check_duplicate(*stack_a, new_node->content);
        i++;
    }
    check_sorted(stack_a);
    check_inverted(stack_a);
    new_node = NULL;
}