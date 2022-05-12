#include "../includes/function.h"

char	*ft_strndup(char *str, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = ft_calloc(sizeof(char), n + 1);
	if (!dest)
		return (NULL);
	while (str[i] && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_free_buff(t_ptr *pgm)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		free(pgm->buff[i]);
		i++;
	}
	free(pgm->buff);
}