#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	// return: zero <= if s1 and s2 equal
	// return: negative value <= the first character that doesnt match has lower value in s1 than in s2
	// return: positive value <= the first character that doesnt match has greater value in s1 than in s2
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}	

int	main()
{
	char	*data1 = "this is Data1";
	char	*data2 = "this is Fata1";
	printf("%d", strncmp(data1, data2, 9));
	return (0);
}
