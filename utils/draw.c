#include "../includes/function.h"

/*Permet de dessiner le plafond et le mur en fonction des couleurs donnees*/

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
	//WARNING a enlever
	//mlx_put_image_to_window(pgm->mlx, pgm->win, pgm->image.img, 0, 0);
}

/*Dessinne un lgine verticale de l'ecran (Une ligne du ray casting)*/

int	ft_vertical(int x, int top, int bottom, t_ptr *pgm)
{
	int	i;

	i = top;
	while (i < bottom)
	{
		my_mlx_pixel_put(&pgm->image, x, i, create_color(0, 255, 0, 0));
		i++;
	}
	return (0);
}