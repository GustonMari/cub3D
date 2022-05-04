/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:33:29 by gmary             #+#    #+#             */
/*   Updated: 2022/05/04 10:45:35 by gmary            ###   ########.fr       */
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

int	key_main(int key, t_ptr *pgm)
{
	if (key == XK_Escape)
		ft_close(pgm);
	if (key == XK_w)
		printf("w\n");
	if (key == XK_s)
		printf("s\n");
	if (key == XK_a)
		printf("a\n");
	if (key == XK_d)
		printf("d\n");
	if (key == XK_Left)
		printf("LEFT\n");
	if (key == XK_Right)
		printf("RIGHT\n");
	if (key == XK_Up)
		printf("UP\n");
	if (key == XK_Down)
		printf("DOWN\n");
	return (0);
}

int	key_manager(int key, t_ptr *pgm)
{
	key_main(key, pgm);
	//print_gustave(pgm, 2, 0); //ligne ou on render notre cub3d
	return (0);
}
