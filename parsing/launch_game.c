#include "../includes/function.h"

// void	get_direction(t_ptr *pgm, char c)
// {
// 	if (c == 'N')
// 	{
// 		pgm->coord.direction_x = -1.0;
// 		pgm->coord.direction_y = 0;
// 		pgm->coord.plane_x = 0.0;
// 		pgm->coord.plane_y = 0.62;
// 	}
// 	else if (c == 'S')
// 	{
// 		pgm->coord.direction_x = 1.0;
// 		pgm->coord.direction_y = 0;
// 		pgm->coord.plane_x = 0.0;
// 		pgm->coord.plane_y = -0.62;
// 	}
// 	else if (c == 'E')
// 	{//pgm->coord.plane_x = 0.0;
// 		pgm->coord.direction_x = 0.0;
// 		pgm->coord.direction_y = 1.0;
// 		pgm->coord.plane_x = 0.62;
// 		pgm->coord.plane_y = 0.0;
// 	}
// 	else if (c == 'W')
// 	{
// 		pgm->coord.direction_x = 0.0;
// 		pgm->coord.direction_y = -1.0;
// 		pgm->coord.plane_x = -0.62;
// 		pgm->coord.plane_y = 0.0;
// 	}
// }

void	get_direction(t_ptr *pgm, char c)
{
	if (c == 'N')
	{
		pgm->coord.direction_x = 0.0;
		pgm->coord.direction_y = -1.0;
		
		pgm->coord.plane_x = 0.62;
		pgm->coord.plane_y = 0.0;
	}
	else if (c == 'S')
	{
		pgm->coord.direction_x = 0.0;
		pgm->coord.direction_y = 1.0;

		
		pgm->coord.plane_x = -0.62;
		pgm->coord.plane_y = 0.0;
	}
	else if (c == 'E')
	{//pgm->coord.plane_x = 0.0;
		pgm->coord.direction_x = -1.0;
		pgm->coord.direction_y = 0;
		pgm->coord.plane_x = 0.0;
		pgm->coord.plane_y = 0.62;
		
	}
	else if (c == 'W')
	{
		pgm->coord.direction_x = 1.0;
		pgm->coord.direction_y = 0;
		pgm->coord.plane_x = 0.0;
		pgm->coord.plane_y = -0.62;

		
	}
}


void	find_pos(t_ptr *pgm)
{
	int	i;
	int	j;

	i = 0;
	while (pgm->map[i])
	{//pgm->coord.plane_x = 0.0;
		j = 0;
		while (pgm->map[i][j])
		{
			if (check_start_char(pgm->map[i][j]) == TRUE)
			{
				//WARNING 0.5 sert a mettre au milieu d'un carre mais
				//c'est pas forcement ca qu'il faut faire
				pgm->coord.x = (double)j + 0.5;
				pgm->coord.y = (double)i + 0.5;
				get_direction(pgm, pgm->map[i][j]);
			}
			j++;
		}
		i++;
	}
}

/*
	permet de definir quelle intersection de la box le rayon touche (vertical ou horizontal, x et y) et ainsi permet de definir
	le deplacement du rayon de box en box. on definti par la suite all_dist_box la distance entre le rayon et la prochaine box.
	move defini le de box en box par exemple nous allons au nord move_y = -1 et move_x = 0.
*/

void	find_intersection(t_ptr *pgm)
{
	if (pgm->coord.ray_dir_x < 0)
	{
		pgm->coord.move_x = -1;
		pgm->coord.all_dist_box_x = (pgm->coord.x - pgm->coord.box_x) * pgm->coord.delta_dist_x;
	}
	else//pgm->coord.plane_x = 0.0;
	{
		pgm->coord.move_x = 1;
		pgm->coord.all_dist_box_x = (pgm->coord.box_x + 1.0 - pgm->coord.x) * pgm->coord.delta_dist_x;
	}
	if (pgm->coord.ray_dir_y < 0)
	{
		pgm->coord.move_y = -1;
		pgm->coord.all_dist_box_y = (pgm->coord.y - pgm->coord.box_y) * pgm->coord.delta_dist_y;
	}
	else
	{
		pgm->coord.move_y = 1;
		pgm->coord.all_dist_box_y = (pgm->coord.box_y + 1.0 - pgm->coord.y) * pgm->coord.delta_dist_y;
	}
}

/*
	Permet de trouver le point d'impact du rayon avec un mur (x et y)
	si impact = 0 alors le rayon a taper un x cest a dire une ligne VERTICAL ATTENTION
*/

void	find_impact(t_ptr *pgm)
{
	int impact;

	impact = 0;
	//warning on sait jamais
	while (impact == 0)
	{
		if (pgm->coord.all_dist_box_x < pgm->coord.all_dist_box_y)
		{
			pgm->coord.all_dist_box_x += pgm->coord.delta_dist_x;
			pgm->coord.box_x += pgm->coord.move_x;
			pgm->coord.impact_point = 0;
		}
		else
		{
			pgm->coord.all_dist_box_y += pgm->coord.delta_dist_y;
			pgm->coord.box_y += pgm->coord.move_y;
			pgm->coord.impact_point = 1;
		}
		//WARNING a voir si oon doit inverser x et y
		if (pgm->map[pgm->coord.box_y][pgm->coord.box_x] == '1')
			impact = 1;
	}
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
	pgm->coord.pos_x_camera = 2 * i / (double)WIDTH - 1;
	pgm->coord.ray_dir_x = pgm->coord.direction_x + (pgm->coord.plane_x * pgm->coord.pos_x_camera);
	pgm->coord.ray_dir_y = pgm->coord.direction_y + (pgm->coord.plane_y * pgm->coord.pos_x_camera);
	if (pgm->coord.ray_dir_x == 0)
		pgm->coord.delta_dist_x = pow(10, 30);
	else
		pgm->coord.delta_dist_x = fabs(1 / pgm->coord.ray_dir_x);
	if (pgm->coord.ray_dir_y == 0)
		pgm->coord.delta_dist_y = pow(10, 30);
	else
		pgm->coord.delta_dist_y = fabs(1 / pgm->coord.ray_dir_y);
}

void	paint_world(t_ptr *pgm, double i, double angle)
{
	int		top;
	int		bottom;
	int		shade;
	(void)angle;

	shade = 0;
	if (pgm->coord.impact_point == 0)
	{
		//mapX - rayPosX + (1 - stepX) / 2) / rayDirX
		//pgm->coord.real_distance = fabs((pgm->coord.all_dist_box_x - pgm->coord.delta_dist_x + (1 - pgm->coord.move_x) / 2) / pgm->coord.ray_dir_x);
		//pgm->coord.real_distance = (pgm->coord.all_dist_box_x - pgm->coord.delta_dist_x + (1 - pgm->coord.move_x) / 2);
		shade = 1;
		pgm->coord.real_distance = fabs(pgm->coord.all_dist_box_x - pgm->coord.delta_dist_x);
	}
	else
	{

		//pgm->coord.real_distance = fabs((pgm->coord.all_dist_box_y - pgm->coord.delta_dist_y + (1 - pgm->coord.move_y) / 2) / pgm->coord.ray_dir_y);
		//pgm->coord.real_distance = (pgm->coord.all_dist_box_y - pgm->coord.delta_dist_y + (1 - pgm->coord.move_y) / 2);
		pgm->coord.real_distance = fabs(pgm->coord.all_dist_box_y - pgm->coord.delta_dist_y);
	}

	
	// if (pgm->coord.impact_point == 0)
	// 	pgm->coord.real_distance = pgm->coord.all_dist_box_x * cos(angle); 
	// else
	// 	pgm->coord.real_distance = pgm->coord.all_dist_box_y * cos(angle);
	top = HEIGHT / 2 - (int)(HEIGHT / (pgm->coord.real_distance * 2));
	 if (top < 0)
	 	top = 0;
	//WARNING
	bottom = HEIGHT / 2 + (int)(HEIGHT / (pgm->coord.real_distance * 2));
	if (bottom > HEIGHT)
		bottom = HEIGHT - 1;
	ft_vertical(i, top, bottom, pgm, shade);
	//ft_vertical(i, top, bottom, pgm);
}

/*
	on a pris un FOV de 0.62 car on a fait
	2 * tan-1(0.62/1.0) = 62
	tant qu'on est avant la droite du vecteur dir,
	on va decrementer l'angle (qui est egal a la moitie du FOV -> 31)
	par le coeficient coef qui se calcul en fonction de notre
	definition de la largeur de l'ecran. Puis quand on depasse la droite on incremente.
*/

void	launch_game(t_ptr *pgm)
{
	double	i;
	double	angle;
	double	coef;
	//pgm->coord.plane_x = 0.0;
	angle = 31.0;
	coef = 62.0 / WIDTH;
	//find_pos(pgm);

	//pgm->coord.plane_x = 0.0;
	//BIG BIG WARNING
	//pgm->coord.plane_y = 0.62;
	//pgm->coord.plane_y = 0.00;
	//pgm->coord.plane_y = 2 * atan(0.62 / 1.0);
	//pgm->coord.plane_y = 0.0;
	//inserer boucle infini
	ft_bicolor(pgm, pgm->floor, pgm->ceil);
	while (i < WIDTH)
	{
		ray_casting(pgm, i);
		find_intersection(pgm);
		find_impact(pgm);
		paint_world(pgm, i, angle);
		if (i < WIDTH / 2)
			angle -= coef;
		else
			angle += coef;
		i++;
	}
	mlx_put_image_to_window(pgm->mlx, pgm->win, pgm->image.img, 0, 0);

}

/*
	constructray(t_ptr *pgm, t_ray *ray)
	findintersection(t_ptr *pgm, t_ray *ray)
	image = create_image(pgm)
*/