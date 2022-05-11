#include "../includes/function.h"

void	pgm_image_init(t_ptr *pgm, t_data *image)
{
	pgm->mlx = mlx_init();
	pgm->win = mlx_new_window(pgm->mlx, WIDTH, HEIGHT, "cub3d");
	pgm->image.img = mlx_new_image(pgm->mlx, WIDTH, HEIGHT);
	//pgm->north.img = mlx_new_image(pgm->mlx, pgm->north.width, pgm->north.height);
	// pgm->north.addr = (int *)mlx_get_data_addr(pgm->north.img,
	// 	&pgm->north.bpp, &pgm->north.line_length, &pgm->north.endian);



	pgm->image.addr = (int *)mlx_get_data_addr(image->img,
			&image->bpp, &image->line_length, &image->endian);
}

/* void	pgm_image_init(t_ptr *pgm, t_data *image)
{
	pgm->mlx = mlx_init();
	pgm->win = mlx_new_window(pgm->mlx, WIDTH, HEIGHT, "cub3d");
	pgm->image.img = mlx_new_image(pgm->mlx, WIDTH, HEIGHT);
	//pgm->win = mlx_new_window(pgm->mlx, HEIGHT, WIDTH, "cub3d");
	//pgm->image.img = mlx_new_image(pgm->mlx, HEIGHT, WIDTH);
	pgm->image.addr = mlx_get_data_addr(image->img,
			&image->bpp, &image->line_length, &image->endian);
} */