/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:33:29 by gmary             #+#    #+#             */
/*   Updated: 2022/05/09 13:22:22 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

int	ft_close(t_ptr *pgm)
{
	mlx_destroy_image(pgm->mlx, pgm->image.img);
	if (pgm->no)
		mlx_destroy_image(pgm->mlx, pgm->no);
	if (pgm->so)
		mlx_destroy_image(pgm->mlx, pgm->so);
	if (pgm->we)
		mlx_destroy_image(pgm->mlx, pgm->we);
	if (pgm->ea)
		mlx_destroy_image(pgm->mlx, pgm->ea);
	mlx_destroy_window(pgm->mlx, pgm->win);
	mlx_destroy_display(pgm->mlx);
	ft_free_tab_2d(pgm->map);
	ft_free_tab_2d(pgm->param); // peut etre a tej plus tard
	free(pgm->mlx);
	exit(0);
}

void	key_up(t_ptr *pgm)
{
	fprintf(stderr, "key_up\n");
	fprintf(stderr, "ray dir y = %f\n", pgm->coord.ray_dir_y);
	if (pgm->map[(int)pgm->coord.y][(int)(pgm->coord.x + pgm->coord.ray_dir_x)] != '1')
		pgm->coord.x += pgm->coord.direction_x;

	fprintf(stderr, "x: %f\n", pgm->coord.x);
	fprintf(stderr, "y: %f\n", pgm->coord.y);
	
	fprintf(stderr, "next case = |%c|\n", pgm->map[(int)(pgm->coord.y + pgm->coord.ray_dir_y)][(int)(pgm->coord.x)]);
	if (pgm->map[(int)(pgm->coord.y + pgm->coord.ray_dir_y)][(int)(pgm->coord.x)] != '1')
	 	pgm->coord.y += pgm->coord.direction_y;


}

void	key_down(t_ptr *pgm)
{
	fprintf(stderr, "ray dir x = %f\n", pgm->coord.ray_dir_x);
	if (pgm->map[(int)(pgm->coord.y)][(int)(pgm->coord.x - pgm->coord.ray_dir_x)] != '1')
		pgm->coord.x -= pgm->coord.direction_x;

	printf("x: %f\n", pgm->coord.x);
	printf("y: %f\n", pgm->coord.y);
	fprintf(stderr, "back case = |%c|\n", pgm->map[(int)(pgm->coord.y)][(int)(pgm->coord.x - pgm->coord.ray_dir_x)]);
	if (pgm->map[(int)(pgm->coord.y - pgm->coord.ray_dir_y)][(int)(pgm->coord.x)] != '1')
		pgm->coord.y -= pgm->coord.direction_y;

}

void	key_left(t_ptr *pgm)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = pgm->coord.direction_x;
	pgm->coord.direction_x = pgm->coord.direction_x * cos(-0.1) - pgm->coord.direction_y * sin(-0.1);
	pgm->coord.direction_y = old_dir_x * sin(-0.1) + pgm->coord.direction_y * cos(-0.1);
	old_plane_x = pgm->coord.plane_x;
	pgm->coord.plane_x = pgm->coord.plane_x * cos(-0.1) - pgm->coord.plane_y * sin(-0.1);
	pgm->coord.plane_y = old_plane_x * sin(-0.1) + pgm->coord.plane_y * cos(-0.1);
	printf("x: %f\n", pgm->coord.x);
	printf("y: %f\n", pgm->coord.y);
}

void	key_right(t_ptr *pgm)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = pgm->coord.direction_x;
	pgm->coord.direction_x = pgm->coord.direction_x * cos(0.1) - pgm->coord.direction_y * sin(0.1);
	pgm->coord.direction_y = old_dir_x * sin(0.1) + pgm->coord.direction_y * cos(0.1);
	old_plane_x = pgm->coord.plane_x;
	pgm->coord.plane_x = pgm->coord.plane_x * cos(0.1) - pgm->coord.plane_y * sin(0.1);
	pgm->coord.plane_y = old_plane_x * sin(0.1) + pgm->coord.plane_y * cos(0.1);
	//WARNING
	// pgm->coord.ray_dir_x = pgm->coord.direction_x + (pgm->coord.plane_x * pgm->coord.pos_x_camera);
	// pgm->coord.ray_dir_y = pgm->coord.direction_y + (pgm->coord.plane_y * pgm->coord.pos_x_camera);
	printf("x: %f\n", pgm->coord.x);
	printf("y: %f\n", pgm->coord.y);
}

int	key_main(int key, t_ptr *pgm)
{
	if (key == XK_Escape)
		ft_close(pgm);
	if (key == XK_Up)
		key_up(pgm);
	if (key == XK_Down)
		key_down(pgm);
	// if (key == XK_w || key == XK_Up)
	// 	key_up(pgm);
	// if (key == XK_s || key == XK_Down)
	// 	key_down(pgm);
	// if (key == XK_a)
	// 	printf("a\n");
	// if (key == XK_d)
	// 	printf("d\n");
	if (key == XK_Left)
		key_left(pgm);
	if (key == XK_Right)
		key_right(pgm);
	return (0);
}

int	key_manager(int key, t_ptr *pgm)
{
	key_main(key, pgm);
	fprintf(stderr, "launch\n");
	launch_game(pgm);
		fprintf(stderr, "after launch\n");
	//print_gustave(pgm, 2, 0); //ligne ou on render notre cub3d
	return (0);
}
