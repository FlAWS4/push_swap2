/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:47 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/17 19:19:56 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	build_stack_from_args(t_list **stack_a, int argc, char **argv, int sz)
{
	t_list	*new_node;
	int		error;
	int		arg_idx;
	int		idx;

	error = 0;
	idx = 1;
	if (sz == 2)
		idx--;
	new_node = NULL;
	while (idx < argc)
	{
		arg_idx = push_swap_strlen(argv[idx]);
		if (arg_idx > 10)
			return (-1);
		new_node = ft_lstnew(ft_atoi(argv[idx], stack_a, argv, sz), stack_a);
		ft_lstadd_back(stack_a, new_node);
		error = check_duplicate(*stack_a, new_node->number);
		if (error == -1)
			return (-1);
		idx++;
	}
	handle_reverse_sorted(stack_a, argc);
	new_node = NULL;
	return (0);
}

void	execute_sort_algorithm(t_list **stack_a, t_list **stack_b, int size)
{
	int	*stack_values;
	int	*lis_arr;
	int	lis_len;

	lis_len = 0;
	if (size == 3)
	{
		sort_three_elements(stack_a);
		return ;
	}
	if (size == 5)
	{
		sort_five_elements(stack_a, stack_b);
		return ;
	}
	stack_values = extract_stack_values(*stack_a, size);
	lis_arr = compute_lis(stack_values, size, &lis_len);
	transfer_non_lis_to_b(stack_a, stack_b, lis_arr, lis_len);
	insert_back_sorted(stack_a, stack_b);
	rotate_min_to_top(stack_a, size);
	free(stack_values);
	free(lis_arr);
}

void	check_arg3(int argc, char **argv, t_list **stack_a)
{
	int	result;

	result = 0;
	if (argc >= 3)
	{
		result = 0;
		result = build_stack_from_args(stack_a, argc, argv, 0);
		if (result == -1)
		{
			delete_list(stack_a);
			write_error();
		}
	}
}

void	validate_and_parse_args(int argc, char **argv, t_list **stack_a)
{
	int		arg_count;
	char	**split_args;
	int		result;

	result = 0;
	split_args = NULL;
	arg_count = 0;
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		check_error_arg(split_args);
		while (split_args[arg_count] != NULL)
			arg_count++;
		result = build_stack_from_args(stack_a, arg_count, split_args, argc);
		if (result == -1)
		{
			delete_list(stack_a);
			free_tab(split_args);
			write_error();
		}
	}
	else if (argc >= 3)
		check_arg3(argc, argv, stack_a);
	free_tab(split_args);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	if (argc < 2)
		return (0);
	else if (!argv[1][0])
		return (write(2, "Error\n", 6), 1);
	else
		validate_and_parse_args(argc, argv, &stack_a);
	size = ft_lstsize(stack_a);
	if (size == 2)
	{
		delete_list(&stack_a);
		return (1);
	}
	if (is_stack_sorted(&stack_a) == -1)
		execute_sort_algorithm(&stack_a, &stack_b, size);
	delete_list(&stack_a);
	delete_list(&stack_b);
	return (0);
}
/*
void print_stack(t_list *stack, const char *name)
{
    printf("%s: ", name);
    while (stack != NULL)
    {
        printf("%d ", stack->number);
        stack = stack->next;
    }
    printf("\n");
}

void print_array(int *arr, int size, const char *name)
{
    printf("%s: ", name);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void sort_list(t_list **stack_a, t_list **stack_b, int size)
{
    int *stack_numbers;
    int *arr;
    int len;

    len = 1;
    if (size == 3)
    {
        sort_three(stack_a);
        return;
    }
    if (size == 5)
    {
        sort_five(stack_a, stack_b);
        return;
    }
    stack_numbers = copy_stack_number(*stack_a, size);
    arr = define_lis(stack_numbers, size, &len);

    // Print the initial state
    print_stack(*stack_a, "stack_a");
    print_stack(*stack_b, "stack_b");
    print_array(stack_numbers, size, "stack_numbers");
    print_array(arr, len, "arr");
    printf("len: %d\n", len);

    move_to_b(stack_a, stack_b, arr, len);

    // Print the state after moving to stack_b
    print_stack(*stack_a, "stack_a");
    print_stack(*stack_b, "stack_b");

    move_to_a(stack_a, stack_b);

    // Print the state after moving back to stack_a
    print_stack(*stack_a, "stack_a");
    print_stack(*stack_b, "stack_b");

    search_min(stack_a, size);

    // Print the final state
    print_stack(*stack_a, "stack_a");
    print_stack(*stack_b, "stack_b");

    free(stack_numbers);
    free(arr);
}*/