#include "../includes/function.h"

/*Permet de savoir si il faut mettre un 1 dans la map*/

int	everything_is_one(char c)
{
	if (ft_is_space(c) == TRUE || c == '\0')
		return (TRUE);
	return (FALSE);
}

/*Permet de creer la premiere et la derniere ligne de la map,
rempli de 1*/

int	first_last_line(char **new_map , int nb_line, int len)
{
	int		i;

	i = 0;
	new_map[i] = ft_calloc(sizeof(char), len + 3);
	if (new_map[i] == NULL)
		return (FALSE);
	new_map[nb_line + 1] = ft_calloc(sizeof(char), len + 3);
	if (new_map[nb_line + 1] == NULL)
	{
		free(new_map[i]);
		return (FALSE);
	}
	while (i < len + 1)
	{
		new_map[0][i] = '1';
		new_map[nb_line + 1][i] = '1';
		i++;
	}
	new_map[0][i] = '\0';
	new_map[nb_line + 1][i] = '\0';
	new_map[nb_line + 2] = NULL;
	return (TRUE);
}

/*Cette fonction permet comme son nom l'indique
de securiser la map en l'entourant de 1,
ca permet d'eviter de segfault dans les coins*/

int	secure_map(t_ptr *pgm)
{
	int		i;
	int		j;
	int		len;
	char	**new_map;

	i = 0;
	pgm->nb_line = ft_count_line(pgm->map);
	len = find_max_lenght(pgm->map);
	new_map = ft_calloc(sizeof(char *), pgm->nb_line + 3);
	if (!new_map)
		return (FALSE);
	if (first_last_line(new_map, pgm->nb_line, len) == FALSE)
	{
		free(new_map);
		return (FALSE);
	}

	while (pgm->map[i])
	{
		j = 0;
		new_map[i + 1] = ft_calloc(sizeof(char), len + 3);
		//WARNING
		if (!new_map[i])
			return (FALSE);
		new_map[i + 1][0] = '1';
		while(pgm->map[i][j])
		{
			if (everything_is_one(pgm->map[i][j]) == FALSE)
				new_map[i + 1][j + 1] = pgm->map[i][j];
			else
				new_map[i + 1][j + 1] = '1';
			j++;
		}
		new_map[i + 1][len] = '1';
		new_map[pgm->nb_line + 2] = NULL;
		i++;
	}
	printf("nb_line = %d\n", pgm->nb_line);
	printf("len = %d\n", len);
	ft_free_tab_2d(pgm->map);
	pgm->map = new_map;
	return (TRUE);
}
