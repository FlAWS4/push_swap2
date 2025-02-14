/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:47 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/14 23:15:16 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	initialize_list(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*new_node;
	int		error;

	error = 0;
	new_node = NULL;
	while (i < argc)
	{
		if (push_swap_strlen(argv[i]) >= 10)
		{
			return (-1);
			break ;
		}
		new_node = ft_lstnew(ft_atoi(argv[i], stack_a, argv), stack_a);
		ft_lstadd_back(stack_a, new_node);
		error = check_duplicate(*stack_a, new_node->number);
		if (error == -1)
		{
			return (-1);
			break ;
		}
		i++;
	}
	check_inverted(stack_a, argc);
	new_node = NULL;
	return (0);
}

void	sort_list(t_list **stack_a, t_list **stack_b, int size)
{
	int	*stack_numbers;
	int	*arr;
	int	len;

	len = 0;
	if (size == 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (size == 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
	stack_numbers = copy_stack_number(*stack_a, size);
	arr = define_lis(stack_numbers, size, &len);
	move_to_b(stack_a, stack_b, arr, len);
	move_to_a(stack_a, stack_b);
	search_min(stack_a, size);
	free(stack_numbers);
	free(arr);
}

void	check_arg3(int argc, char **argv, t_list **stack_a)
{
	int	i;

	i = 0;
	if (argc >= 3)
	{
		i = 0;
		i = initialize_list(stack_a, argc, argv, 1);
		if (i == -1)
		{
			delete_list(stack_a);
			write_error();
		}
	}
}

void	check_arguments(int argc, char **argv, t_list **stack_a)
{
	int		size;
	char	**arg;
	int		i;

	i = 0;
	arg = NULL;
	size = 0;
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		check_error_arg(arg);
		while (arg[size] != NULL)
			size++;
		i = initialize_list(stack_a, size, arg, 0);
		if (i == -1)
		{
			delete_list(stack_a);
			free_tab(arg);
			write_error();
		}
	}
	else if (argc >= 3)
		check_arg3(argc, argv, stack_a);
	free_tab(arg);
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
	else
		check_arguments(argc, argv, &stack_a);
	size = ft_lstsize(stack_a);
	if (size == 2)
	{
		delete_list(&stack_a);
		return (0);
	}
	sort_list(&stack_a, &stack_b, size);
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