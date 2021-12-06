#include "libft.h"

void	ft_strdel(char **as)
{
	/* we need to typecast it to what memdel needs as input. */
	ft_memdel((void **)as);
}
