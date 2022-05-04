#include "../includes/function.h"

/* void cast_ray(t_ptr *pgm, t_ray *ray)
{
	int		x;
	int		y;
	int		i;
	double	dist;

	x = ray->x;
	y = ray->y;
	i = 0;
	dist = 0;
	while (i < pgm->map.height)
	{
		if (pgm->map.map[i][x] == '1')
		{
			dist = (i - y) / ray->ray_dir_y;
			ray->dist = dist;
			ray->angle = (x - ray->x + (1 - ray->ray_dir_x) / 2) / dist;
			return ;
		}
		i++;
	}
	ray->dist = 0;
	ray->angle = 0;

} */

void	get_direction(t_ptr *pgm, char c)
{
	if (c == 'N')
	{
		pgm->coord.direction_x = 0;
		pgm->coord.direction_y = -1;
	}
	else if (c == 'S')
	{
		pgm->coord.direction_x = 0;
		pgm->coord.direction_y = 1;
	}
	else if (c == 'E')
	{
		pgm->coord.direction_x = 1;
		pgm->coord.direction_y = 0;
	}
	else if (c == 'W')
	{
		pgm->coord.direction_x = -1;
		pgm->coord.direction_y = 0;
	}
}
void	find_pos(t_ptr *pgm)
{
	int		i;
	int		j;

	i = 0;
	while (pgm->map[i])
	{
		j = 0;
		while (pgm->map[i][j])
		{
			if (check_start_char(pgm->map[i][j]) == TRUE)
			{
				pgm->coord.x = j;
				pgm->coord.y = i;
				get_direction(pgm, pgm->map[i][j]);
			}
			j++;
		}
		i++;
	}
	printf("x: %d y: %d\n", pgm->coord.x, pgm->coord.y);
	printf("dir_x: %d dir_y: %d\n", pgm->coord.direction_x, pgm->coord.direction_y);
}

void	launch_game(t_ptr *pgm)
{
	find_pos(pgm);
}
