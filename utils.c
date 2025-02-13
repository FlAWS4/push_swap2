/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:50:36 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/13 22:57:28 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	initialize_lis_and_prev(int *lis, int *prev, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lis[i] = 1;
		prev[i] = -1;
		i++;
	}
}

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

int	check_duplicate(t_list *stack_a, int value)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->number == value)
		{
			return (-1);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

void	check_sorted(t_list **stack_a, int ac, char **av)
{
	t_list	*current;
	t_list	*next;

	current = *stack_a;
	next = current->next;
	while (next != NULL)
	{
		if (current->number > next->number)
			return ;
		current = current->next;
		next = next->next;
	}
	delete_list(stack_a);
	if (ac == 2)
		free_tab(av);
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
		if (current->number < next->number)
			return ;
		current = current->next;
		next = next->next;
	}
	swap_a(stack_a);
}
