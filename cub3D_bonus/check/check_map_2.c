/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:44:33 by gmary             #+#    #+#             */
/*   Updated: 2022/05/17 16:17:54 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

/*Permet de checker la premiere
et la derniere ligne de la map*/

int	check_first_last(char **map, int nb_line)
{
	int	j;

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

int	check_forbiden_char(char c)
{
	if (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E' || c == '\0' || c == '\n')
		return (TRUE);
	return (FALSE);
}

/*Permet de checker si le nom de la map est valide*/

int	check_name_map(char *name)
{
	if (ft_strchr_str(name, ".cub") == TRUE)
	{
		if (ft_strlen(name) < 5)
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

/*Va checker si les parametres avant la map sont bons,
Si on a NO SO WE EA F C et que F et C sont bien parametres
On checkera plus tard pour voir si les path de NO SO WE EA sont ok*/

int	check_is_param(char *str)
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
