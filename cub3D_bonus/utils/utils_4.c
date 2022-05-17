/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:09:56 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/16 11:21:30 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

char	*ft_strndup(char *str, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = ft_calloc(sizeof(char), n + 1);
	if (!dest)
		return (NULL);
	while (str[i] && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_free_buff(t_ptr *pgm)
{
	int	i;

	i = 0;
	if (!pgm->buff)
		return ;
	while (i < HEIGHT)
	{
		free(pgm->buff[i]);
		i++;
	}
	free(pgm->buff);
}

int	count_without_empty_line(char **srcs, int nb_line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (srcs[i] && i < nb_line)
	{
		if (ft_strcmp(srcs[i], "\n"))
			count++;
		i++;
	}
	return (count);
}

char	**cpy_tab(char **srcs, int nb_line)
{
	int		len;
	int		i;
	int		j;
	char	**new_tab;

	i = 0;
	j = 0;
	len = count_without_empty_line(srcs, nb_line);
	new_tab = ft_calloc(sizeof(char *), (len + 1));
	if (!new_tab)
		return (NULL);
	while (srcs[i] && i < nb_line)
	{
		if (ft_strcmp(srcs[i], "\n"))
		{
			new_tab[j] = ft_strdup(srcs[i]);
			if (!new_tab[j])
				return (ft_free_tab_2d(new_tab));
			j++;
		}
		i++;
	}
	new_tab[j] = NULL;
	return (new_tab);
}

int	ft_strchr_str(char *s, char *str)
{
	while (*s)
	{
		if (*s == str[0])
		{
			if (ft_strcmp(s, str) == 0)
			{
				return (TRUE);
			}
		}
		s++;
	}
	return (FALSE);
}
