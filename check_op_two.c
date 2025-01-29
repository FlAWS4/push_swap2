/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:46:34 by mshariar          #+#    #+#             */
/*   Updated: 2025/01/29 19:46:37 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./libft/libft.h"
#include "push_swap.h"

void	rotate_a_checker(t_list **stack_a)
{
    t_list	*last;
    t_list	*first;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    last = *stack_a;
    first = *stack_a;
    while (last->next != NULL)
        last = last->next;
    *stack_a = first->next;
    first->next = NULL;
    last->next = first;
    return ;
}

void	rotate_b_checker(t_list **stack_b)
{
    t_list	*last;
    t_list	*first;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    last = *stack_b;
    first = *stack_b;
    while (last->next != NULL)
        last = last->next;
    *stack_b = first->next;
    first->next = NULL;
    last->next = first;
    return ;
}

void	rotate_both_checker(t_list **stack_a, t_list **stack_b)
{
    rotate_a_checker(stack_a);
    rotate_b_checker(stack_b);
}