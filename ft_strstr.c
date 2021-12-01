#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

char	*str_str(const char *str, const char *substr)
{
	size_t	n;

	n = ft_strlen(substr);
	while (*str)
	{
		if (!memcmp(str++, substr, n))
			return (char *)(str - 1);
	}
	return (0);
}

int main (void)
{
	char string[42] ="This is a test string for testing strstr";
	char *p;

	p = strstr(string,"test");
        if(p)
	{
		printf("String found:\n");
		printf("First occurrence of string \"test\" in \"%s\" is:\n%s\n", string, p);
	}
	p = str_str(string,"test");
        if(p)
	{
		printf("String found:\n");
		printf("First occurrence of string \"test\" in \"%s\" is:\n%s\n", string, p);
	}
	else
	{
	printf("String not found!\n" );
	}
	return 0; 
}
