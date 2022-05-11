#ifndef FUNCTION_H
# define FUNCTION_H

//for mac_os
//# include "minilibx/mlx.h"
//for Linux
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// check dans le makefile
# include <X11/keysym.h>
# include <unistd.h>
# include <math.h>
# include <stdint.h>
# include <inttypes.h>
# include "get_next_line.h"
# define TRUE 0
# define FALSE 1
# define FULL 10
# define HEIGHT 480
# define WIDTH 640
# define NO 100
# define SO 101
# define EA 102
# define WE 103
# define FLOOR 104
# define CEIL 105
# define FOV 0.62
# define SPEED 0.1
/*
	box_x et y sont les coordonnees de la du carre ou le joueur se trouve
	direction_x et y sont les directions du joueur (par exmple N au depart))
	plane_x et y sont les coordonnees du plan de vision du joueur
	et x et y correspond a la valeur de la position du joueur precise
*/

typedef struct s_coord
{
	double	x;
	double	y;
	double	direction_x;
	double	direction_y;
	double	plane_x;
	double	plane_y;
	int		box_x;
	int		box_y;
	double	pos_x_camera;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	all_dist_box_x;
	double	all_dist_box_y;
	double	move_x;
	double	move_y;
	double	impact_point;
	double	real_distance;
}				t_coord;

typedef struct s_save
{
	void	*img;
	char	*addr;
}				t_save;

typedef struct s_data
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

//corespond a notre structure global
typedef struct s_ptr
{
	t_data	image;
	t_data	north;
	//t_data	so;
	//t_data	ea;
	//t_data	we;
	//t_data	no;
	//t_data	so;
	//t_data	ea;
	//t_data	we;
	t_coord	coord;
	int		pos;
	int 	nb_line;
	void	*mlx;
	void	*win;
	char	**param;
	char	**map;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	int		floor;
	int		ceil;
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
int		create_color(int t, int r, int g, int b);
void	ft_bicolor(t_ptr *pgm, int color_floor, int color_ceil);
void	pgm_image_init(t_ptr *pgm, t_data *image);

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
char	*ft_strndup(char *str, int n);

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

int ft_check(char **all, char *name, int nb_line, t_ptr *pgm);

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
------------------INIT GAME-------------------------
*/

void	launch_game(t_ptr *pgm);
void	find_pos(t_ptr *pgm);

/*
------------------CONVERT PARAM-------------------------
*/

int	convert_param(t_ptr *pgm);

/*
------------------SPLIT--------------------------
*/

char    **ft_split(char *str, char *charset);

/*
------------------CLEAN AND CLOSE--------------------------
*/

int	ft_close(t_ptr *pgm);

/*
------------------KEYS--------------------------
*/

int	key_main(int key, t_ptr *pgm);
int key_release(int key, t_ptr *pgm);


/*
------------------COLOR--------------------------
*/

//int	ft_vertical(int x, int top, int bottom, t_ptr *pgm);
int	ft_vertical(int x, int top, int bottom, t_ptr *pgm, int shade);

/*
------------------SECURE MAP-------------------------
*/

int	secure_map(t_ptr *pgm);

#endif