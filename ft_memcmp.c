/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:53:10 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/10 10:55:00 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	int		CmpStatus;

	CmpStatus = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (s1 == s2)
		return (0);
	while (n > 0)
	{
		if (*str1 != *str2)
		{
			if (*str1 > *str2)
				CmpStatus = 1;
			else
				CmpStatus = -1;
		}
		n--;
		str1++;
		str2++;
	}
	return (CmpStatus);
}
