#include "../includes/function.h"

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
	//mlx_put_image_to_window(pgm->mlx, pgm->win, pgm->image.img, 0, 0);
}
