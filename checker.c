/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:43:14 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/14 22:07:22 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	check_instruction_rrr(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "rra\n"))
		reverse_rotate_a_check(stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		reverse_rotate_b_check(stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		reverse_rotate_r_check(stack_a, stack_b);
	else
		write_error();
}

void	check_instruction(t_list **stack_a, t_list **stack_b, char *str)
{
	while (str != NULL)
	{
		if (ft_strcmp(str, "sa\n"))
			swap_a_check(stack_a);
		else if (ft_strcmp(str, "sb\n"))
			swap_b_check(stack_b);
		else if (ft_strcmp(str, "ss\n"))
			swap_s_check(stack_a, stack_b);
		else if (ft_strcmp(str, "pa\n"))
			push_a_check(stack_b, stack_a);
		else if (ft_strcmp(str, "pb\n"))
			push_b_check(stack_a, stack_b);
		else if (ft_strcmp(str, "ra\n"))
			rotate_a_check(stack_a);
		else if (ft_strcmp(str, "rb\n"))
			rotate_b_check(stack_b);
		else if (ft_strcmp(str, "rr\n"))
			rotate_r_check(stack_a, stack_b);
		else
			check_instruction_rrr(stack_a, stack_b, str);
		str = get_next_line(0);
	}
}

void	check_args(int argc, char **argv, t_list **stack_a)
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
		check_initialize_list(stack_a, size, arg, 0);
		free(arg);
	}
	else if (argc >= 3)
		check_initialize_list(stack_a, argc, argv, 1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else
		check_args(argc, argv, &stack_a);
	str = get_next_line(0);
	check_instruction(&stack_a, &stack_b, str);
	if (ok_or_ko(&stack_a) == -1)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	return (0);
}
