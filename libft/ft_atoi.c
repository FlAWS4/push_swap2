/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:32:34 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/13 22:34:30 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*free_atoi(char	*str)
{
	ft_putstr_fd("Error\n", 2);
	return(free(str), NULL);
}

int	ft_atoi(const char *str)
{
	int			x;
	long int	y;

	y = 0;
	x = 1;
	if ((*str == 43 || *str == 45) && ft_isdigit(*(str + 1)))
	{
		if (*str == 45)
			x *= -1;
		str++;
	}
	while (*str <= 57 && *str >= 48)
	{
		if (!ft_isdigit(*str) && *str != '\0')
			write_error();
		y = (y * 10) + ((*str - 48) % 10);
		str++;
	}
	if (!ft_isdigit(*str) && *str != '\0')
		write_error();
	y *= x;
	if (y > 2147483647 || y < -2147483648)
		write_error();
	return ((int) y);
}
