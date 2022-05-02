#include "../function.h"


/*Permet de checker la premiere
et la derniere ligne de la map*/

int check_first_last(char **map, int nb_line)
{
    int j;

    j = 0;
	if (line_is_whitespace(map[0]) == TRUE
		|| line_is_whitespace(map[nb_line -1]) == TRUE)
		return (FALSE);
    while (map[0][j])
    {
        if ((ft_is_space(map[0][j])) && map[0][j] != '1')
            return (FALSE);
        j++;
    }
    j = 0;
    while (map[nb_line - 1][j])
    {
        if ((ft_is_space(map[nb_line - 1][j]))
            && map[nb_line - 1][j] != '1')
            return (FALSE);
        j++;
    }
    return (TRUE);
}

/*Permet de checker si c'est un des caracteres de depart*/

int	check_start_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (TRUE);
    return (FALSE);
}

int check_forbiden_char(char c)
{
    if (c == '1' || c == '0' || c == 'N' 
        || c == 'S' || c == 'W' || c == 'E' || c == '\0' || c == '\n')
        return (TRUE);
    return (FALSE);
}

/*Permet de checker si le nom de la map est valide*/

int check_name_map(char *name)
{
    if (ft_strchr_str(name, ".cub") == TRUE)
    {
        if (ft_strlen(name) < 5)
            return (FALSE);
        return (TRUE);
    }
    return (FALSE);
}