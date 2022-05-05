#include "../includes/function.h"

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
	double		i;
	double		j;

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
}


/*
	
*/

void	find_intersection(t_ptr *pgm)
{

}


/*
	cree et lance un rayon et determine sa distance euclidienne (donc avec effet fisheye pour linstant)
	et determine la distance avec le mur (delta_dist)
	ray_dir determine la direction du vecteur du rayon
	pos_x_camera determine la position de la camera par rapport au joueur centrer au centre de la fenetre
	box_x et y sont les coordonnees de la du carre ou le joueur se trouve
*/

void	ray_casting(t_ptr *pgm, int i)
{
	pgm->coord.box_x = (int)pgm->coord.x;
	pgm->coord.box_y = (int)pgm->coord.y;
	pgm->coord.pos_x_camera = 2 * i / WIDTH - 1;
	pgm->coord.ray_dir_x = pgm->coord.direction_x + pgm->coord.plane_x * pgm->coord.pos_x_camera;
	pgm->coord.ray_dir_y = pgm->coord.direction_y + pgm->coord.plane_y * pgm->coord.pos_x_camera;
	if (pgm->coord.ray_dir_x == 0)
		pgm->coord.delta_dist_x = pow(10, 30);
	else
		pgm->coord.delta_dist_x = fabs(1 / pgm->coord.ray_dir_x);
	if (pgm->coord.ray_dir_y == 0)
		pgm->coord.delta_dist_y = pow(10, 30);
	else
		pgm->coord.delta_dist_y = fabs(1 / pgm->coord.ray_dir_y);
}

/*
	on a pris un FOV de 0.62 car on a fait 
	2 * tan-1(0.62/1.0) = 62
*/

void	launch_game(t_ptr *pgm)
{
	double	i;

	i = 0;
	find_pos(pgm);
	pgm->coord.plane_x = 0;
	pgm->coord.plane_y = 0.62;
	//inserer boucle infini
	while (i < WIDTH)
	{
		ray_casting(pgm, i);
		find_intersection(pgm);
		i++;
	}
}

/*
	constructray(t_ptr *pgm, t_ray *ray)
	findintersection(t_ptr *pgm, t_ray *ray)
	image = create_image(pgm)
*/