/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:45:33 by mshariar          #+#    #+#             */
/*   Updated: 2025/08/29 23:30:48 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	swap_a_check(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	tmp2 = tmp->next;
	*stack_a = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

void	swap_b_check(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	tmp2 = tmp->next;
	*stack_b = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

void	swap_s_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		tmp2 = tmp->next;
		*stack_a = tmp2;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
	}
	tmp = NULL;
	tmp2 = NULL;
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		tmp2 = tmp->next;
		*stack_b = tmp2;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
	}
	return ;
}

void	push_a_check(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	return ;
}

void	push_b_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	return ;
}
