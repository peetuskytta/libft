/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:25:21 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/10 11:03:22 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n;

	n = ft_strlen(needle);
	while (*haystack)
	{
		if (!ft_memcmp(haystack++, needle, n))
			return ((char *)(haystack - 1));
	}
	return (0);
}
