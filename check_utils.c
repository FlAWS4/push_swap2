/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:46:44 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/13 17:09:40 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	check_delete_list(t_list **stack)
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

int	check_dup(t_list *stack_a, int check)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->number == check)
		{
			return (-1);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

int	ok_or_ko(t_list **stack_a)
{
	t_list	*current;
	t_list	*next;

	current = *stack_a;
	next = current->next;
	while (next != NULL)
	{
		if (current->number > next->number)
		{
			return (-1);
		}
		current = current->next;
		next = next->next;
	}
	return (1);
}

void	check_initialize_list(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*new_node;
	int		error;

	error = 0;
	new_node = NULL;
	while (i < argc)
	{
		new_node = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, new_node);
		error = check_dup(*stack_a, new_node->number);
		if (error == -1)
			break ;
		i++;
	}
	if (error == -1)
	{
		check_delete_list(stack_a);
		write_error();
	}
	ok_or_ko(stack_a);
	new_node = NULL;
}
