#include "../includes/function.h"

void	pgm_image_init(t_ptr *pgm, t_data *image)
{
	pgm->mlx = mlx_init();
	pgm->win = mlx_new_window(pgm->mlx, HT, WT, "cub3d");
	pgm->image.img = mlx_new_image(pgm->mlx, HT, WT);
	pgm->image.addr = mlx_get_data_addr(image->img,
			&image->bpp, &image->line_length, &image->endian);
}