/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:57:21 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/14 19:13:09 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int number, t_list **stack)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (free(stack), NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}
/*
int	main()
{
	int	*tmp = malloc(sizeof(int));
	int	*tmp1 = malloc(sizeof(int));
	
	*tmp = 42;
	*tmp1 = 123;
	t_list	*node = ft_lstnew(tmp);
	node->next = ft_lstnew(tmp1);
	//node->next->next = ft_lstnew("23");
	//node->next->next->next = ft_lstnew("33");
	while (node)
	{
		printf("%d\n", *(int *)node->number);
		node = node->next;
	}
}
*/
