#include "../includes/function.h"

char	**adjust_map(char **map, int nb_line)
{
	int		i;
	int		max_len;
	char	**new_map;

	i = 0;
	new_map = NULL;
	max_len = find_max_lenght(map) - 1;
	new_map = ft_calloc(sizeof(char *), nb_line + 1);
	if (!new_map)
	{
		ft_free_tab_2d(map);
		return (NULL);
	}
	new_map[nb_line] = NULL;
	if (!new_map)
		return (NULL);
	while (i < nb_line)
	{
		if (ft_strlen(map[i]) != max_len)
		{
			new_map[i] = ft_strdup_less(map[i], 1);
			if (!new_map[i])
			{
				ft_free_tab_2d(new_map);
				ft_free_tab_2d(map);
				return (NULL);
			}
			while (ft_strlen(new_map[i]) < max_len)
			{
				new_map[i] = ft_strjoin_free(new_map[i], " ", 1);
				if (!new_map[i])
				{
					ft_free_tab_2d(new_map);
					ft_free_tab_2d(map);
					return (NULL);
				}
			}
			new_map[i] = ft_strjoin_free(new_map[i], "\n", 1);
			if (!new_map[i])
			{
				ft_free_tab_2d(new_map);
				ft_free_tab_2d(map);
				return (NULL);
			}
		}
		else
		{
			new_map[i] = ft_strdup(map[i]);
			if (!new_map)
				return (NULL);
		}
		i++;
	}
	ft_free_tab_2d(map);
	return (new_map);
}
