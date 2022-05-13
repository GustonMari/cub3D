#include "../includes/function.h"

int	ft_putstr_error(char *s)
{
	if (s)
	{
		write(2, s, ft_strlen(s));
	}
	return (FALSE);
}
