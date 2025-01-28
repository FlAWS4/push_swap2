#include "./libft/libft.h"
#include "push_swap.h"

static void	check_duplicate_checker(t_list *stack_a, int value)
{
    while (stack_a->next != NULL)
    {
        if (stack_a->content == value)
            write_error();
        stack_a = stack_a->next;
    }
}

static void	check_sorted_checker(t_list **stack_a)
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

void	check_inverted_checker(t_list **stack_a)
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
    swap_a_checker(stack_a);
}

void	initialize_list_checker(t_list **stack_a, int argc, char **argv, int i)
{
    t_list	*new_node;

    new_node = NULL;
    while (i < argc)
    {
        new_node = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(stack_a, new_node);
        check_duplicate_checker(*stack_a, new_node->content);
        i++;
    }
    check_sorted_checker(stack_a);
    check_inverted_checker(stack_a);
    new_node = NULL;
}