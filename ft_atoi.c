/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:53:14 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/17 15:15:29 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswsp(int c)
{
	unsigned int	i;

	i = 0;
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	long			sign;
	long			result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_iswsp(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
