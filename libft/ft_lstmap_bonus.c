/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my42 <my42@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:21:28 by mshariar          #+#    #+#             */
/*   Updated: 2025/01/28 00:48:12 by my42             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int *(*f)(int *), void (*del)(int *))
{
	t_list	*node;
	t_list	*newlst;

	if (!lst)
		return (lst);
	newlst = NULL;
	while (lst)
	{
		node = ft_lstnew(*f(&lst->content));
		if (!(node))
		{
			ft_lstclear(&newlst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}
/*
void	del(void *content)
{
		free(content);
}
void	*count(void *content)
{
	*(int *) content += 1;
	return (content);
}
void	*cap(void *content)
{
	int i;
	
	i = 0;
	char *str = (char *)content;
	while (str[i])
	{
		((char *) content)[i] = ft_toupper(str[i]);
		i++;
	}
	return (content);
		
}
int	main()
{
	int *first = malloc(sizeof(int));
	int	*second = malloc(sizeof(int));
	int	*third = malloc(sizeof(int));
	char *first = ft_strdup("hello");
	char *second = ft_strdup("i");
	char *third = ft_strdup("am a ");
	char *str3 = ft_strdup("list");
	t_list *list = NULL;
	
	*first = 1;
	*second = 2;
	*third = 3;
	ft_lstadd_back(&list, ft_lstnew(str));
	ft_lstadd_back(&list, ft_lstnew(first));
	ft_lstadd_back(&list, ft_lstnew(second));
	ft_lstadd_back(&list, ft_lstnew(third));
	t_list *newmap = ft_lstmap(list, count, del);
	t_list *newmap = ft_lstmap(list, cap, del);
	t_list  *tmp = newmap;
	while(newmap)
	{
		printf("%s\n", (char *)newmap->content);
		newmap = newmap->next;
	}
	ft_lstclear(&newmap, del);
	ft_lstclear(&list, del);
}*/