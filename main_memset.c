/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:00:05 by pskytta           #+#    #+#             */
/*   Updated: 2021/11/22 16:42:27 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main()
{
	char test1[50] = "This is so fucked up test.";

	ft_putstr("-\033[0;32m---TEST_1-----\033[0m");
	ft_putchar('\n');
	ft_putstr(test1);
	ft_putchar('\n');
	ft_memset(test1 + 11, '*', 6);
	ft_putstr(test1);
	ft_putchar('\n');
	ft_putstr("-\033[0;32m---END_TEST_1----\033[0m");
	ft_putchar('\n');
	return (0);
}
