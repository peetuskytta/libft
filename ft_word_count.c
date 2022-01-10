/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:09:39 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/19 13:18:56 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define OFF 0
#define ON 1

/*
* ft_word_count counts the number of words in a string and returns that number.
* This additional function was used in ft_strsplit.
*/

size_t	ft_word_count(char const *str, char c)
{
	int				state;
	unsigned int	count;

	state = OFF;
	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
			state = OFF;
		else if (state == OFF)
		{
			state = ON;
			count++;
		}
		str++;
	}
	return (count);
}
