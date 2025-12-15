/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:50:21 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/17 19:19:41 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static void	apply_sort_operation(t_list **stack_a, int *vals)
{
	if ((vals[0] > vals[1] && vals[1] < vals[2] && vals[2] > vals[0])
		|| (vals[0] > vals[1] && vals[1] > vals[2] && vals[2] < vals[0])
		|| (vals[0] < vals[1] && vals[1] > vals[2] && vals[2] > vals[0]))
		swap_a(stack_a);
	if (vals[0] > vals[1] && vals[1] < vals[2] && vals[2] < vals[0])
		rotate_a(stack_a);
	if (vals[0] < vals[1] && vals[1] > vals[2] && vals[2] < vals[0])
		reverse_rotate_a(stack_a);
}

void	sort_three_elements(t_list **stack_a)
{
	int		vals[3];
	t_list	*node;

	vals[0] = 0;
	vals[1] = 0;
	vals[2] = 0;
	while (!(vals[0] < vals[1] && vals[1] < vals[2] && vals[2] > vals[0]))
	{
		node = *stack_a;
		vals[0] = node->number;
		node = node->next;
		vals[1] = node->number;
		node = node->next;
		vals[2] = node->number;
		apply_sort_operation(stack_a, vals);
	}
}

void	sort_five_elements(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = 2;
	while (count-- > 0)
		push_b(stack_a, stack_b);
	sort_three_elements(stack_a);
	insert_back_sorted(stack_a, stack_b);
	rotate_min_to_top(stack_a, ft_lstsize(*stack_a));
}

void	insert_back_sorted(t_list **stack_a, t_list **stack_b)
{
	int	optimal_pos;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while (*stack_b != NULL)
	{
		optimal_pos = calculate_target_position(stack_b, size_b,
				stack_a, size_a);
		if (optimal_pos < 0)
		{
			while (optimal_pos++ < 0)
				reverse_rotate_b(stack_b);
		}
		else if (optimal_pos > 0)
		{
			while (optimal_pos-- > 0)
				rotate_b(stack_b);
		}
		push_a(stack_b, stack_a);
		size_a++;
		size_b--;
	}
}

void	transfer_non_lis_to_b(t_list **stack_a, t_list **stack_b,
	int *arr, int len)
{
	int	pos;
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	pos = locate_non_lis_element(*stack_a, size_a, arr, len);
	while (pos != -1)
	{
		if (pos > 0)
		{
			while (pos > 0)
			{
				rotate_a(stack_a);
				pos--;
			}
		}
		push_b(stack_a, stack_b);
		pos = locate_non_lis_element(*stack_a, --size_a, arr, len);
	}
}
