/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:10:31 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/16 19:04:28 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

void	draw_buffer(t_ptr *pgm)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			pgm->image.addr[i * WIDTH + j] = pgm->buff[i][j];
			j++;
		}
		i++;
	}
}

/*Permet de dessiner le plafond et le mur en fonction des couleurs donnees*/

void	ft_bicolor(t_ptr *pgm, int color_floor, int color_ceil)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (j < HEIGHT / 2)
				pgm->buff[j][i] = color_ceil;
			else
				pgm->buff[j][i] = color_floor;
			j++;
		}
		i++;
	}
	draw_buffer(pgm);
}
