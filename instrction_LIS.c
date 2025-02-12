/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrction_LIS.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:47:05 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/12 21:23:46 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	update_lis_and_prev(int *lis, int *prev, int *stack_numbers, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (stack_numbers[i] > stack_numbers[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	find_max_lis_length(int *lis, int size, int *end_index)
{
	int	max_lis_length;
	int	i;

	max_lis_length = 0;
	*end_index = 0;
	i = 0;
	while (i < size)
	{
		if (lis[i] > max_lis_length)
		{
			max_lis_length = lis[i];
			*end_index = i;
		}
		i++;
	}
	free(lis);
	return (max_lis_length);
}

int	*construct_lis(int *stack_numbers, int *prev, int lis_length, int end_index)
{
	int	*result;
	int	i;

	result = (int *)malloc(lis_length * sizeof(int));
	if (!result)
		write_error();
	i = lis_length - 1;
	while (end_index >= 0)
	{
		result[i] = stack_numbers[end_index];
		end_index = prev[end_index];
		i--;
	}
	free(prev);
	return (result);
}

int	*find_lis_and_len(int *stack_numbers, int size, int *len)
{
	int	*lis;
	int	*prev;
	int	end_index;

	lis = (int *)malloc(size * sizeof(int));
	prev = (int *)malloc(size * sizeof(int));
	if (!lis || !prev)
		write_error();
	initialize_lis_and_prev(lis, prev, size);
	update_lis_and_prev(lis, prev, stack_numbers, size);
	*len = find_max_lis_length(lis, size, &end_index);
	return (construct_lis(stack_numbers, prev, *len, end_index));
}

int	*define_lis(int *stack_numbers, int size, int *len)
{
	return (find_lis_and_len(stack_numbers, size, len));
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