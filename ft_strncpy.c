/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:48:47 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/10 10:53:56 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*start;

	start = dst;
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	while (*src && len--)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (start);
}
