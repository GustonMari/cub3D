/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:16:40 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/16 19:30:35 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

// double get_dec(double d)
// {
// 	printf("%f\n", d - (int)d);
// 	return (d - (int)d);
// }

uint32_t	choose_color(t_ptr *pgm, int texy)
{
	uint32_t	color;

	// printf("%d\n", pgm->east.bpp);
	// fprintf(stderr, "pgm->north.width = %d\n", pgm->north.width);
	// fprintf(stderr, "pgm->north.height = %d\n", pgm->north.height);
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
	// fprintf(stderr, "bpp= %d\n", pgm->north.bpp);
	// fprintf(stderr, "width= %d\n", pgm->north.width);
	// fprintf(stderr, "height= %d\n", pgm->north.height);
	// fprintf(stderr, "endian= %d\n", pgm->north.endian);
	// fprintf(stderr, "line_lenght= %d\n", pgm->north.line_length);
	// exit(0);
	while (y < pgm->bottom)
	{
		find_texture_x(pgm, pgm->coord.cardinal_wall);
		if (pgm->coord.cardinal_wall == NO)
		{
			//fprintf(stderr, "top = %d\n", pgm->top);
			//fprintf(stderr, "pgm->north.height = %d\n", pgm->north.height);
			//fprintf(stderr, "")
			texy = (int)(texpos) /* & (pgm->north.height256 - 1) */;
		//	texy = (int)(texpos) & (/* pgm->north.height */256 - 1);

			//fprintf(stderr, "texy = %d\n", texy);
			//fprintf(stderr, "texpos = %f\n", texpos);
		}
		else if (pgm->coord.cardinal_wall == SO)
		{
			//fprintf(stderr, "pgm->south.height = %d\n", pgm->south.height);
			texy = (int)(texpos)/*  & (pgm->south.height - 1) */;
			//fprintf(stderr, "texy = %d\n", texy);
		}
		else if (pgm->coord.cardinal_wall == EA)
			texy = (int)(texpos)/*  & (pgm->east.height - 1) */;
		else if (pgm->coord.cardinal_wall == WE)
			texy = (int)(texpos)/*  & (pgm->west.height - 1) */;
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
