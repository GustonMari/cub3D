#include "../includes/function.h"

/*Va checker si le tableau de boolens pour les parametres
est completement rempli. Si oui on va s'arreter de checker,
tout est bon*/

int tab_is_full(int *tab)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (tab[i] == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*Va checker si les parametres avant la map sont bons,
Si on a NO SO WE EA F C et que F et C sont bien parametres
On checkera plus tard pour voir si les path de NO SO WE EA sont ok*/

int check_is_param(char *str)
{
	const char	*ref[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	static int	tab[6] = {0, 0, 0, 0, 0, 0};
	int			i;

	i = 0;
	while (ref[i])
	{
		if (ft_strncmp(str, (char *)ref[i], ft_strlen((char *)ref[i])) == 0)
		{
			if (tab[i] == 1)
				return (FALSE);
			if (i == 4 || i == 5)
				if (check_color(str) == FALSE)
					return (FALSE);
			tab[i] = 1;
			return (TRUE);
		}
		if (tab_is_full(tab) == TRUE)
			return (FULL);
		i++;
	}
	return (FALSE);
}

int check_element_file(char **map)
{
    int i;
	int	j;

    i = 0;
    while (map[i])
    {
		j = 0;
		if (ft_is_space(map[i][0]) == TRUE)
			while (map[i][j] && (ft_is_space(map[i][j]) == TRUE))
				j++;
		if (check_is_param(&map[i][j]) == FALSE && ft_strcmp(map[i], "\n"))
			return (FALSE);
		else if (check_is_param(&map[i][j]) == FULL)
			return (i + 1);
		i++;
	}
	return (TRUE);
}

int ft_check(char **all, char *name, int nb_line, t_ptr *pgm)
{
	char **map;
	char **param;
	int	ret;

	ret = 0;
	if (check_name_map(name) == FALSE)
	{
		ft_putstr_error("Error\nWrong map name\n");
		return (FALSE);
	}
	ret = check_element_file(all);
	if (ret == FALSE)
	{
		ft_putstr_error("Error\nWrong element in file\n");
		ft_free_tab_2d(all);
		return (FALSE);
	}
	else if (ret > 1)
	{
		map = cpy_tab(&all[ret], (nb_line - ret));
		param = cpy_tab(all, ret);
		map = adjust_map(map, ft_count_line(map));
		pgm->map = map;
		pgm->param = param;
		//WARNING
		if (!map)
			return (FALSE);
		if (check_map(map, ft_count_line(map)) == FALSE)
		{
			ft_putstr_error("Error\nWrong map\n");
			ft_free_tab_2d(all);
			ft_free_tab_2d(map);
			ft_free_tab_2d(param);
			return (FALSE);
		}
	}
	else
	{
		printf("y'a un pb\n");
		return (FALSE);
	}
	return (TRUE);
}
