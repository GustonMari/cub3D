#include "../includes/function.h"

void	__mlx_loop_hook(t_ptr *pgm)
{
	mlx_hook(pgm->win, 2, (1L << 0), &key_manager, pgm);
	mlx_hook(pgm->win, 3, (1L << 1), &key_release, pgm);
	mlx_hook(pgm->win, 17, 02, ft_close, &pgm);
	mlx_loop(pgm->mlx);
}