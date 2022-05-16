/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:20:55 by gmary             #+#    #+#             */
/*   Updated: 2022/05/16 16:15:23 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/function.h"

int	main(int argc, char **argv, char **envp)
{
	int		nb_line;
	char	**all;
	t_ptr	pgm;

	all = NULL;
	nb_line = -1;
	ft_set_null(&pgm);
	if (*envp == NULL)
		return (ft_putstr_error("Error\nWhat can we do wihout env ?\n"));
	all = parsing(argc, argv, &nb_line);
	if (!all)
		return (FALSE);
	if (ft_check(all, argv[1], nb_line, &pgm) == FALSE)
		return (ft_check_error(&pgm, all));
	ft_free_tab_2d(all);
	pgm_image_init(&pgm, &pgm.image);
	if (convert_param(&pgm) == FALSE)
		return (ft_close(&pgm));
	if (secure_map(&pgm) == FALSE)
		return (ft_close(&pgm));
	find_pos(&pgm);
	launch_game(&pgm);
	__mlx_loop_hook(&pgm);
	return (TRUE);
}
