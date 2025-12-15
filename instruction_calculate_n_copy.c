/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_calculate_n_copy.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:24 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/17 19:34:37 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	calculate_rotation_cost(int min, int len, int size)
{
	int	result;

	if (min > (size / 2))
		min = min - size;
	if (len > (size / 2))
		len = len - size;
	result = get_smaller_absolute(len, min);
	return (result);
}

int	compute_moves_for_stack_b(int len, int size)
{
	if (len > (size / 2))
		len = len - size;
	return (len);
}

int	compute_moves_for_stack_a(t_list *stack_a, int nb, int size)
{
	t_list	*node;
	int		idx;

	node = stack_a;
	idx = find_extremes_and_position(stack_a, nb, size);
	if (idx != size + 1)
		return (compute_moves_for_stack_b(idx, size));
	while (node->next != NULL)
		node = node->next;
	if (nb < stack_a->number && nb > node->number)
		return (0);
	idx = 1;
	while (!(nb > stack_a->number && nb < (stack_a->next)->number))
	{
		stack_a = stack_a->next;
		idx++;
	}
	return (compute_moves_for_stack_b(idx, size));
}

int	*extract_stack_values(t_list *stack_a, int size)
{
	int	*values;
	int	idx;

	idx = 0;
	values = (int *) malloc (sizeof(int) * size + 1);
	if (!values)
		write_error();
	while (stack_a != NULL)
	{
		values[idx++] = (stack_a)->number;
		stack_a = (stack_a)->next;
	}
	return (values);
}

int	*duplicate_int_array(int	*arr, int size)
{
	int	idx;
	int	*copy;

	idx = 0;
	copy = (int *) malloc (sizeof(int) * size);
	if (!arr || !copy)
		write_error();
	while (idx < size)
	{
		copy[idx] = arr[idx];
		idx++;
	}
	return (copy);
}
