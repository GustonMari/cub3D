#include "../includes/get_next_line.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char			*dest;
	size_t			len_dest;
	unsigned int	i;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	if (!s1 && !s2)
		return (NULL);
	len_dest = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dest = (char *)malloc(sizeof(char) * (len_dest + 1));
	if (!dest)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
		*dest++ = s1[i++];
	i = 0;
	while (s2 && s2[i])
		*dest++ = s2[i++];
	*dest = '\0';
	free(s1);
	return (dest - len_dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}