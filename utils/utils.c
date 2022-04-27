#include "../function.h"

int	ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (TRUE);
	return (FALSE);
}

void	print_tab_2d(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		ft_putstr_fd(strs[i], 2);
		//ft_putstr_fd("\n", 2);
		i++;
	}
}

int	ft_count_line(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s || !fd)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = ft_calloc(sizeof(char), (i + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*Permet de copier la chaine de caractere
-carac caractere a la fin*/

char	*ft_strdup_less(char *src, int carac)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	i -= carac;
	dest = ft_calloc(sizeof(char), (i + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i + carac])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}