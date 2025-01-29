/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:46:00 by mshariar          #+#    #+#             */
/*   Updated: 2025/01/29 19:46:03 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./libft/libft.h"
#include "push_swap.h"

void	reverse_rotate_a_checker(t_list **stack_a)
{
    t_list	*last;
    t_list	*tmp;

    last = *stack_a;
    tmp = *stack_a;
    while (last->next != NULL)
    {
        tmp = last;
        last = last->next;
    }
    last->next = *stack_a;
    *stack_a = last;
    tmp->next = NULL;
}

void	reverse_rotate_b_checker(t_list **stack_b)
{
    t_list	*last;
    t_list	*tmp;

    last = *stack_b;
    tmp = *stack_b;
    while (last->next != NULL)
    {
        tmp = last;
        last = last->next;
    }
    last->next = *stack_b;
    *stack_b = last;
    tmp->next = NULL;
}

void	reverse_rotate_both_checker(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate_a_checker(stack_a);
    reverse_rotate_b_checker(stack_b);
}