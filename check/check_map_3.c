#include "../includes/function.h"

/*ON va regarder si on a un point de depart un juste un seul
sinon on retourne FALSE*/

int	check_double(char **map)
{
	int	i;
	int	j;
	int	letter;

	i = 0;
	letter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_start_char(map[i][j]) == TRUE)
				letter++;
			j++;
		}
		i++;
	}
	if (letter != 1)
		return (FALSE);
	return (TRUE);
}

int	check_map(char **map, int nb_line)
{
	int	i;
	int	max_len;

	i = 1;
	if (check_first_last(map, nb_line) == FALSE)
		return (FALSE);
	while (i < nb_line)
	{
		if (check_horizon(map[i]) == FALSE)
			return (FALSE);
		if (line_is_whitespace(map[i]) == TRUE)
			return (FALSE);
		i++;
	}
	i = 0;
	max_len = find_max_lenght(map);
	while (i < max_len - 1)
	{
		if (check_vertical(map, i, nb_line) == FALSE)
			return (FALSE);
		i++;
	}
	if (check_double(map) == FALSE)
		return (FALSE);
	return (TRUE);
}