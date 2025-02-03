/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:47 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/03 15:46:24 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	initialize_list(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*new_node;

	new_node = NULL;
	while (i < argc)
	{
		new_node = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, new_node);
		check_duplicate(*stack_a, new_node->content);
		i++;
	}
	check_sorted(stack_a);
	check_inverted(stack_a);
	new_node = NULL;
}

void	sort_list(t_list **stack_a, t_list **stack_b, int size)
{
	int	*dst;
	int	*arr;
	int	i;

	i = 0;
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
	dst = copy_stack_content(*stack_a, size);
	arr = define_lis(dst, size, &i);
	move_to_b(stack_a, stack_b, arr, i);
	move_to_a(stack_a, stack_b);
	search_min(stack_a, size);
	free(dst);
	free(arr);
}

void	check_arguments(int argc, char **argv, t_list **stack_a)
{
	int		size;
	char	**arg;

	arg = NULL;
	size = 0;
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		while (arg[size] != NULL)
			size++;
		initialize_list(stack_a, size, arg, 0);
		free(arg);
	}
	else if (argc >= 3)
		initialize_list(stack_a, argc, argv, 1);
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
		return (0);
	sort_list(&stack_a, &stack_b, size);
	delete_list(&stack_a);
	delete_list(&stack_b);
	return (0);
}
