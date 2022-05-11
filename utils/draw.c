#include "../includes/function.h"


void	draw_buffer(t_ptr *pgm, int (*buff)[WIDTH])
{
	int	i;
	int j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			pgm->image.addr[i * WIDTH + j] = buff[i][j];
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(pgm->mlx, pgm->win, pgm->image.img, 0, 0);
}

/*Permet de dessiner le plafond et le mur en fonction des couleurs donnees*/

void	ft_bicolor(t_ptr *pgm, int color_floor, int color_ceil)
{
	int	i;
	int	j;
	int	buff[HEIGHT][WIDTH];

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (j < HEIGHT / 2)
				buff[j][i] = color_floor;
				//my_mlx_pixel_put(&pgm->image, i, j, color_ceil);
			else
				buff[j][i] = color_ceil;
				//my_mlx_pixel_put(&pgm->image, i, j, color_floor);
			j++;
		}
		i++;
	}
	(void)buff;
	(void)pgm;
	//fprintf(stderr, "bicolor\n");
	draw_buffer(pgm, buff);
}

/*Dessinne un lgine verticale de l'ecran (Une ligne du ray casting)*/

/* int	ft_vertical(int x, int top, int bottom, t_ptr *pgm, int shade)
{
	int	i;

	i = top;
	while (i < bottom)
	{
		if (shade == 0)
			my_mlx_pixel_put(&pgm->image, x, i, create_color(0, 255, 0, 0));
		else
			my_mlx_pixel_put(&pgm->image, x, i,
				create_color(0, 255 / 2, 0 / 2, 0 / 2));
		i++;
	}
	return (0);
} */

/* int	ft_vertical(int x, int top, int bottom, t_ptr *pgm, int shade)
{
	int	i;

	i = top;
	while (i < bottom)
	{
		if (shade == 0)
			my_mlx_pixel_put(&pgm->image, x, i, create_color(0, 255, 0, 0));
		else
			my_mlx_pixel_put(&pgm->image, x, i,
				create_color(0, 255 / 2, 0 / 2, 0 / 2));
		i++;
	}
	return (0);
} */