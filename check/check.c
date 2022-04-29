#include "../function.h"

/* int check_element_file(char **map)
{
    const char  *ref[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
    int tab[6];
    int i;

    i = -1;
    while (++i < 6)
        tab[i] = 0;
    i = 0;
    while (map[i])
    {
		if(strcmp(map[i], "\n"))
			i++;
    }
} */

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

int main(int argc, char **argv)
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
}