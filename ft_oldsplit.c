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
#include <stdio.h>

static size_t	ft_word_length(char const *str, char c)
{
	size_t  i;
        size_t  len;

        i = 0;
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

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	nbr;
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
		nbr = ft_word_length(&s[i], c);
		split[k] = malloc(sizeof(**split) * (nbr + 1));
		ft_strncpy(split[k], &s[i], nbr);
		split[k][nbr] = '\0';
		while (s[i] != '\0' && s[i] != c)
			i++;
		k++;
	}
	split[k] = NULL;
	return (split);
}

int     main(void)
{
        char    *ptr;
        char    **new;

        ptr = "this*is**my***string";
        new = (ft_strsplit(ptr, '*'));
        printf("%s\n%s\n%s\n%s\n" , new[0], new[1], new[2], new[3]);
        return (0);
}
