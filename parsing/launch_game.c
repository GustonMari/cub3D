#include "../includes/function.h"

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
	{
		pgm->coord.direction_x = 1.0;
		pgm->coord.direction_y = 0;
		pgm->coord.plane_x = 0.0;
		 pgm->coord.plane_y = 0.62;
	}
	else if (c == 'W')
	{
		pgm->coord.direction_x = -1.0;
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
	{
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
		pgm->coord.all_dist_box_x = (pgm->coord.x - pgm->coord.box_x)
			* pgm->coord.delta_dist_x;
	}
	else
	{
		pgm->coord.move_x = 1;
		pgm->coord.all_dist_box_x = (pgm->coord.box_x + 1.0 - pgm->coord.x)
			* pgm->coord.delta_dist_x;
	}
	if (pgm->coord.ray_dir_y < 0)
	{
		pgm->coord.move_y = -1;
		pgm->coord.all_dist_box_y = (pgm->coord.y - pgm->coord.box_y)
			* pgm->coord.delta_dist_y;
	}
	else
	{
		pgm->coord.move_y = 1;
		pgm->coord.all_dist_box_y = (pgm->coord.box_y + 1.0 - pgm->coord.y)
			* pgm->coord.delta_dist_y;
	}
}

/*
	Permet de trouver le point d'impact du rayon avec un mur (x et y)
	si impact = 0 alors le rayon a taper un x cest a dire une ligne VERTICAL ATTENTION
*/

void	find_impact(t_ptr *pgm)
{
	int	impact;

	impact = 0;
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
	pgm->coord.ray_dir_x = pgm->coord.direction_x
		+ (pgm->coord.plane_x * pgm->coord.pos_x_camera);
	pgm->coord.ray_dir_y = pgm->coord.direction_y
		+ (pgm->coord.plane_y * pgm->coord.pos_x_camera);
	if (pgm->coord.ray_dir_x == 0)
		pgm->coord.delta_dist_x = pow(10, 30);
	else
		pgm->coord.delta_dist_x = fabs(1 / pgm->coord.ray_dir_x);
	if (pgm->coord.ray_dir_y == 0)
		pgm->coord.delta_dist_y = pow(10, 30);
	else
		pgm->coord.delta_dist_y = fabs(1 / pgm->coord.ray_dir_y);
}

void	paint_world(t_ptr *pgm, double i)
{
	int		top;
	int		bottom;
	double	step;

	step = -111111111;
	define_walls(pgm);
	top = HEIGHT / 2 - (int)(HEIGHT / (pgm->coord.real_distance * 2));
	 if (top < 0)
	 	top = 0;
	//WARNING
	bottom = HEIGHT / 2 + (int)(HEIGHT / (pgm->coord.real_distance * 2));
	if (bottom > HEIGHT)
		bottom = HEIGHT;
	if (pgm->coord.impact_point == 0)
		pgm->coord.wall_x = (pgm->coord.y + (pgm->coord.real_distance * pgm->coord.ray_dir_y));
	else
		pgm->coord.wall_x = (pgm->coord.x + (pgm->coord.real_distance * pgm->coord.ray_dir_x));
	pgm->coord.wall_x -= floor(pgm->coord.wall_x);
	if (pgm->coord.cardinal_wall == NO)
		step = 1.0 * pgm->north.height / (HEIGHT / (pgm->coord.real_distance));
	else if (pgm->coord.cardinal_wall == SO)
		step = 1.0 * pgm->south.height / (HEIGHT / (pgm->coord.real_distance));
	else if (pgm->coord.cardinal_wall == EA)
		step = 1.0 * pgm->east.height / (HEIGHT / (pgm->coord.real_distance));
	else if (pgm->coord.cardinal_wall == WE)
		step = 1.0 * pgm->west.height / (HEIGHT / (pgm->coord.real_distance));
	double texpos = (top - HEIGHT /2  + ((HEIGHT / pgm->coord.real_distance) / 2)) * step;
	int texY;
	uint32_t color;
	for(int y = top; y < bottom; y++)
	{
		find_texture_x(pgm, pgm->coord.cardinal_wall);
		if (pgm->coord.cardinal_wall == NO)
			texY = (int)(texpos) & (pgm->north.height - 1);
		else if (pgm->coord.cardinal_wall == SO)
			texY = (int)(texpos) & (pgm->south.height - 1);
		else if (pgm->coord.cardinal_wall == EA)
			texY = (int)(texpos) & (pgm->east.height - 1);
		else if (pgm->coord.cardinal_wall == WE)
			texY = (int)(texpos) & (pgm->west.height - 1);
		texpos += step;
		if (pgm->coord.cardinal_wall == NO)
			color = pgm->north.addr[texY * pgm->north.width + pgm->coord.texture_x];
		if (pgm->coord.cardinal_wall == SO)
			color = pgm->south.addr[texY * pgm->south.width + pgm->coord.texture_x];
		if (pgm->coord.cardinal_wall == EA)
			color = pgm->east.addr[texY * pgm->east.width + pgm->coord.texture_x];
		if (pgm->coord.cardinal_wall == WE)
			color = pgm->west.addr[texY * pgm->west.width + pgm->coord.texture_x];
		if (pgm->coord.impact_point == 0)
			color = (color >> 1) & 8355711;
		pgm->buff[y][(int)i] = color;
	}
	//printf("%f\n", pgm->coord.real_distance);
}

/* void	paint_world(t_ptr *pgm, double i)
{
	int		top;
	int		bottom;
	double	step;
	//double	wallX;

	step = -111111111;
	define_walls(pgm);
	printf("wall = %d\nimpact = %f\n", pgm->coord.cardinal_wall, pgm->coord.impact_point);
	top = HEIGHT / 2 - (int)(HEIGHT / (pgm->coord.real_distance * 2));
	 if (top < 0)
	 	top = 0;
	//WARNING
	bottom = HEIGHT / 2 + (int)(HEIGHT / (pgm->coord.real_distance * 2));
	if (bottom > HEIGHT)
		bottom = HEIGHT - 1;
	if (pgm->coord.impact_point == 0)
		pgm->coord.wall_x = (pgm->coord.y + (pgm->coord.real_distance * pgm->coord.ray_dir_y));
	else
		pgm->coord.wall_x = (pgm->coord.x + (pgm->coord.real_distance * pgm->coord.ray_dir_x));
	pgm->coord.wall_x -= floor(pgm->coord.wall_x);
	// find_texture_x(pgm, pgm->coord.cardinal_wall);
	if (pgm->coord.cardinal_wall == NO)
		step = 1.0 * pgm->north.height / (HEIGHT / (pgm->coord.real_distance));
	else if (pgm->coord.cardinal_wall == SO)
		step = 1.0 * pgm->south.height / (HEIGHT / (pgm->coord.real_distance));
	else if (pgm->coord.cardinal_wall == EA)
		step = 1.0 * pgm->east.height / (HEIGHT / (pgm->coord.real_distance));
	else if (pgm->coord.cardinal_wall == WE)
		step = 1.0 * pgm->west.height / (HEIGHT / (pgm->coord.real_distance));
	double texpos = (top - HEIGHT /2  + ((HEIGHT / pgm->coord.real_distance) / 2)) * step;
	int texY;
	uint32_t color;
	for(int y = top; y < bottom; y++)
	{
		find_texture_x(pgm, pgm->coord.cardinal_wall);
		if (pgm->coord.cardinal_wall == NO)
			texY = (int)(texpos) & (pgm->north.height - 1);
		else if (pgm->coord.cardinal_wall == SO)
			texY = (int)(texpos) & (pgm->south.height - 1);
		else if (pgm->coord.cardinal_wall == EA)
			texY = (int)(texpos) & (pgm->east.height - 1);
		else if (pgm->coord.cardinal_wall == WE)
			texY = (int)(texpos) & (pgm->west.height - 1);
		texpos += step;
		if (pgm->coord.cardinal_wall == NO)
			color = pgm->north.addr[texY * pgm->north.width + pgm->coord.texture_x];
		if (pgm->coord.cardinal_wall == SO)
			color = pgm->south.addr[texY * pgm->south.width + pgm->coord.texture_x];
		if (pgm->coord.cardinal_wall == EA)
			color = pgm->east.addr[texY * pgm->east.width + pgm->coord.texture_x];
		if (pgm->coord.cardinal_wall == WE)
			color = pgm->west.addr[texY * pgm->west.width + pgm->coord.texture_x];
		if (pgm->coord.impact_point == 0)
			color = (color >> 1) & 8355711;
		pgm->buff[y][(int)i] = color;
	}
	// printf("raydir_x = %f\n", pgm->coord.ray_dir_x);
	// printf("raydir_y = %f\n", pgm->coord.ray_dir_y);
} */

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

	i = 0.0;
	ft_bicolor(pgm, pgm->floor, pgm->ceil);
	while (i < WIDTH)
	{
		ray_casting(pgm, i);
		find_intersection(pgm);
		find_impact(pgm);
		paint_world(pgm, i);
		i++;
	}
	draw_buffer(pgm);
	mlx_put_image_to_window(pgm->mlx, pgm->win, pgm->image.img, 0, 0);
}
