/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:31:15 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/10 13:33:40 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	char		*d;
	char		*e;
	const char	*s;

	d = dst;
	e = dst + dstsize;
	s = src;
	while (*s != '\0' && d < e)
		*d++ = *s++;
	if (d < e)
		d = 0;
	else if (dstsize > 0)
		d[-1] = 0;
	while (*s != '\0')
		s++;
	return (s - src);
}
