/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:52:01 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/13 18:29:23 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

/*
	cree et lance un rayon et determine sa distance euclidienne
	(donc avec effet fisheye pour linstant)
	et determine la distance avec le mur (delta_dist)
	ray_dir determine la direction du vecteur du rayon
	pos_x_camera determine la position de la camera par rapport
	au joueur centrer au centre de la fenetre
	box_x et y sont les coordonnees de la du carre ou le joueur
	se trouve
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

/*
	on a pris un FOV de 0.62 car on a fait
	2 * tan-1(0.62/1.0) = 62
	tant qu'on est avant la droite du vecteur dir,
	on va decrementer l'angle (qui est egal a la moitie du FOV -> 31)
	par le coeficient coef qui se calcul en fonction de notre
	definition de la largeur de l'ecran. Puis quand on
	 depasse la droite on incremente.
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
