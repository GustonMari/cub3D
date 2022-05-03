#include "../includes/get_next_line.h"

void	ft_putstr_error(char *s)
{
	if (s)
	{
		write(2, s, ft_strlen(s));
	}
}