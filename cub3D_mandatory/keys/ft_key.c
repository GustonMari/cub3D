/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:33:29 by gmary             #+#    #+#             */
/*   Updated: 2022/05/16 14:34:01 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

int	ft_close(t_ptr *pgm)
{
	mlx_destroy_image(pgm->mlx, pgm->image.img);
	if (pgm->north.img)
		mlx_destroy_image(pgm->mlx, pgm->north.img);
	if (pgm->south.img)
		mlx_destroy_image(pgm->mlx, pgm->south.img);
	if (pgm->west.img)
		mlx_destroy_image(pgm->mlx, pgm->west.img);
	if (pgm->east.img)
		mlx_destroy_image(pgm->mlx, pgm->east.img);
	if (pgm->mlx)
	{
		mlx_destroy_window(pgm->mlx, pgm->win);
		mlx_destroy_display(pgm->mlx);
		free(pgm->mlx);
	}
	ft_free_tab_2d(pgm->map);
	ft_free_tab_2d(pgm->param);
	ft_free_buff(pgm);
	exit(0);
	return (FALSE);
}

void	key_up(t_ptr *pgm)
{
	if (pgm->map[(int)pgm->coord.y]
		[(int)(pgm->coord.x + pgm->coord.direction_x)] != '1')
		pgm->coord.x += pgm->coord.direction_x * SPEED;
	if (pgm->map[(int)(pgm->coord.y + pgm->coord.direction_y)]
		[(int)(pgm->coord.x)] != '1')
		pgm->coord.y += pgm->coord.direction_y * SPEED;
}

void	key_down(t_ptr *pgm)
{
	if (pgm->map[(int)(pgm->coord.y)]
		[(int)(pgm->coord.x - pgm->coord.direction_x)] != '1')
		pgm->coord.x -= pgm->coord.direction_x * SPEED;
	if (pgm->map[(int)(pgm->coord.y - pgm->coord.direction_y)]
		[(int)(pgm->coord.x)] != '1')
		pgm->coord.y -= pgm->coord.direction_y * SPEED;
}

void	key_left(t_ptr *pgm)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = pgm->coord.direction_x;
	pgm->coord.direction_x = pgm->coord.direction_x * cos(-0.05)
		- pgm->coord.direction_y * sin(-0.05);
	pgm->coord.direction_y = old_dir_x * sin(-0.05)
		+ pgm->coord.direction_y * cos(-0.05);
	old_plane_x = pgm->coord.plane_x;
	pgm->coord.plane_x = pgm->coord.plane_x * cos(-0.05)
		- pgm->coord.plane_y * sin(-0.05);
	pgm->coord.plane_y = old_plane_x * sin(-0.05)
		+ pgm->coord.plane_y * cos(-0.05);
}

void	key_right(t_ptr *pgm)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = pgm->coord.direction_x;
	pgm->coord.direction_x = pgm->coord.direction_x * cos(0.05)
		- pgm->coord.direction_y * sin(0.05);
	pgm->coord.direction_y = old_dir_x * sin(0.05)
		+ pgm->coord.direction_y * cos(0.05);
	old_plane_x = pgm->coord.plane_x;
	pgm->coord.plane_x = pgm->coord.plane_x * cos(0.05)
		- pgm->coord.plane_y * sin(0.05);
	pgm->coord.plane_y = old_plane_x * sin(0.05)
		+ pgm->coord.plane_y * cos(0.05);
}
