/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:53:41 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/17 18:44:32 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

void	get_direction_2(t_ptr *pgm, char c)
{
	if (c == 'E')
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
	else
		get_direction_2(pgm, c);
}

/* WARNING 0.5 sert a mettre au milieu d'un carre mais
c'est pas forcement ca qu'il faut faire */

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
	permet de definir quelle intersection de la box le rayon touche
	(vertical ou horizontal, x et y) et ainsi permet de definir
	le deplacement du rayon de box en box. on definti par la suite all_dist_box
	la distance entre le rayon et la prochaine box.
	move defini le de box en box par exemple nous allons
	au nord move_y = -1 et move_x = 0.
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
	si impact = 0 alors le rayon a taper un x cest a dire
	une ligne VERTICAL ATTENTION
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
