/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:23:08 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/20 13:23:08 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_error(int nbr, char **res)
{
	while (nbr >= 0)
	{
		if (res[nbr] != NULL)
			ft_memdel((void **)res);
		nbr--;
	}
	free(res);
}

static size_t	ft_word_size(char const *str, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	ft_allocate_fill(char const *s, char **res, char c)
{
	size_t	i;
	size_t	k;
	size_t	w_size;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			w_size = 0;
			while (s[i] && s[i] != c)
			{
				w_size = ft_word_size(s, i, c);
				res[k] = ft_strsub(s, i, w_size);
				if (!res[k])
					ft_free_error(k, res);
				i = i + w_size;
				k++;
			}
		}
	}
}

char	**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	nbr;

	if (!s)
		return (NULL);
	nbr = ft_word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (nbr + 1));
	if (!result)
		return (NULL);
	ft_allocate_fill(s, result, c);
	result[nbr] = 0;
	return (result);
}
