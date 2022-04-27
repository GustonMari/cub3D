#include "../function.h"

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
	while (ret)
	{
		nb_line++;
		free(ret);
		ret = get_next_line(fd);
	}
	return (nb_line);
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
			return (NULL);
		free(ret);
		ret = get_next_line(fd);
		i++;
	}
	strs[i] = NULL;
	if (ret)
		free(ret);
	return (strs);
}

char	**parsing(int argc, char **argv, int *nb_line)
{
	char	**map;

	if (argc != 2)
    {
        ft_putstr_error("Error, wrong number of arguments\n");
        exit(0);
    }
	*nb_line = ft_count_line_map(argv[1]);
	map = ft_calloc(sizeof(char *), (*nb_line + 1));
	if (!map)
    {
        ft_putstr_fd("Error\n", 2);
        exit(0);
        //Voir comment on exit
    }
	map = ft_convert_map(map, argv[1]);
	if (!map)
	{
        ft_putstr_error("Malloc failed\n");
        exit(0);
    }
	// if (ft_check(map, *nb_line) == 0)
	// {
	// 	ft_clean_tab2d(map);
	// 	write(2, "Error\n", 6);
	// 	ft_putstr_error("Mauvaise map\n");
	// 	exit(0);
	// }
	return (map);
}