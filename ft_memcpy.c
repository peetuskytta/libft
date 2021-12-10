/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:18:34 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/03 12:57:32 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*mydest;
	const char	*mysource;

	mydest = (char *)dst;
	mysource = (const char *)src;
	if ((mydest != NULL) && (mysource != NULL))
	{
		while (n > 0)
		{
			*(mydest++) = *(mysource++);
			n--;
		}
	}
	return (dst);
}
