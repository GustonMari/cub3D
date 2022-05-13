#include "../includes/function.h"

int	ft_putstr_error(char *s)
{
	if (s)
	{
		write(2, s, ft_strlen(s));
	}
	return (FALSE);
}

int	ft_check_error(t_ptr *pgm, char **all)
{
	ft_free_tab_2d(all);
	ft_free_tab_2d(pgm->map);
	ft_free_tab_2d(pgm->param);
	ft_putstr_error("some issue with file\n");
	return (FALSE);
}