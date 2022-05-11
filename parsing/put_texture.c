#include "../includes/function.h"

int	define_walls(t_ptr *pgm)
{
	if (pgm->coord.impact_point == 0)
	{
		//ici on est sur les cote east west
		pgm->coord.real_distance = fabs(pgm->coord.all_dist_box_x
				- pgm->coord.delta_dist_x);
		if (pgm->coord.ray_dir_x < 0 && pgm->coord.ray_dir_y < 0)
			return (WE);
		else if (pgm->coord.ray_dir_x > 0 && pgm->coord.ray_dir_y > 0)
			return (EA);
	}
	else
	{
		//ICI cote north south
		pgm->coord.real_distance = fabs(pgm->coord.all_dist_box_y
				- pgm->coord.delta_dist_y);
		if (pgm->coord.ray_dir_x > 0 && pgm->coord.ray_dir_y < 0)
			return (NO);
		else if (pgm->coord.ray_dir_x < 0 && pgm->coord.ray_dir_y > 0)
			return (SO);
	}
	return (0);
}