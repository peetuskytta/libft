/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:20:57 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/12 13:40:56 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_print(int	err_id, char *str)
{
	if (err_id == 1)
		ft_putendl(str);
	if (err_id == 2)
		ft_putendl(str);
	if (err_id == 3)
		ft_putendl(str);
	if (err_id == 4)
		ft_putendl(str);
	if (err_id == 5)
		ft_putendl(str);
	if (err_id == 6)
		ft_putendl(str);
	if (err_id == 7)
		ft_putendl(str);
	if (err_id == 0)
		ft_putendl(str);
	exit(1);
}
