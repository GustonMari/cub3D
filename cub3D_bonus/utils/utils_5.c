/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:19:48 by gmary             #+#    #+#             */
/*   Updated: 2022/05/16 10:41:23 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

void	*__free(void *str)
{
	free(str);
	return (NULL);
}

int	ft_free_tab_2d_int(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (FALSE);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (FALSE);
}
