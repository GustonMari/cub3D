/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:20:55 by gmary             #+#    #+#             */
/*   Updated: 2022/04/25 14:12:42 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	pgm_image_init(t_ptr *pgm, t_data *image)
{
	pgm->mlx = mlx_init();
	pgm->win = mlx_new_window(pgm->mlx, HT, WT, "hello");
	pgm->image.img = mlx_new_image(pgm->mlx, HT, WT);
	pgm->image.addr = mlx_get_data_addr(image->img,
			&image->bpp, &image->line_length, &image->endian);
	pgm->check.no = 0;
	pgm->check.so = 0;
	pgm->check.we = 0;
	pgm->check.ea = 0;
	pgm->check.f = 0;
	pgm->check.c = 0;
}

int	main(int ac, char **av)
{
	t_ptr	pgm;

	pgm_image_init(&pgm, &pgm.image);
/* 	if (!ft_strcmp(av[1], "julia"))
	{
		print_julia(&pgm, 2, 0);
		mlx_key_hook(pgm.win, &key_julia, &pgm);
		mlx_mouse_hook(pgm.win, &mouse_scroll, &pgm);
	}
	if (!ft_strcmp(av[1], "mandelbrot"))
	{
		print_mandelbrot(&pgm, 2, 0);
		mlx_key_hook(pgm.win, &key_mandel, &pgm);
		mlx_mouse_hook(pgm.win, &mouse_scroll_2, &pgm);
	}
	if (!ft_strcmp(av[1], "gustave"))
	{
		print_gustave(&pgm, 2, 0);
		mlx_key_hook(pgm.win, &key_gus, &pgm);
		mlx_mouse_hook(pgm.win, &mouse_scroll_3, &pgm);
	} */
	mlx_hook(pgm.win, 17, 02, ft_close, &pgm);
	mlx_loop(pgm.mlx);
	return (0);
}
