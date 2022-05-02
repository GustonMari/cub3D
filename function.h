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
# define FULL 10
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
	//t_check	check;
}				t_ptr;


/*
------------------MLX-------------------------
*/

int		key_esc(int key, t_ptr *pgm);
int		ft_close(t_ptr *pgm);
int		key_manager(int key, t_ptr *pgm);
int		ft_black(t_ptr *pgm);
void	ft_zoom_in(t_ptr *pgm, double zoom_f);
int		create_color(int t, int r, int g, int b);
int		palette(int i);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
------------------GNL---------------------------
*/

char	*get_next_line(int fd);

/*
------------------UTILS--------------------------
*/

int		ft_strcmp(char *s1, char *s2);
int		ft_strchr_str(char *s, char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_is_space(char c);
void	*ft_free_tab_2d(char **tab);
char	*ft_strjoin_free(char *s1, char *s2, int del);
void	print_tab_2d(char **strs);
int		ft_count_line(char **tab);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
char	**cpy_tab(char **srcs, int nb_line);
int		line_is_whitespace(char *str);


/*
------------------CHECK MAP----------------------
*/

int		check_first_last(char **map, int nb_line);
int		check_forbiden_char(char c);
int		check_name_map(char *name);
int		find_max_lenght(char **map);
char	**adjust_map(char **map, int nb_line);
int		check_map(char **map, int nb_line);
int		check_start_char(char c);
/*
-----------------CHECK-------------------------
*/

int ft_check(char **map, char *name, int nb_line);

/*
-----------------CHECK COLOR----------------------
*/

int check_color(char *str);


/*
------------------ERROR--------------------------
*/

void	ft_putstr_error(char *s);

/*
------------------PARSING-------------------------
*/

char	**parsing(int argc, char **argv, int *nb_line);

/*
------------------SPLIT--------------------------
*/

char    **ft_split(char *str, char *charset);

#endif