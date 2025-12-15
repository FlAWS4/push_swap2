/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_postion_n_combination.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:32 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/12 20:35:38 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	locate_non_lis_element(t_list *stack_a, int size, int *arr, int len)
{
	int	position;
	int	arr_idx;

	position = 0;
	arr_idx = 0;
	while (stack_a != NULL)
	{
		arr_idx = 0;
		while (stack_a->number != arr[arr_idx] && arr_idx < len)
		{
			if (arr_idx == len - 1)
				return (position);
			arr_idx++;
		}
		stack_a = stack_a->next;
		position++;
	}
	size = -1;
	return (size);
}

int	compare_move_costs(int *arr_a, int *arr_b, int *tmp, int size)
{
	int	idx;
	int	min_pos;

	min_pos = 0;
	idx = -1;
	while (++idx < size)
	{
		if (tmp[idx] < tmp[min_pos])
			min_pos = idx;
	}
	free(arr_a);
	free(arr_b);
	free(tmp);
	return (min_pos);
}

int	get_optimal_move_combo(int *arr_a, int *arr_b, int size)
{
	int	*cost_combined;
	int	idx;

	idx = -1;
	cost_combined = (int *) malloc (sizeof(int) * size);
	if (!cost_combined || !arr_a || !arr_b)
		write_error();
	while (++idx < size)
	{
		if ((arr_a[idx] > 0 && arr_b[idx] > 0)
			|| (arr_a[idx] < 0 && arr_b[idx] < 0))
			cost_combined[idx] = get_larger_absolute(arr_a[idx], arr_b[idx]);
		else
		{
			if (arr_a[idx] < 0)
				arr_a[idx] *= -1;
			if (arr_b[idx] < 0)
				arr_b[idx] *= -1;
			cost_combined[idx] = arr_a[idx] + arr_b[idx];
		}
	}
	return (compare_move_costs(arr_a, arr_b, cost_combined, size));
}

int	execute_combined_rotations(int mv_a, int mv_b,
	t_list **stack_a, t_list **stack_b)
{
	while (mv_a < 0 && mv_b < 0)
	{
		reverse_rotate_both(stack_a, stack_b);
		mv_a++;
		mv_b++;
	}
	while (mv_a > 0 && mv_b > 0)
	{
		rotate_both(stack_a, stack_b);
		mv_a--;
		mv_b--;
	}
	if (mv_a < 0)
		while (mv_a++ < 0)
			reverse_rotate_a(stack_a);
	else if (mv_a > 0)
		while (mv_a-- > 0)
			rotate_a(stack_a);
	return (mv_b);
}

int	calculate_target_position(t_list **stack_b, int size_b,
	t_list **stack_a, int size_a)
{
	int		*moves_b;
	int		*moves_a;
	t_list	*current_b;
	int		idx;

	moves_a = (int *) malloc (sizeof(int) * size_b);
	moves_b = (int *) malloc (sizeof(int) * size_b);
	if (!moves_b || !moves_a)
		write_error();
	idx = -1;
	while (++idx < size_b)
		moves_b[idx] = compute_moves_for_stack_b(idx, size_b);
	idx = -1;
	current_b = *stack_b;
	while (++idx < size_b && current_b != NULL)
	{
		moves_a[idx] = compute_moves_for_stack_a(*stack_a,
				current_b->number, size_a);
		current_b = current_b->next;
	}
	idx = get_optimal_move_combo(duplicate_int_array(moves_a, size_b),
			duplicate_int_array(moves_b, size_b), size_b);
	idx = execute_combined_rotations(moves_a[idx], moves_b[idx],
			stack_a, stack_b);
	return (free(moves_a), free(moves_b), idx);
}
