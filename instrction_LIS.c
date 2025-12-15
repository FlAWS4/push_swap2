/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrction_LIS.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:47:05 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/16 20:47:20 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	process_lis_update(int *lis, int *prev, int *stack_numbers, int size)
{
	int	outer;
	int	inner;

	outer = 1;
	while (outer < size)
	{
		inner = 0;
		while (inner < outer)
		{
			if (stack_numbers[outer] > stack_numbers[inner]
				&& lis[outer] < lis[inner] + 1)
			{
				lis[outer] = lis[inner] + 1;
				prev[outer] = inner;
			}
			inner++;
		}
		outer++;
	}
}

int	get_lis_max_length(int *lis, int size, int *end_index)
{
	int	max_length;
	int	idx;

	max_length = 0;
	*end_index = 0;
	idx = 0;
	while (idx < size)
	{
		if (lis[idx] > max_length)
		{
			max_length = lis[idx];
			*end_index = idx;
		}
		idx++;
	}
	free(lis);
	return (max_length);
}

int	*build_lis_sequence(int *stack_numbers,
	int *prev, int lis_length, int end_index)
{
	int	*result;
	int	pos;

	result = (int *)malloc(lis_length * sizeof(int));
	if (!result)
		write_error();
	pos = lis_length - 1;
	while (end_index >= 0)
	{
		result[pos] = stack_numbers[end_index];
		end_index = prev[end_index];
		pos--;
	}
	free(prev);
	return (result);
}

int	*calculate_lis_with_length(int *stack_numbers, int size, int *len)
{
	int	*lis;
	int	*prev;
	int	end_index;

	lis = (int *)malloc(size * sizeof(int));
	prev = (int *)malloc(size * sizeof(int));
	if (!lis || !prev)
		write_error();
	setup_lis_arrays(lis, prev, size);
	process_lis_update(lis, prev, stack_numbers, size);
	*len = get_lis_max_length(lis, size, &end_index);
	return (build_lis_sequence(stack_numbers, prev, *len, end_index));
}

int	*compute_lis(int *stack_numbers, int size, int *len)
{
	return (calculate_lis_with_length(stack_numbers, size, len));
}
/*
void print_array(int *arr, int size, const char *name)
{
    int i;

    printf("%s: ", name);
    i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

int main(void)
{
    int stack_numbers[] = {10, 22, 9, 33, 21, 50, 
	41, 60, 80, 5, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100};
    int size;
    int len;
    int *lis;

    size = sizeof(stack_numbers) / sizeof(stack_numbers[0]);
    lis = define_lis(stack_numbers, size, &len);
    print_array(lis, len, "Longest Increasing Subsequence");
    free(lis);
    return (0);
}

*/