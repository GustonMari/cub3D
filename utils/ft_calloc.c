#include "../function.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	tab = malloc(size * nmemb);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}
