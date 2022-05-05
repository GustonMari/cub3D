#include "../includes/function.h"

/*Permet de convertir le path des points cardinaux
et le mettre dans la string path*/

char	*convert_cardinal_path(char *str)
{
	char	*path;
	int		len;

	len = 0;
	while (str[len] && (ft_is_space(str[len]) == FALSE))
		len++;
	//WARNING
	path = ft_strndup(str, len);
	if (!path)
		return (NULL);
	return (path);
}

/*Permet de d'ouvrir les textures des points cardinaux*/

int	convert_cardinal_points(t_ptr *pgm, char *path, int dir)
{
	if (dir == NO)
	{
		pgm->no = mlx_xpm_file_to_image(pgm->mlx, path,
				&pgm->image.width, &pgm->image.height);
		if (pgm->no == NULL)
			return (FALSE);
	}
	if (dir == SO)
	{
		pgm->so = mlx_xpm_file_to_image(pgm->mlx, path,
				&pgm->image.width, &pgm->image.height);
		if (pgm->so == NULL)
			return (FALSE);
	}
	if (dir == EA)
	{
		pgm->ea = mlx_xpm_file_to_image(pgm->mlx, path,
				&pgm->image.width, &pgm->image.height);
		if (pgm->ea == NULL)
			return (FALSE);
	}
	if (dir == WE)
	{
		pgm->we = mlx_xpm_file_to_image(pgm->mlx, path,
				&pgm->image.width, &pgm->image.height);
		if (pgm->we == NULL)
			return (FALSE);
	}
	return (TRUE);
}

/*Va renvoyer le debut du path*/

char	*find_cardinal_path(char *path)
{
	int	i;

	i = 2;
	while (path[i] && (ft_is_space(path[i]) == TRUE))
		i++;
	return (&path[i]);
}

int	convert_param_2(t_ptr *pgm, char *str_param, int dir)
{
	char	*path;

	path = convert_cardinal_path(find_cardinal_path(str_param));
	if (!path)
	{
		ft_putstr_error("Error\nMalloc failed\n");
		return (FALSE);
	}
	if (convert_cardinal_points(pgm, path, dir) == FALSE)
	{
		ft_putstr_error("Error\nImpossible to open texture\n");
		free(path);
		return (FALSE);
	}
	free(path);
	return (TRUE);
}

/*Permet la converion des chiffres (exe: 255,0,0) 
vers l'int qui serra stocke par la suite dans la struct*/

void	convert_floor_ceil(t_ptr *pgm, char *path, int dir)
{
	char	**tab;

	tab = ft_split(path, ", ");
	if (dir == FLOOR)
		pgm->floor = create_color(0,
				ft_atoi(tab[0]), ft_atoi(tab[1]), ft_atoi(tab[2]));
	if (dir == CEIL)
		pgm->ceil = create_color(0,
				ft_atoi(tab[0]), ft_atoi(tab[1]), ft_atoi(tab[2]));
	free(path);
	ft_free_tab_2d(tab);
}

/*Converti les param et les mets dans la structure*/

int	convert_param(t_ptr *pgm)
{
	int		i;
	int		j;

	i = 0;
	//print_tab_2d(pgm->param);
	while (pgm->param[i])
	{
		j = 0;
		while (pgm->param[i][j] && (ft_is_space(pgm->param[i][j]) == TRUE))
			j++;
		if (ft_strncmp(pgm->param[i], "NO", 2) == TRUE)
		{
			if (convert_param_2(pgm, &pgm->param[i][j], NO) == FALSE)
				return (FALSE);
		}
		if (ft_strncmp(pgm->param[i], "SO", 2) == TRUE)
		{
			if (convert_param_2(pgm, &pgm->param[i][j], SO) == FALSE)
				return (FALSE);
		}
		if (ft_strncmp(pgm->param[i], "EA", 2) == TRUE)
		{
			if (convert_param_2(pgm, &pgm->param[i][j], EA) == FALSE)
				return (FALSE);
		}
		if (ft_strncmp(pgm->param[i], "WE", 2) == TRUE)
		{
			if (convert_param_2(pgm, &pgm->param[i][j], WE) == FALSE)
				return (FALSE);
		}
		if (ft_strncmp(pgm->param[i], "F", 1) == TRUE)
		{
			convert_floor_ceil(pgm, convert_cardinal_path(find_cardinal_path(&pgm->param[i][j])), FLOOR);
		}
		if (ft_strncmp(pgm->param[i], "C", 1) == TRUE)
			convert_floor_ceil(pgm, convert_cardinal_path(find_cardinal_path(&pgm->param[i][j])), CEIL);
		i++;
	}
	//ft_bicolor(pgm, pgm->floor, pgm->ceil);
	return (TRUE);
}
