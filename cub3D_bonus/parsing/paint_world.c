/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:16:40 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/17 09:54:18 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

uint32_t	choose_color(t_ptr *pgm, int texy)
{
	uint32_t	color;

	if (pgm->coord.cardinal_wall == NO)
		color = pgm->north.addr[texy * pgm->north.width
			+ pgm->coord.texture_x];
	if (pgm->coord.cardinal_wall == SO)
		color = pgm->south.addr[texy * pgm->south.width
			+ pgm->coord.texture_x];
	if (pgm->coord.cardinal_wall == EA)
		color = pgm->east.addr[texy * pgm->east.width
			+ pgm->coord.texture_x];
	if (pgm->coord.cardinal_wall == WE)
		color = pgm->west.addr[texy * pgm->west.width
			+ pgm->coord.texture_x];
	if (pgm->coord.impact_point == 0)
		color = (color >> 1) & 8355711;
	return (color);
}

void	paint_line(t_ptr *pgm, double step, int i)
{
	double		texpos;
	int			texy;
	uint32_t	color;
	int			y;

	y = pgm->top;
	texpos = (pgm->top - HEIGHT / 2
			+ ((HEIGHT / pgm->coord.real_distance) / 2)) * step;
	while (y < pgm->bottom)
	{
		find_texture_x(pgm, pgm->coord.cardinal_wall);
		if (pgm->coord.cardinal_wall == NO)
			texy = (int)(texpos);
		else if (pgm->coord.cardinal_wall == SO)
			texy = (int)(texpos);
		else if (pgm->coord.cardinal_wall == EA)
			texy = (int)(texpos);
		else if (pgm->coord.cardinal_wall == WE)
			texy = (int)(texpos);
		texpos += step;
		color = choose_color(pgm, texy);
		pgm->buff[y][(int)i] = color;
		y++;
	}
}

double	calculate_step(t_ptr *pgm)
{
	double	step;

	step = -111111111;
	if (pgm->coord.cardinal_wall == NO)
		step = 1.0 * pgm->north.height / (HEIGHT / (pgm->coord.real_distance));
	else if (pgm->coord.cardinal_wall == SO)
		step = 1.0 * pgm->south.height / (HEIGHT / (pgm->coord.real_distance));
	else if (pgm->coord.cardinal_wall == EA)
		step = 1.0 * pgm->east.height / (HEIGHT / (pgm->coord.real_distance));
	else if (pgm->coord.cardinal_wall == WE)
		step = 1.0 * pgm->west.height / (HEIGHT / (pgm->coord.real_distance));
	return (step);
}

void	paint_world(t_ptr *pgm, double i)
{
	double	step;

	define_walls(pgm);
	pgm->top = HEIGHT / 2 - (int)(HEIGHT / (pgm->coord.real_distance * 2));
	if (pgm->top < 0)
		pgm->top = 0;
	pgm->bottom = HEIGHT / 2 + (int)(HEIGHT / (pgm->coord.real_distance * 2));
	if (pgm->bottom > HEIGHT)
		pgm->bottom = HEIGHT;
	if (pgm->coord.impact_point == 0)
		pgm->coord.wall_x = (pgm->coord.y
				+ (pgm->coord.real_distance * pgm->coord.ray_dir_y));
	else
		pgm->coord.wall_x = (pgm->coord.x
				+ (pgm->coord.real_distance * pgm->coord.ray_dir_x));
	pgm->coord.wall_x -= floor(pgm->coord.wall_x);
	step = calculate_step(pgm);
	paint_line(pgm, step, i);
}
