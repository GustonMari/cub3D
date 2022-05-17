/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:45:07 by gmary             #+#    #+#             */
/*   Updated: 2022/05/17 18:43:36 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

void	ft_set_null(t_ptr *pgm)
{
	pgm->mlx = NULL;
	pgm->win = NULL;
	pgm->param = NULL;
	pgm->map = NULL;
	pgm->buff = NULL;
}

void	pgm_image_init(t_ptr *pgm, t_data *image)
{
	pgm->mlx = mlx_init();
	if (pgm->mlx == NULL)
	{
		ft_putstr_error("Error: mlx_init failed\n");
		ft_close(pgm);
	}
	pgm->win = mlx_new_window(pgm->mlx, WIDTH, HEIGHT, "cub3d");
	pgm->image.img = mlx_new_image(pgm->mlx, WIDTH, HEIGHT);
	pgm->image.addr = (int *)mlx_get_data_addr(image->img,
			&image->bpp, &image->line_length, &image->endian);
	pgm->north.img = NULL;
	pgm->south.img = NULL;
	pgm->west.img = NULL;
	pgm->east.img = NULL;
}
