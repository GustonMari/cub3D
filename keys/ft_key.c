/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:33:29 by gmary             #+#    #+#             */
/*   Updated: 2022/05/06 15:23:28 by gmary            ###   ########.fr       */
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
	//if (pgm->map[(int)(pgm->coord.x + pgm->coord.ray_dir_x)][(int)pgm->coord.y] != '1')
	//	pgm->coord.x += pgm->coord.ray_dir_x;
	fprintf(stderr, "UP----------------- x: %f y: %f\n", pgm->coord.x, (pgm->coord.y - pgm->coord.ray_dir_y));
	fprintf(stderr, "UP----------------- x: %d y: %d\n", (int)pgm->coord.x, (int)(pgm->coord.y - pgm->coord.ray_dir_y));
	if (pgm->map[(int)(pgm->coord.x)][(int)(pgm->coord.y + pgm->coord.ray_dir_y)] != '1')
		pgm->coord.y += pgm->coord.ray_dir_y;
	////if (pgm->map[(int)(pgm->coord.x + pgm->coord.ray_dir_x)][(int)pgm->coord.y] != '1')
	//	pgm->coord.x += pgm->coord.ray_dir_x;
	////if (pgm->map[(int)(pgm->coord.x)][(int)(pgm->coord.y + pgm->coord.ray_dir_y)] != '1')
	//	pgm->coord.y += pgm->coord.ray_dir_y;
}

void	key_down(t_ptr *pgm)
{
	//if (pgm->map[(int)(pgm->coord.x - pgm->coord.ray_dir_x)][(int)pgm->coord.y] != '1')
	//	pgm->coord.x -= pgm->coord.ray_dir_x;
	fprintf(stderr, "DOWN----------------- x: %f y: %f\n", pgm->coord.x, (pgm->coord.y - pgm->coord.ray_dir_y));
	fprintf(stderr, "DOWN----------------- x: %d y: %d\n", (int)pgm->coord.x, (int)(pgm->coord.y - pgm->coord.ray_dir_y));
	if (pgm->map[(int)(pgm->coord.x)][(int)(pgm->coord.y - pgm->coord.ray_dir_y)] != '1')
		pgm->coord.y -= pgm->coord.ray_dir_y;
}

int	key_main(int key, t_ptr *pgm)
{
	if (key == XK_Escape)
		ft_close(pgm);
	if (key == XK_Up)
		key_up(pgm);
	if (key == XK_Down)
		key_down(pgm);
	printf("x: %f\n", pgm->coord.x);
	printf("y: %f\n", pgm->coord.y);
	// if (key == XK_w || key == XK_Up)
	// 	key_up(pgm);
	// if (key == XK_s || key == XK_Down)
	// 	key_down(pgm);
	// if (key == XK_a)
	// 	printf("a\n");
	// if (key == XK_d)
	// 	printf("d\n");
	// if (key == XK_Left)
	// 	printf("LEFT\n");
	// if (key == XK_Right)
	// 	printf("RIGHT\n");
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
