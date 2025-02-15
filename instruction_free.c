/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:54:32 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/15 23:18:36 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	free_atoi(t_list **stack, char **argv)
{
	free_tab(argv);
	delete_list(stack);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	ft_atoi(const char *str, t_list **stack, char **argv)
{
	unsigned int		i;
	int					sign;
	unsigned long int	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			free_atoi(stack, argv);
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if ((number > 2147483648 && sign == -1)
		|| (number > 2147483647 && sign == 1))
		free_atoi(stack, argv);
	return (number * sign);
}

void	check_error_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i] && av)
	{
		if (is_numeric(av[i]))
		{
			free_tab(av);
			write_error();
		}
		i++;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
