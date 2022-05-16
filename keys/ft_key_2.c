/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:07:41 by gmary             #+#    #+#             */
/*   Updated: 2022/05/16 10:07:55 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

void	key_mv_left(t_ptr *pgm)
{
	if (pgm->map[(int)pgm->coord.y]
		[(int)(pgm->coord.x - pgm->coord.plane_x)] != '1')
		pgm->coord.x -= pgm->coord.plane_x * SPEED;
	if (pgm->map[(int)(pgm->coord.y - pgm->coord.plane_y)]
		[(int)(pgm->coord.x)] != '1')
		pgm->coord.y -= pgm->coord.plane_y * SPEED;
}

void	key_mv_right(t_ptr *pgm)
{
	if (pgm->map[(int)pgm->coord.y]
		[(int)(pgm->coord.x + pgm->coord.plane_x)] != '1')
		pgm->coord.x += pgm->coord.plane_x * SPEED;
	if (pgm->map[(int)(pgm->coord.y + pgm->coord.plane_y)]
		[(int)(pgm->coord.x)] != '1')
		pgm->coord.y += pgm->coord.plane_y * SPEED;
}

int	key_main(int key, t_ptr *pgm)
{
	if (key == XK_Escape)
		ft_close(pgm);
	if (key == XK_w || key == XK_Up)
		key_up(pgm);
	if (key == XK_s || key == XK_Down)
		key_down(pgm);
	if (key == XK_Left)
		key_left(pgm);
	if (key == XK_Right)
		key_right(pgm);
	if (key == XK_a)
		key_mv_left(pgm);
	if (key == XK_d)
		key_mv_right(pgm);
	return (0);
}

int	key_release(int key, t_ptr *pgm)
{
	(void)key;
	(void)pgm;
	return (0);
}

int	key_manager(int key, t_ptr *pgm)
{
	key_main(key, pgm);
	launch_game(pgm);
	return (0);
}
