/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:46:44 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/03 18:45:02 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static void	ft_lstcheck_c(t_list *stack_a, int check)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content == check)
			write_error();
		stack_a = stack_a->next;
	}
	return ;
}

static void	ft_lst_order_c(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->content > tmp2->content)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	exit(0);
}

void	ft_check_lst_inverted(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->content < tmp2->content)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	ft_sa_check(stack_a);
	return ;
}

void	ft_check_write_lst(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*tmp;

	tmp = NULL;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, tmp);
		ft_lstcheck_c(*stack_a, tmp->content);
		i++;
	}
	ft_lst_order_c(stack_a);
	ft_check_lst_inverted(stack_a);
	tmp = NULL;
}