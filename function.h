#ifndef FUNCTION_H
# define FUNCTION_H

//for mac_os
//# include "minilibx/mlx.h"
//for Linux
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// check dans le makefile
# include <X11/keysym.h>
# include <unistd.h>
# include "get_next_line.h"
# define TRUE 0
# define FALSE 1
# define HT 1000
# define WT 1000

typedef struct s_check
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}				t_check;

typedef struct s_save
{
	void	*img;
	char	*addr;
}				t_save;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

//corespond a notre structure global
typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	t_data	image;
	t_check	check;
}				t_ptr;



int		key_esc(int key, t_ptr *pgm);
int		ft_close(t_ptr *pgm);
int		key_manager(int key, t_ptr *pgm);
int		ft_black(t_ptr *pgm);
void	ft_zoom_in(t_ptr *pgm, double zoom_f);
int		create_color(int t, int r, int g, int b);
int		palette(int i);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
--------------------------------------------
*/

char	*get_next_line(int fd);
void	ft_putstr_error(char *s);
int		ft_is_space(char c);
char	**parsing(int argc, char **argv, int *nb_line);
void	print_tab_2d(char **strs);
int		ft_count_line(char **tab);
void	ft_putstr_fd(char *s, int fd);
int 	find_max_lenght(char **map);
void	*ft_free_tab_2d(char **tab);
char	*ft_strjoin_free(char *s1, char *s2, int del);
char	**adjust_map(char **map, int nb_line);

#endif