/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:20:55 by gmary             #+#    #+#             */
/*   Updated: 2022/05/10 13:55:21 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/function.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

/* int main(int argc, char **argv)
{
	int nb_line;
	char **all;
	t_ptr	pgm;

	nb_line = -1;
	all = parsing(argc, argv, &nb_line);
	if (ft_check(all, argv[1], nb_line, &pgm) == FALSE)
	{
		printf("Probleme file-----------------------------------------\n");
		return (1);
	}
	pgm_image_init(&pgm, &pgm.image);
	if (convert_param(&pgm) == FALSE)
	{
		ft_free_tab_2d(all);
		ft_close(&pgm);
		return (1);
	}
	//WARNING
	if (secure_map(&pgm) == FALSE)
		return (FALSE);
	find_pos(&pgm);
	launch_game(&pgm);
	ft_free_tab_2d(all);
	//mlx_key_hook(pgm.win, &key_manager, &pgm);
	mlx_hook(pgm.win, 2, (1L << 0), &key_manager, &pgm);
	mlx_hook(pgm.win, 3, (1L << 1), &key_release, &pgm);
	mlx_hook(pgm.win, 17, 02, ft_close, &pgm);
	mlx_loop(pgm.mlx);
	return (0);
} */

int			get_pixel(t_data *data, int x, int y, unsigned int *color)
{
	char	*dest;

	if (x < 0 /* || x > img->siz.x */ || y < 0 /* || y > img->siz.y */)
	{
		return (1);
	}
	dest = data->addr +
				(y * data->line_length + x * (data->bpp / 8));
	*color = *(unsigned int *)dest;
	return (0);
}

int main()
{
	t_ptr	pgm;

	pgm.mlx = mlx_init();
	pgm.win = mlx_new_window(pgm.mlx, WIDTH, HEIGHT, "cub3d");
	pgm.image.img = mlx_new_image(pgm.mlx, pgm.image.width, pgm.image.height);
	pgm.north.img = mlx_new_image(pgm.mlx, pgm.north.width, pgm.north.height);
	pgm.north.img = mlx_xpm_file_to_image(pgm.mlx, "./texture/dofup.xpm",
		&pgm.north.width, &pgm.north.height);
	if (pgm.north.img == NULL)
		return (FALSE);
	pgm.image.addr = mlx_get_data_addr(pgm.image.img,
		&pgm.image.bpp, &pgm.image.line_length, &pgm.image.endian);
	pgm.north.addr = mlx_get_data_addr(pgm.north.img,
			&pgm.north.bpp, &pgm.north.line_length, &pgm.north.endian);
	if (pgm.north.addr == NULL)
		return (FALSE);
	int	i = 0;
	int	j;
	unsigned int	color;

	//color = (int)0xFFFFFF;
	//j = 0;
	//my_mlx_pixel_put(&pgm.image, 10, 10, color);
	while (i < pgm.north.height/* pgm.image.height */)
	{
		j = 0;
		while (j < pgm.north.width/* pgm.image.width */)
		{
			//color = (int)0xf8f8ff;
			//pos = (i * pgm->north.width + j * (pgm->north.bpp / 8));
		//	my_mlx_pixel_put(&pgm.image, j, i, pgm.north.addr[i * pgm.north.width + j * (pgm.north.bpp / 8)]);
			get_pixel(&pgm.north, j, i, &color);
			my_mlx_pixel_put(&pgm.image, j, i, color);
			j++;
		}
		i++;
	}

	//my_mlx_pixel_put(&pgm->north, 0, 0, pgm->north.addr[0]);

	
	//my_mlx_pixel_put()
	mlx_put_image_to_window(pgm.mlx, pgm.win, pgm.image.img, 0, 0);
	mlx_loop(pgm.mlx);
}

