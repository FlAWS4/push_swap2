/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:50:06 by mshariar          #+#    #+#             */
/*   Updated: 2025/01/29 19:50:09 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

void	split_list(t_list **stack_a, t_list **stack_b, int size);
void	initialize_list(t_list **stack_a, int argc, char **argv, int i);
void	check_duplicate(t_list *stack_a, int value);
void	check_sorted(t_list **stack_a);
void	check_inverted(t_list **stack_a);
void	delete_list(t_list **stack);

void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate(t_list **stack);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);

void	check_arguments(int argc, char **argv, t_list **stack_a);
void	move_to_b(t_list **stack_a, t_list **stack_b, int *arr, int max);
void	move_to_a(t_list **stack_a, t_list **stack_b);
int		find_best_position_b(t_list **stack_b, int size_b, t_list **stack_a, int size_a);
int		find_best_position_a(t_list *stack_a, int size, int *arr, int max);
int		find_best_combination(int *arr_a, int *arr_b, int size);
int		find_best_combination_helper(int *arr_a, int *arr_b, int *tmp, int size);
int		move_stack_a(int a, int b, t_list **stack_a, t_list **stack_b);
void	search_min(t_list **stack_a, int size);

int		*copy_stack_content(t_list *stack_a, int size);
int		*copy_int_array(int	*arr, int size);

int		calculate_needed(int min, int max, int size);
int		calculate_needed_a(t_list *stack_a, int cont, int size);
int		calculate_needed_b(int max, int size);
int		max_number(int a, int b);
int		min_number(int a, int b);
int		max_or_min(t_list *stack_a, int cont, int size);
int		return_max_or_min(int cont, int *max_n_min, int size);

int		*define_lis(int *dst, int size, int *max);
int		*lis_util(int *dst, int *arr, int max, int size);
int		*lis_util_helper(int max);

void	execute_sort(t_list **stack_a, t_list **stack_b, char *str);
void	execute_reverse_rotate(t_list **stack_a, t_list **stack_b, char *str);
void	initialize_list_checker(t_list **stack_a, int argc, char **argv, int i);
void	check_inverted_checker(t_list **stack_a);
void	check_sort(t_list *stack_a);
void	check_arguments_checker(int argc, char **argv, t_list **stack_a);
void	swap_a_checker(t_list **stack_a);
void	swap_b_checker(t_list **stack_b);
void	swap_both_checker(t_list **stack_a, t_list **stack_b);
void	push_a_checker(t_list **stack_b, t_list **stack_a);
void	push_b_checker(t_list **stack_a, t_list **stack_b);
void	rotate_a_checker(t_list **stack_a);
void	rotate_b_checker(t_list **stack_b);
void	rotate_both_checker(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a_checker(t_list **stack_a);
void	reverse_rotate_b_checker(t_list **stack_b);
void	reverse_rotate_both_checker(t_list **stack_a, t_list **stack_b);

#endif
