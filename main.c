/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:20:55 by gmary             #+#    #+#             */
/*   Updated: 2022/05/09 14:57:39 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/function.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int main(int argc, char **argv)
{
	int nb_line;
	char **all;
	t_ptr	pgm;

	nb_line = -1;
	all = parsing(argc, argv, &nb_line);
	if (ft_check(all, argv[1], nb_line, &pgm) == FALSE)
	{
		printf("Probleme file-----------------------------------------\n");
		return (1);
	}
	pgm_image_init(&pgm, &pgm.image);
	if (convert_param(&pgm) == FALSE)
	{
		ft_free_tab_2d(all);
		ft_close(&pgm);
		return (1);
	}
	//WARNING
	if (secure_map(&pgm) == FALSE)
		return (FALSE);
	// printf("%s\n", pgm.map[0]);
	// printf("%s\n", pgm.map[nb_line + 1]);
	print_tab_2d(pgm.map);


	// find_pos(&pgm);
	// fprintf(stderr, "map = %c\n", pgm.map[9][2]);
	// launch_game(&pgm);
	// ft_free_tab_2d(all);
	// mlx_key_hook(pgm.win, &key_manager, &pgm);
	// mlx_hook(pgm.win, 17, 02, ft_close, &pgm);
	// mlx_loop(pgm.mlx);
	return (0);
}

