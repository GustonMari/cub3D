/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:33:29 by gmary             #+#    #+#             */
/*   Updated: 2022/05/13 16:41:16 by gmary            ###   ########.fr       */
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
	ft_free_tab_2d(pgm->param); // peut etre a tej plus tard
	ft_free_buff(pgm);
	exit(0);
	return (FALSE);
}

void	key_up(t_ptr *pgm)
{
	if (pgm->map[(int)pgm->coord.y][(int)(pgm->coord.x + pgm->coord.ray_dir_x)] != '1' /* && pgm->map[(int)pgm->coord.y][(int)(pgm->coord.x - pgm->coord.plane_x)] != '1' */)
		pgm->coord.x += pgm->coord.direction_x * SPEED;
	fprintf(stderr, "next case = |%c|\n", pgm->map[(int)(pgm->coord.y + pgm->coord.ray_dir_y)][(int)(pgm->coord.x)]);
	if (pgm->map[(int)(pgm->coord.y + pgm->coord.ray_dir_y)][(int)(pgm->coord.x)] != '1' && pgm->map[(int)(pgm->coord.y - pgm->coord.plane_y -0.04)][(int)(pgm->coord.x)] != '1')
		pgm->coord.y += pgm->coord.direction_y * SPEED;
}

void	key_down(t_ptr *pgm)
{
	fprintf(stderr, "ray dir x = %f\n", pgm->coord.ray_dir_x);
	if (pgm->map[(int)(pgm->coord.y)][(int)(pgm->coord.x - pgm->coord.ray_dir_x)] != '1')
		pgm->coord.x -= pgm->coord.direction_x * SPEED;
	fprintf(stderr, "back case = |%c|\n", pgm->map[(int)(pgm->coord.y)][(int)(pgm->coord.x - pgm->coord.ray_dir_x)]);
	if (pgm->map[(int)(pgm->coord.y - pgm->coord.ray_dir_y)][(int)(pgm->coord.x)] != '1')
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
	double old_dir_x;
	double old_plane_x;

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

void	key_mv_left(t_ptr *pgm)
{
	if (pgm->map[(int)pgm->coord.y][(int)(pgm->coord.x - pgm->coord.plane_x)] != '1')
		pgm->coord.x -= pgm->coord.plane_x * SPEED;
	fprintf(stderr, "next case = |%c|\n", pgm->map[(int)(pgm->coord.y + pgm->coord.ray_dir_y)][(int)(pgm->coord.x)]);
	if (pgm->map[(int)(pgm->coord.y - pgm->coord.plane_y)][(int)(pgm->coord.x)] != '1')
		pgm->coord.y -= pgm->coord.plane_y * SPEED;
}

void	key_mv_right(t_ptr *pgm)
{
	if (pgm->map[(int)pgm->coord.y][(int)(pgm->coord.x + pgm->coord.plane_x)] != '1')
		pgm->coord.x += pgm->coord.plane_x * SPEED;
	fprintf(stderr, "next case = |%c|\n", pgm->map[(int)(pgm->coord.y + pgm->coord.ray_dir_y)][(int)(pgm->coord.x)]);
	if (pgm->map[(int)(pgm->coord.y + pgm->coord.plane_y)][(int)(pgm->coord.x)] != '1')
		pgm->coord.y += pgm->coord.plane_y * SPEED;
}

int	key_main(int key, t_ptr *pgm)
{
	if (key == XK_Escape)
		ft_close(pgm);
	if (key == XK_w || key == XK_Up)
		key_up(pgm);
	if (key == XK_s || key == XK_Down)
		key_down(pgm);
	if (/* key == XK_a ||  */key == XK_Left)
		key_left(pgm);
	if (/* key == XK_d ||  */key == XK_Right)
		key_right(pgm);
	if (key == XK_a)
		key_mv_left(pgm);
	if (key == XK_d)
		key_mv_right(pgm);
	return (0);
}

int key_release(int key, t_ptr *pgm)
{
	(void)key;
	(void)pgm;
	return (0);
}

int	key_manager(int key, t_ptr *pgm)
{
	key_main(key, pgm);
	launch_game(pgm);
	return (0);
}
