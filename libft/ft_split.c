/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:06:01 by mshariar          #+#    #+#             */
/*   Updated: 2025/02/12 22:56:53 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int		i;
	size_t	count;
	count = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			count++;
			i = 1;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}
static int	safe_malloc(char **tab, int i, size_t word)
{
	int	j;
	j = 0;
	tab[i] = malloc(word);
	if (tab[i] == NULL)
	{
		while (j < i)
		{
			free(tab[j]);
			j++;
		}
		free(tab);
		return (1);
	}
	return (0);
}
static int	fill_word(char **tab, char *s, char c)
{
	size_t		word_len;
	int			i;
	char		*start;
	i = 0;
	while (*s)
	{
		word_len = 0;
		while (*s == c && *s)
			s++;
		start = s;
		while (*s != c && *s)
		{
			word_len++;
			s++;
		}
		if (word_len > 0)
		{
			if (safe_malloc(tab, i, word_len + 1))
				return (1);
			ft_strlcpy(tab[i], start, word_len + 1);
			i++;
		}
	}
	return (0);
}
char	**ft_split(char *s, char c)
{
	char		**tab;
	size_t		word;
	if (s == NULL)
		return (NULL);
	word = 0;
	word = count_word(s, c);
	tab = malloc((word + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[word] = NULL;
	if (fill_word(tab, s, c))
		return (NULL);
	return (tab);
}
