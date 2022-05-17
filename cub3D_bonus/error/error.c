/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:44:39 by gmary             #+#    #+#             */
/*   Updated: 2022/05/16 10:44:40 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

int	ft_putstr_error(char *s)
{
	if (s)
	{
		write(2, s, ft_strlen(s));
	}
	return (FALSE);
}

char	**ft_putstr_error_char(char *s)
{
	if (s)
	{
		write(2, s, ft_strlen(s));
	}
	return (NULL);
}

int	ft_check_error(t_ptr *pgm, char **all)
{
	ft_free_tab_2d(all);
	ft_free_tab_2d(pgm->map);
	ft_free_tab_2d(pgm->param);
	ft_putstr_error("some issue with file\n");
	return (FALSE);
}
