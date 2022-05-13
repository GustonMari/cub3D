/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:29:00 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/13 18:29:07 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

void	find_texture_x_2(t_ptr *pgm, int cardinal_wall)
{
	if (cardinal_wall == EA)
	{
		pgm->coord.texture_x = (int)(pgm->coord.wall_x
				* (double)pgm->east.width);
		if (pgm->coord.impact_point == 0 && pgm->coord.ray_dir_x > 0)
			pgm->coord.texture_x = pgm->east.width - pgm->coord.texture_x - 1;
	}
	else if (cardinal_wall == WE)
	{
		pgm->coord.texture_x = (int)(pgm->coord.wall_x
				* (double)pgm->west.width);
		if (pgm->coord.impact_point == 0 && pgm->coord.ray_dir_x > 0)
			pgm->coord.texture_x = pgm->west.width - pgm->coord.texture_x - 1;
	}
}

void	find_texture_x(t_ptr *pgm, int cardinal_wall)
{
	if (cardinal_wall == NO)
	{
		pgm->coord.texture_x = (int)(pgm->coord.wall_x
				* (double)pgm->north.width);
		if (pgm->coord.impact_point == 1 && pgm->coord.ray_dir_y < 0)
			pgm->coord.texture_x = pgm->north.width - pgm->coord.texture_x - 1;
	}
	else if (cardinal_wall == SO)
	{
		pgm->coord.texture_x = (int)(pgm->coord.wall_x
				* (double)pgm->south.width);
		if (pgm->coord.impact_point == 1 && pgm->coord.ray_dir_y < 0)
			pgm->coord.texture_x = pgm->south.width - pgm->coord.texture_x - 1;
	}
	else
		find_texture_x_2(pgm, cardinal_wall);
}

/*
	permet de definir le perpwalldist aka real_distance
	et de trouver la face cardinal touche par le ray
*/

void	define_walls(t_ptr *pgm)
{
	if (pgm->coord.impact_point == 0)
	{
		pgm->coord.real_distance = fabs(pgm->coord.all_dist_box_x
				- pgm->coord.delta_dist_x);
		if (pgm->coord.ray_dir_x < 0)
			pgm->coord.cardinal_wall = WE;
		else if (pgm->coord.ray_dir_x > 0)
			pgm->coord.cardinal_wall = EA;
	}
	else
	{
		pgm->coord.real_distance = fabs(pgm->coord.all_dist_box_y
				- pgm->coord.delta_dist_y);
		if (pgm->coord.ray_dir_y < 0)
			pgm->coord.cardinal_wall = NO;
		else if (pgm->coord.ray_dir_y > 0)
			pgm->coord.cardinal_wall = SO;
	}
}
