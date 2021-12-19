/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:02:47 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/19 14:12:01 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_lenght(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			s++;
			i++;
		}
		else
			return (i);
	}
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	word_len;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	split = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!split || (!s || c == '\0'))
		return (NULL);
	while (k < ft_word_count(s, c) && split)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		word_len = ft_word_lenght(&s[i], c);
		split[k] = malloc(sizeof(**split) * (word_len + 1));
		ft_strncpy(split[k], &s[i], word_len);
		split[k][word_len] = '\0';
		while (s[i] != '\0' && s[i] != c)
			i++;
		k++;
	}
	split[k] = NULL;
	return (split);
}
