#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t	(char *dst, const char *src, size_t size)
{
	const size_t	dstlen;
	const size_t	srclen;

	dstlen = ft_strnlen(dst, size);
	srclen = ft_strlen(src);
	if (dstlen == size)
		return (size + srclen);
	if (srclen < size - dstlen)
		ft_memcpy(dst + dstlen, src, size - srclen - 1);
	else
	{
		ft_memcpy(dst + dstlen, src, size - dstlen - 1);
		dst[size - 1] = '\0';
	}
	return (dstlen + srclen);
}

int	main()
{

