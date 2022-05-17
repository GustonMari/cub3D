/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:44:14 by gmary             #+#    #+#             */
/*   Updated: 2022/05/17 18:05:48 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

/*Va checker si le tableau de boolens pour les parametres
est completement rempli. Si oui on va s'arreter de checker,
tout est bon*/

int	tab_is_full(int *tab)
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

int	check_element_file(char **map)
{
	int	i;
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

int	create_map_param(t_ptr *pgm, char **map, char **param)
{
	map = adjust_map(map, ft_count_line(map));
	if (!map)
	{
		ft_free_tab_2d(param);
		return (FALSE);
	}
	pgm->map = map;
	pgm->param = param;
	return (TRUE);
}

int	ft_check_bis(char **all, int ret, int nb_line, t_ptr *pgm)
{
	char	**map;
	char	**param;

	if (ret == FALSE)
		return (ft_putstr_error("Error\nWrong element in file\n"));
	else if (ret > 1)
	{
		map = cpy_tab(&all[ret], (nb_line - ret));
		if (!map)
			return (FALSE);
		param = cpy_tab(all, ret);
		if (!param)
		{
			ft_free_tab_2d(map);
			return (FALSE);
		}
		if (create_map_param(pgm, map, param) == FALSE)
			return (FALSE);
		if (check_map(pgm->map, ft_count_line(pgm->map)) == FALSE)
			return (ft_putstr_error("Error\nWrong map\n"));
	}
	else
		return (ft_putstr_error("Problem append\n"));
	return (TRUE);
}

int	ft_check(char **all, char *name, int nb_line, t_ptr *pgm)
{
	int		ret;

	ret = 0;
	if (check_name_map(name) == FALSE)
		return (ft_putstr_error("Error\nWrong map name\n"));
	ret = check_element_file(all);
	if (ft_check_bis(all, ret, nb_line, pgm) == FALSE)
		return (FALSE);
	return (TRUE);
}
