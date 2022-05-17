/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:37:36 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/17 09:57:17 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

int	convert_cardinal_points_2(t_ptr *pgm, char *path, int dir)
{
	if (dir == EA)
	{
		pgm->east.img = mlx_xpm_file_to_image(pgm->mlx, path,
				&pgm->east.width, &pgm->east.height);
		if (pgm->east.img == NULL)
			return (FALSE);
		pgm->east.addr = (int *)mlx_get_data_addr(pgm->east.img,
				&pgm->east.bpp, &pgm->east.line_length, &pgm->east.endian);
	}
	if (dir == WE)
	{
		pgm->west.img = mlx_xpm_file_to_image(pgm->mlx, path,
				&pgm->west.width, &pgm->west.height);
		if (pgm->west.img == NULL)
			return (FALSE);
		pgm->west.addr = (int *)mlx_get_data_addr(pgm->west.img,
				&pgm->west.bpp, &pgm->west.line_length, &pgm->west.endian);
	}
	return (TRUE);
}

int	convert_cardinal_points(t_ptr *pgm, char *path, int dir)
{
	if (dir == NO)
	{
		pgm->north.img = mlx_xpm_file_to_image(pgm->mlx, path,
				&pgm->north.width, &pgm->north.height);
		if (pgm->north.img == NULL)
			return (FALSE);
		pgm->north.addr = (int *)mlx_get_data_addr(pgm->north.img,
				&pgm->north.bpp, &pgm->north.line_length, &pgm->north.endian);
	}
	if (dir == SO)
	{
		pgm->south.img = mlx_xpm_file_to_image(pgm->mlx, path,
				&pgm->south.width, &pgm->south.height);
		if (pgm->south.img == NULL)
			return (FALSE);
		pgm->south.addr = (int *)mlx_get_data_addr(pgm->south.img,
				&pgm->south.bpp, &pgm->south.line_length, &pgm->south.endian);
	}
	if (convert_cardinal_points_2(pgm, path, dir) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	convert_param_2(t_ptr *pgm, char *str_param, int dir)
{
	char	*path;

	path = convert_cardinal_path(find_cardinal_path(str_param));
	if (!path)
	{
		ft_putstr_error("Error\nMalloc failed\n");
		return (FALSE);
	}
	if (convert_cardinal_points(pgm, path, dir) == FALSE)
	{
		ft_putstr_error("Error\nUnable to open texture\n");
		free(path);
		return (FALSE);
	}
	free(path);
	return (TRUE);
}

int	convert_param_conditions(t_ptr *pgm, int i, int j)
{
	if (ft_strncmp(&pgm->param[i][j], "NO", 2) == TRUE)
		if (convert_param_2(pgm, &pgm->param[i][j], NO) == FALSE)
			return (FALSE);
	if (ft_strncmp(&pgm->param[i][j], "SO", 2) == TRUE)
		if (convert_param_2(pgm, &pgm->param[i][j], SO) == FALSE)
			return (FALSE);
	if (ft_strncmp(&pgm->param[i][j], "EA", 2) == TRUE)
		if (convert_param_2(pgm, &pgm->param[i][j], EA) == FALSE)
			return (FALSE);
	if (ft_strncmp(&pgm->param[i][j], "WE", 2) == TRUE)
		if (convert_param_2(pgm, &pgm->param[i][j], WE) == FALSE)
			return (FALSE);
	if (ft_strncmp(&pgm->param[i][j], "F", 1) == TRUE)
		convert_floor_ceil(pgm,
			convert_color_take(find_cardinal_path(&pgm->param[i][j])),
			FLOOR);
	if (ft_strncmp(&pgm->param[i][j], "C", 1) == TRUE)
		convert_floor_ceil(pgm,
			convert_color_take(find_cardinal_path(&pgm->param[i][j])),
			CEIL);
	return (TRUE);
}

/*Converti les param et les mets dans la structure*/

int	convert_param(t_ptr *pgm)
{
	int		i;
	int		j;

	i = 0;
	if (init_struct(pgm) == FALSE)
		return (FALSE);
	while (pgm->param[i])
	{
		j = 0;
		while (pgm->param[i][j] && (ft_is_space(pgm->param[i][j]) == TRUE))
			j++;
		if (convert_param_conditions(pgm, i, j) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
