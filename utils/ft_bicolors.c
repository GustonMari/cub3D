#include "../includes/function.h"

/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
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
} */

void	ft_bicolor(t_ptr *pgm, int color_floor, int color_ceil)
{
	int	i;
	int	j;

	i = 0;
	while (i < WT)
	{
		j = 0;
		while (j < HT)
		{
			if (j < HT / 2)
				my_mlx_pixel_put(&pgm->image, i, j, color_ceil);
			else
				my_mlx_pixel_put(&pgm->image, i, j, color_floor);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(pgm->mlx, pgm->win, pgm->image.img, 0, 0);
}

/* int	main()
{
	t_ptr	pgm;

	pgm_image_init(&pgm, &pgm.image);
	ft_bicolor(&pgm, create_color(0, 255, 0, 0), create_color(0, 0, 255, 0));
	mlx_hook(pgm.win, 17, 02, ft_close, &pgm);
	mlx_loop(pgm.mlx);
	return (0);
} */