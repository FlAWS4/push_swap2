/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:46:44 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/10 00:19:44 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static void	check_dup(t_list *stack_a, int check)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->number == check)
			write_error();
		stack_a = stack_a->next;
	}
	return ;
}

static void	check_ok_or_ko(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->number > tmp2->number)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	exit(0);
}

void	check_lst_inverted(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->number < tmp2->number)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	swap_a_check(stack_a);
	return ;
}

void	check_initialize_list(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*tmp;

	tmp = NULL;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, tmp);
		check_dup(*stack_a, tmp->number);
		i++;
	}
	check_ok_or_ko(stack_a);
	check_lst_inverted(stack_a);
	tmp = NULL;
}