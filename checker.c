/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:46:57 by mshariar          #+#    #+#             */
/*   Updated: 2025/01/29 19:47:00 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	execute_reverse_rotate(t_list **stack_a, t_list **stack_b, char *str)
{
    if (ft_strcmp(str, "rra\n") == 0)
        reverse_rotate_a_checker(stack_a);
    else if (ft_strcmp(str, "rrb\n") == 0)
        reverse_rotate_b_checker(stack_b);
    else if (ft_strcmp(str, "rrr\n") == 0)
        reverse_rotate_both_checker(stack_a, stack_b);
    else
        write_error();
}

void	execute_sort(t_list **stack_a, t_list **stack_b, char *str)
{
    while (str != NULL)
    {
        if (ft_strcmp(str, "sa\n") == 0)
            swap_a_checker(stack_a);
        else if (ft_strcmp(str, "sb\n") == 0)
            swap_b_checker(stack_b);
        else if (ft_strcmp(str, "ss\n") == 0)
            swap_both_checker(stack_a, stack_b);
        else if (ft_strcmp(str, "pa\n") == 0)
            push_a_checker(stack_b, stack_a);
        else if (ft_strcmp(str, "pb\n") == 0)
            push_b_checker(stack_a, stack_b);
        else if (ft_strcmp(str, "ra\n") == 0)
            rotate_a_checker(stack_a);
        else if (ft_strcmp(str, "rb\n") == 0)
            rotate_b_checker(stack_b);
        else if (ft_strcmp(str, "rr\n") == 0)
            rotate_both_checker(stack_a, stack_b);
        else
            execute_reverse_rotate(stack_a, stack_b, str);
        str = ft_get_next_line_gnl(0);
    }
}

void	check_sort(t_list *stack_a)
{
    while (stack_a->next != NULL)
    {
        if (stack_a->content > (stack_a->next)->content)
        {
            write(1, "KO\n", 3);
            return ;
        }
        stack_a = stack_a->next;
    }
    write(1, "OK\n", 3);
    return ;
}

void	check_arguments_checker(int argc, char **argv, t_list **stack_a)
{
    int		size;
    char	**arg;

    arg = NULL;
    size = 0;
    if (argc == 2)
    {
        arg = ft_split(argv[1], ' ');
        while (arg[size] != NULL)
            size++;
        initialize_list_checker(stack_a, size, arg, 0);
        free(arg);
    }
    else if (argc >= 3)
        initialize_list_checker(stack_a, argc, argv, 1);
}

int	main(int argc, char *argv[])
{
    t_list	*stack_a;
    t_list	*stack_b;
    char	*str;

    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        return (0);
    else
        check_arguments_checker(argc, argv, &stack_a);
    str = ft_get_next_line_gnl(0);
    execute_sort(&stack_a, &stack_b, str);
    check_sort(stack_a);
    return (0);
}