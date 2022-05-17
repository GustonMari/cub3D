/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_param_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:39:14 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/17 09:57:55 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

/*Va renvoyer le debut du path*/

char	*find_cardinal_path(char *path)
{
	int	i;

	i = 2;
	while (path[i] && (ft_is_space(path[i]) == TRUE))
		i++;
	return (&path[i]);
}

/*Permet la converion des chiffres (exe: 255,0,0) 
vers l'int qui serra stocke par la suite dans la struct*/

void	convert_floor_ceil(t_ptr *pgm, char *path, int dir)
{
	char	**tab;

	tab = ft_split(path, ", ");
	if (dir == FLOOR)
		pgm->floor = create_color(0,
				ft_atoi(tab[0]), ft_atoi(tab[1]), ft_atoi(tab[2]));
	if (dir == CEIL)
		pgm->ceil = create_color(0,
				ft_atoi(tab[0]), ft_atoi(tab[1]), ft_atoi(tab[2]));
	free(path);
	ft_free_tab_2d(tab);
}

int	init_struct(t_ptr *pgm)
{
	int	i;

	i = 0;
	pgm->buff = malloc(sizeof(int *) * (HEIGHT));
	if (!pgm->buff)
		return (FALSE);
	while (i < HEIGHT)
	{
		pgm->buff[i] = malloc(sizeof(int) * (WIDTH));
		if (!pgm->buff[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*Permet de convertir le path des points cardinaux
et le mettre dans la string path*/

char	*convert_cardinal_path(char *str)
{
	char	*path;
	int		len;

	len = 0;
	while (str[len] && (ft_is_space(str[len]) == FALSE))
		len++;
	path = ft_strndup(str, len);
	if (!path)
		return (NULL);
	return (path);
}

char	*convert_color_take(char *str)
{
	char	*path;
	int		len;

	len = 0;
	while (str[len])
		len++;
	path = ft_strndup(str, len);
	if (!path)
		return (NULL);
	return (path);
}
