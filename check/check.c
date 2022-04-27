#include "../function.h"

/*Permet de checker la premiere
et la derniere ligne de la map*/

int check_first_last(char **map, int nb_line)
{
    int j;

    j = 0;
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

int check_forbiden_char(char c)
{
    if (c == '1' || c == '0' || c == 'N' 
        || c == 'S' || c == 'W' || c == 'E' || c == '\0' || c == '\n')
        return (TRUE);
    printf("%c", c);
    return (FALSE);
}

/*Permet de voir si une ligne est bonne en horizontal*/

int check_horizon(char *line)
{
    int i;
    int space;
    (void)space;

    i = 0;
    space = 0;
    while (ft_is_space(line[i]) == TRUE)
    {
        space = 1;
        i++;
    }
    if (space == 1 && (line[i] != '1')) // faire fonction pour si la ligne est vide
        return (FALSE);
    while (line[i])
    {
        if (check_forbiden_char(line[i]) == FALSE)
            return (FALSE);
        if (line[i + 1] && ft_is_space(line[i + 1]) == TRUE)
        {
            if (line[i] != '1')
                return (FALSE);
            i++;
            while (line[i] && ft_is_space(line[i]) == TRUE)
                i++;
            if (line[i] && line[i] != '1')
                return (FALSE);
        }
        else
            i++;
    }
    return (TRUE);
}

/*Permet de voir si une ligne est bonne en verticale*/

int check_vertical(char **map, int column, int nb_line)
{
    int i;
    int space;
    (void)space;

    i = 0;
    space = 0;
    while (ft_is_space(map[i][column]) == TRUE)
    {
        space = 1;
        i++;
    }
    if (space == 1 && map[i][column] != '1' && map[i][column] != '\0') // faire fonction pour si la ligne est vide
       return (FALSE);
    while (i < nb_line)
    {
        if (check_forbiden_char(map[i][column]) == FALSE)
           return (FALSE);
        if ((i + 1 < nb_line) && ft_is_space(map[i + 1][column]) == TRUE)
        {
            if (map[i][column] != '1' && map[i][column] != '\0')
                return (FALSE);
            i++;
            while ((i < nb_line) && ft_is_space(map[i][column]) == TRUE)
                i++;
            if ((i < nb_line) && map[i][column] != '1' && map[i][column] != '\0')
                return (FALSE);
        }
        else
            i++;
    }
    return (TRUE);
}

/*Permet de trouver la plus grande
ligne horizontale et de renvoyer sa taille*/

int find_max_lenght(char **map)
{
    int i;
    int len;

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

int check_map(char **map, int nb_line)
{
    int i;
    int max_len;

    i = 1;
    if (check_first_last(map, nb_line) == FALSE)
        return (FALSE);
    while (i < nb_line)
    {
        if (check_horizon(map[i]) == FALSE)
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
    return (TRUE);
}

/* int ft_check(char **map, int nb_line)
{
    if (check_map == FALSE)
    {
        ft_putstr_error("Wrong map\n");
        exit(0);
    }
} */

int main(int argc, char **argv)
{
    char **map;
    char **new_map;
    int nb_line;

    nb_line = -1;
    map = parsing(argc, argv, &nb_line);
    new_map = adjust_map(map, nb_line);
    printf("check = %d\n", check_map(new_map, nb_line));
    print_tab_2d(new_map);
    //printf("ret = %d\n", check_map(map, nb_line));
    return (0);
}