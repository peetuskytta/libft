#include <string.h>
#include <stdio.h>
#include "libft.h"
#define SIZE 40

char	*ft_strcat(char *dest, const char *src)
{
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	ft_strcpy(dest + ft_strlen(dest), src);
	return (dest);
}

int	main()
{
	char dest[SIZE] = "I Love ";
	char src[] = "Pauliina soo much!";

	ft_strncat(dest, src);
	printf("\n%s\n\n", dest);
	return (0);
}
