/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:20:58 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/17 10:53:44 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

static int	ft_count_line_map(char *file)
{
	size_t	nb_line;
	int		fd;
	char	*ret;

	nb_line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	ret = get_next_line(fd);
	if (!ret)
		return (-1);
	while (ret)
	{
		nb_line++;
		free(ret);
		ret = get_next_line(fd);
	}
	close(fd);
	return (nb_line);
}

static char	**ft_convert_map_error(char **strs, char *ret, int fd, int i)
{
	free(ret);
	close(fd);
	strs[i] = NULL;
	ft_free_tab_2d(strs);
	return (NULL);
}

static char	**ft_convert_map(char **strs, char *file)
{
	int		i;
	int		fd;
	char	*ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	ret = get_next_line(fd);
	while (ret)
	{
		strs[i] = ft_strdup(ret);
		if (!strs[i])
			return (ft_convert_map_error(strs, ret, fd, i));
		free(ret);
		ret = get_next_line(fd);
		i++;
	}
	close(fd);
	strs[i] = NULL;
	if (ret)
		free(ret);
	return (strs);
}

char	**parsing(int argc, char **argv, int *nb_line)
{
	char	**map;

	if (argc != 2)
		return (ft_putstr_error_char("Error\nwrong number of arguments\n"));
	*nb_line = ft_count_line_map(argv[1]);
	if (*nb_line == -1)
		return (ft_putstr_error_char("Error\nfile map does not exist\n"));
	map = ft_calloc(sizeof(char *), (*nb_line + 1));
	if (!map)
		return (ft_putstr_error_char("Error\nCalloc failed\n"));
	map = ft_convert_map(map, argv[1]);
	if (!map)
		return (ft_putstr_error_char("Malloc failed\n"));
	return (map);
}
