#include "../includes/function.h"

/*Permet de voir si une ligne est bonne en horizontal*/

int	check_horizon_bis(char *line, int *i)
{
	if (check_forbiden_char(line[*i]) == FALSE)
		return (FALSE);
	if (line[*i + 1] && ft_is_space(line[*i + 1]) == TRUE)
	{
		if (line[*i] != '1')
			return (FALSE);
		(*i)++;
		while (line[*i] && ft_is_space(line[*i]) == TRUE)
			(*i)++;
		if (line[*i] && line[*i] != '1')
			return (FALSE);
	}
	else
		(*i)++;
	return (TRUE);
}

int	check_horizon(char *line)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (ft_is_space(line[i]) == TRUE)
	{
		space = 1;
		i++;
	}
	if (space == 1 && (line[i] != '1'))
		return (FALSE);
	while (line[i])
	{
		if (check_horizon_bis(line, &i) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

/*Permet de voir si une ligne est bonne en verticale*/

int	check_vertical_bis(char **map, int *i, int column, int nb_line)
{
	if (check_forbiden_char(map[*i][column]) == FALSE)
		return (FALSE);
	if (((*i) + 1 < nb_line) && ft_is_space(map[(*i) + 1][column]) == TRUE)
	{
		if (map[*i][column] != '1' && map[*i][column] != '\0')
			return (FALSE);
		(*i)++;
		while ((*i < nb_line) && ft_is_space(map[*i][column]) == TRUE)
			(*i)++;
		if ((*i < nb_line) && map[*i][column] != '1'
			&& map[*i][column] != '\0')
			return (FALSE);
	}
	else
		(*i)++;
	return (TRUE);
}

int	check_vertical(char **map, int column, int nb_line)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (ft_is_space(map[i][column]) == TRUE)
	{
		space = 1;
		i++;
	}
	if (space == 1 && map[i][column] != '1' && map[i][column] != '\0')
		return (FALSE);
	while (i < nb_line)
	{
		if (check_vertical_bis(map, &i, column, nb_line) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

/*Permet de trouver la plus grande
ligne horizontale et de renvoyer sa taille*/

int	find_max_lenght(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (len < ft_strlen((map[i])))
			len = ft_strlen((map[i]));
		i++;
	}
	return (len);
}
