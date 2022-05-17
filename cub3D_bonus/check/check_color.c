/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:44:18 by gmary             #+#    #+#             */
/*   Updated: 2022/05/16 10:44:19 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

/*Va checker si il n'y a pas d'espace entre
les chiffres 22  0,10  0,0 par exemple*/

int	check_color_space_bis(char *str, int *i, int *k)
{
	while (str[*i] && (ft_is_space(str[*i]) == TRUE))
		(*i)++;
	if (ft_strlen(str) == *i || ft_isdigit(str[*i]) == FALSE)
		return (FALSE);
	while (str[*i] && ft_isdigit(str[*i]) == TRUE)
		(*i)++;
	while (str[*i] && (ft_is_space(str[*i]) == TRUE))
		(*i)++;
	if (*k < 2)
	{
		if (str[*i] && ft_strncmp(&str[*i], ",", 1))
			return (FALSE);
	}
	else
	{
		if (str[*i] != '\0')
			return (FALSE);
	}
	(*i)++;
	(*k)++;
	return (TRUE);
}

int	check_color_space(char *str)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (str[i] && k < 3)
	{
		if (check_color_space_bis(str, &i, &k) == FALSE)
			return (FALSE);
	}
	if (k != 3)
		return (FALSE);
	return (TRUE);
}

/*Cette fonction va checker si les chiffre sont valides*/

int	check_color_number(char *str)
{
	char	**dest;
	int		i;
	int		nb;

	dest = NULL;
	i = 0;
	if (str[i + 1])
		dest = ft_split(&str[1], " ,");
	else
		return (FALSE);
	if (!dest)
		return (-1);
	while (i < 3)
	{
		nb = ft_atoi(dest[i]);
		if (nb < 0 || nb > 255)
		{
			ft_free_tab_2d(dest);
			return (FALSE);
		}
		i++;
	}
	ft_free_tab_2d(dest);
	return (TRUE);
}

/*Cette fonction va permettre de voir si 
les parametres F et C sont bien formattes
F 220,100,0 --> espace, bon nombre de virgules
et chiffres pas superieurs a 255 ni inferieur a 0*/

int	check_color(char *str)
{
	if (check_color_space(str) == FALSE)
		return (FALSE);
	if (check_color_number(str) == FALSE)
		return (FALSE);
	return (TRUE);
}
