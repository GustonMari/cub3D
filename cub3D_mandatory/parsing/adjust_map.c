/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:16:23 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/17 18:38:18 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

char	**adjust_map_free(char **new_map, char **map)
{
	ft_free_tab_2d(new_map);
	ft_free_tab_2d(map);
	return (NULL);
}

char	*adjust_map_3(char **map, int max_len, int i, int len)
{
	char	*new_map;

	if (map[i][len] == '\n')
	{
		new_map = ft_strdup_less(map[i], 1);
		if (!new_map)
			return (NULL);
	}
	else
	{
		new_map = ft_strdup(map[i]);
		if (!new_map)
			return (NULL);
	}
	while (ft_strlen(new_map) < max_len)
	{
		new_map = ft_strjoin_free(new_map, " ", 1);
		if (!new_map)
			return (NULL);
	}
	new_map = ft_strjoin_free(new_map, "\n", 1);
	if (!new_map)
		return (NULL);
	return (new_map);
}

char	**adjust_map_2(char **map, char **new_map, int max_len, int i)
{
	int	len;

	len = ft_strlen(map[i]);
	if (ft_strlen(map[i]) != max_len)
	{
		new_map[i] = adjust_map_3(map, max_len, i, len);
		if (!new_map[i])
			return (adjust_map_free(new_map, map));
	}
	else
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map)
			return (NULL);
	}
	return ((char **)"yes");
}

/* char	**adjust_map_2(char **map, char **new_map, int max_len, int i)
{
	int	len;

	len = ft_strlen(map[i]);
	if (ft_strlen(map[i]) != max_len)
	{
		if (map[i][len] == '\n')
		{
			new_map[i] = ft_strdup_less(map[i], 1);
			if (!new_map[i])
				return (adjust_map_free(new_map, map));
		}
		else
		{
			new_map[i] = ft_strdup(map[i]);
			if (!new_map[i])
				return (adjust_map_free(new_map, map));
		}
		while (ft_strlen(new_map[i]) < max_len)
		{
			new_map[i] = ft_strjoin_free(new_map[i], " ", 1);
			if (!new_map[i])
				return (adjust_map_free(new_map, map));
		}
		new_map[i] = ft_strjoin_free(new_map[i], "\n", 1);
		if (!new_map[i])
			return (adjust_map_free(new_map, map));
	}
	else
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map)
			return (NULL);
	}
	return ((char **)"yes");
} */

char	**adjust_map(char **map, int nb_line)
{
	int		i;
	int		max_len;
	char	**new_map;

	i = 0;
	new_map = NULL;
	max_len = find_max_lenght(map) - 1;
	if (max_len < 0)
		return (ft_free_tab_2d(map));
	new_map = ft_calloc(sizeof(char *), nb_line + 1);
	if (!new_map)
		return (ft_free_tab_2d(map));
	new_map[nb_line] = NULL;
	if (!new_map)
		return (NULL);
	while (i < nb_line)
	{
		if (adjust_map_2(map, new_map, max_len, i) == NULL)
			return (NULL);
		i++;
	}
	ft_free_tab_2d(map);
	return (new_map);
}
