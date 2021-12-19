/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:10:31 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/17 15:12:49 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnumber(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_putnumber(n / 10, str, i);
		ft_putnumber(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}

static size_t	ft_nblen(long long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	number;

	number = n;
	str = ft_memalloc(ft_nblen(number) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	if (number < 0)
	{
		str[i++] = '-';
		number = number * -1;
	}
	ft_putnumber(number, str, &i);
	str[i] = '\0';
	return (str);
}
