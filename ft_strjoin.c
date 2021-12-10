/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:00:00 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/10 10:53:08 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*retstr;

	retstr = ft_strcat((char *)s1, s2);
	if (retstr != NULL)
	{
		retstr = ft_memalloc(ft_strlen(retstr));
		return (retstr);
	}
	return (NULL);
}
