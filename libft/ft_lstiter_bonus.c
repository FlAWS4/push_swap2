/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:11:30 by mshariar          #+#    #+#             */
/*   Updated: 2025/01/28 00:46:27 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(&lst->content);
		lst = lst->next;
	}
}

void	func(void *content)
{
	*(int *)content += 1;
}
/*
int	main()
{
	int	*data1 = malloc(sizeof(int));
	int	*data2 = malloc(sizeof(int));
	int	*data3 = malloc(sizeof(int));

	*data1 = 1;
	*data2 = 2;
	*data3 = 3;
	t_list *list = NULL;

	ft_lstadd_back(&list, ft_lstnew(data1));
	ft_lstadd_back(&list, ft_lstnew(data2));
	ft_lstadd_back(&list, ft_lstnew(data3));
	
	ft_lstiter(list, func);
	while (list)
	{
		printf("%d\n", *(int *)list->content);
		list = list->next;
	}	
}*/