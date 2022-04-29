#include "../function.h"

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
				check_color(str);
			tab[i] = 1;
			return (TRUE);
		}
		if (tab_is_full(tab) == TRUE)
			return (TRUE);
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
		i++;
	}
	return (TRUE);
}

int ft_check(char **map, char *name, int nb_line)
{
	(void)map;
	(void)nb_line;
    if (check_name_map(name) == FALSE)
    {
        ft_putstr_error("Error\nWrong map name\n");
        return (FALSE);
    }

    // if (check_map == FALSE)
    // {
    //     ft_putstr_error("Error\nWrong map\n");
    //     return (FALSE);
    // }
	return (TRUE);
}

/* int main(int argc, char **argv)
{
    char **map;
    char **new_map;
    int nb_line;

    nb_line = -1;
    map = parsing(argc, argv, &nb_line);
    new_map = adjust_map(map, nb_line);
    //printf("check = %d\n", check_map(new_map, nb_line));
    print_tab_2d(new_map);
    //printf("ret = %d\n", check_map(map, nb_line));
    return (0);
} */

/* int main(int argc, char **argv)
{
    char **map;
    char **new_map;
    int nb_line;
	(void)new_map;

    nb_line = -1;
    map = parsing(argc, argv, &nb_line);
    //new_map = adjust_map(map, nb_line);

	if (check_element_file(map) == TRUE)
		printf("Les param sont bons\n");
	else
		printf("C'est pas bon\n");
    return (0);
} */