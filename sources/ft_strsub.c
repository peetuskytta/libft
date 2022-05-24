/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:01:26 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/16 19:57:45 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ptr;

	ptr = ft_strnew(len);
	if (!ptr || !s || start > ft_strlen(s))
		return (NULL);
	ptr = ft_strncpy(ptr, (const char *)s + start, len);
	return (ptr);
}
