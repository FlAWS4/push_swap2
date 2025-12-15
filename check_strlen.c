/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:46:44 by mshariar          #+#    #+#             */
/*   Updated: 2025/08/29 23:30:48 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	push_swap_strlen(char *str)
{
	int	idx;
	int	digit_count;

	idx = 0;
	digit_count = 0;
	while (str[idx])
	{
		if (str[idx] >= '1' && str[idx] <= '9')
			digit_count++;
		idx++;
	}
	return (digit_count);
}
