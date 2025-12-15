/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:50:06 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/17 19:22:31 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_extremes
{
	int	max_val;
	int	min_val;
	int	max_pos;
	int	min_pos;
	int	curr_pos;
}	t_extremes;

int		is_stack_sorted(t_list **stack_a);
int		push_swap_strlen(char *str);
void	free_tab(char **tab);
void	check_error_arg(char **av);
int		is_numeric(char *str);
void	free_atoi(t_list **stack, char **argv, int size);
int		ft_atoi(const char *str, t_list **stack, char **argv, int size);
void	execute_sort_algorithm(t_list **stack_a, t_list **stack_b, int size);
int		build_stack_from_args(t_list **stack_a, int argc, char **argv, int sz);
int		check_duplicate(t_list *stack_a, int value);
void	handle_reverse_sorted(t_list **stack_a, int argc);
void	delete_list(t_list **stack);

void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
void	sort_three_elements(t_list **stack_a);
void	sort_five_elements(t_list **stack_a, t_list **stack_b);
void	free_tab(char **tab);
void	validate_and_parse_args(int argc, char **argv, t_list **stack_a);
void	transfer_non_lis_to_b(t_list **stack_a, t_list **stack_b,
			int *arr, int len);
void	insert_back_sorted(t_list **stack_a, t_list **stack_b);
int		calculate_target_position(t_list **stack_b, int size_b,
			t_list **stack_a, int size_a);
int		locate_non_lis_element(t_list *stack_a, int size, int *arr, int len);
int		get_optimal_move_combo(int *arr_a, int *arr_b, int size);
int		compare_move_costs(int *arr_a, int *arr_b, int *tmp, int size);
int		execute_combined_rotations(int mv_a, int mv_b,
			t_list **stack_a, t_list **stack_b);
void	rotate_min_to_top(t_list **stack_a, int size);

int		*extract_stack_values(t_list *stack_a, int size);
int		*duplicate_int_array(int	*arr, int size);

int		calculate_rotation_cost(int min, int len, int size);
int		compute_moves_for_stack_a(t_list *stack_a, int nb, int size);
int		compute_moves_for_stack_b(int len, int size);
int		get_larger_absolute(int a, int b);
int		get_smaller_absolute(int a, int b);
int		find_extremes_and_position(t_list *stack_a, int nb, int size);
int		check_if_extreme_value(int nb, t_extremes *ext, int size);

int		*build_lis_sequence(int *stack_numbers,
			int *prev, int lis_length, int end_index);
int		get_lis_max_length(int *lis, int size, int *end_index);
void	process_lis_update(int *lis, int *prev, int *stack_numbers, int size);
void	setup_lis_arrays(int *lis, int *prev, int size);
int		*compute_lis(int *stack_numbers, int size, int *len);
int		*calculate_lis_with_length(int *stack_numbers, int size, int *len);

int		check_len(char *str);
void	check_free_tab(char **tab);
int		check_numeric(char *str);
int		check_atoi(const char *str, t_list **stack, char **argv, int size);
void	check_error_args(char **av);
void	check_args3(int argc, char **argv, t_list **stack_a);
void	check_delete_list(t_list **stack);
int		check_dup(t_list *stack_a, int check);
void	check_instruction(t_list **stack_a, t_list **stack_b, char *str);
void	check_instruction_rrr(t_list **stack_a, t_list **stack_b, char *str);
int		check_list(t_list **stack_a, int argc, char **argv, int size);
int		ok_or_ko(t_list **stack_a);
void	swap_a_check(t_list **stack_a);
void	swap_b_check(t_list **stack_b);
void	swap_s_check(t_list **stack_a, t_list **stack_b);
void	push_a_check(t_list **stack_b, t_list **stack_a);
void	push_b_check(t_list **stack_a, t_list **stack_b);
void	rotate_a_check(t_list **stack_a);
void	rotate_b_check(t_list **stack_b);
void	rotate_r_check(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a_check(t_list **stack_a);
void	reverse_rotate_b_check(t_list **stack_b);
void	reverse_rotate_r_check(t_list **stack_a, t_list **stack_b);

#endif
