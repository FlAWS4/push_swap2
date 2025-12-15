/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_maxnmin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:13 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/14 22:08:00 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	check_if_extreme_value(int nb, t_extremes *ext, int size)
{
	if (nb > ext->max_val)
		return (ext->max_pos);
	if (nb < ext->min_val)
		return (ext->min_pos);
	return (size + 1);
}

int	find_extremes_and_position(t_list *stack_a, int nb, int size)
{
	t_extremes	ext;

	ext.max_val = stack_a->number;
	ext.min_val = stack_a->number;
	ext.max_pos = 0;
	ext.min_pos = 0;
	ext.curr_pos = 1;
	while (stack_a != NULL)
	{
		if (stack_a->number >= ext.max_val)
		{
			ext.max_val = stack_a->number;
			ext.max_pos = ext.curr_pos;
		}
		if (stack_a->number < ext.min_val)
		{
			ext.min_val = stack_a->number;
			ext.min_pos = ext.curr_pos - 1;
		}
		stack_a = stack_a->next;
		ext.curr_pos++;
	}
	return (check_if_extreme_value(nb, &ext, size));
}

int	get_smaller_absolute(int a, int b)
{
	int	abs_a;
	int	abs_b;

	abs_a = a;
	abs_b = b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a == b)
		return (abs_a);
	if (a < b)
		return (abs_a);
	return (abs_b);
}

int	get_larger_absolute(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	if (b > a)
		return (b);
	else
		return (a);
}

void	rotate_min_to_top(t_list **stack_a, int size)
{
	int		position;
	int		min_pos;
	int		min_val;
	t_list	*node;

	min_pos = 0;
	position = 0;
	node = *stack_a;
	min_val = node->number;
	while (position < size)
	{
		if (min_val > node->number)
		{
			min_val = node->number;
			min_pos = position;
		}
		node = node->next;
		position++;
	}
	node = NULL;
	position = compute_moves_for_stack_b(min_pos, size);
	execute_combined_rotations(position, 0, stack_a, &node);
}
/*
printf("max_n_min: [%d, %d, %d, %d, %d]\n",
 max_n_min[0], max_n_min[1], max_n_min[2], max_n_min[3], max_n_min[4]);
printf("Updated max_n_min: [%d, %d, %d, %d, %d]\n", max_n_min[0], 
max_n_min[1], max_n_min[2], max_n_min[3], max_n_min[4]);
		printf("stack->a: %d\n",stack_a->number);
*/