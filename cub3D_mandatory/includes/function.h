/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:45:00 by gmary             #+#    #+#             */
/*   Updated: 2022/05/17 18:44:05 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H
/* for mac_os
# include "minilibx/mlx.h"
for Linux */
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
/* check dans le makefile */
# include <X11/keysym.h>
# include <unistd.h>
# include <math.h>
# include <stdint.h>
# include <inttypes.h>
# include "get_next_line.h"
# define TRUE 0
# define FALSE 1
# define FULL 10
# define HEIGHT 1000/*480*/ /* 960  */
# define WIDTH 1000/*640 *//* 1280  */
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
	int		cardinal_wall;
	double	wall_x;
	int		texture_x;
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

typedef struct s_ptr
{
	t_data	image;
	t_data	north;
	t_data	south;
	t_data	east;
	t_data	west;
	t_coord	coord;
	int		pos;
	int		nb_line;
	int		top;
	int		bottom;
	void	*mlx;
	void	*win;
	char	**param;
	char	**map;
	int		**buff;
	int		floor;
	int		ceil;
}				t_ptr;

/*
------------------MLX-------------------------
*/

int			key_esc(int key, t_ptr *pgm);
int			ft_close(t_ptr *pgm);
int			key_manager(int key, t_ptr *pgm);
int			ft_black(t_ptr *pgm);
void		ft_zoom_in(t_ptr *pgm, double zoom_f);
int			create_color(int t, int r, int g, int b);
int			palette(int i);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_color(int t, int r, int g, int b);
void		ft_bicolor(t_ptr *pgm, int color_floor, int color_ceil);

/*
------------------INIT--------------------------
*/

void		ft_set_null(t_ptr *pgm);
void		pgm_image_init(t_ptr *pgm, t_data *image);

/*
------------------GNL---------------------------
*/

char		*get_next_line(int fd);

/*
------------------UTILS--------------------------
*/

int			ft_strcmp(char *s1, char *s2);
int			ft_strchr_str(char *s, char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_is_space(char c);
void		*ft_free_tab_2d(char **tab);
char		*ft_strjoin_free(char *s1, char *s2, int del);
void		print_tab_2d(char **strs);
int			ft_count_line(char **tab);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isdigit(int c);
int			ft_atoi(char *str);
char		**cpy_tab(char **srcs, int nb_line);
int			line_is_whitespace(char *str);
char		*ft_strndup(char *str, int n);
void		ft_free_buff(t_ptr *pgm);
void		*__free(void *str);
int			ft_free_tab_2d_int(char **tab);
/*
------------------CHECK MAP----------------------
*/

int			check_first_last(char **map, int nb_line);
int			check_forbiden_char(char c);
int			check_name_map(char *name);
int			find_max_lenght(char **map);
char		**adjust_map(char **map, int nb_line);
int			check_map(char **map, int nb_line);
int			check_start_char(char c);
/*
-----------------CHECK-------------------------
*/

int			ft_check(char **all, char *name, int nb_line, t_ptr *pgm);
int			check_double(char **map);
int			check_map(char **map, int nb_line);
int			check_horizon(char *line);
int			check_vertical(char **map, int column, int nb_line);
int			check_is_param(char *str);
int			tab_is_full(int *tab);

/*
-----------------CHECK COLOR----------------------
*/

int			check_color(char *str);

/*
------------------ERROR--------------------------
*/

int			ft_putstr_error(char *s);
int			ft_check_error(t_ptr *pgm, char **all);
char		**ft_putstr_error_char(char *s);

/*
------------------PARSING-------------------------
*/

char		**parsing(int argc, char **argv, int *nb_line);

/*
------------------INIT GAME-------------------------
*/

void		launch_game(t_ptr *pgm);
void		find_pos(t_ptr *pgm);
void		find_impact(t_ptr *pgm);
void		find_intersection(t_ptr *pgm);

/*
------------------CONVERT PARAM-------------------------
*/

int			convert_param(t_ptr *pgm);
char		*find_cardinal_path(char *path);
void		convert_floor_ceil(t_ptr *pgm, char *path, int dir);
int			init_struct(t_ptr *pgm);
char		*convert_cardinal_path(char *str);

/*
------------------SPLIT--------------------------
*/

char		**ft_split(char *str, char *charset);

/*
------------------CLEAN AND CLOSE--------------------------
*/

int			ft_close(t_ptr *pgm);

/*
------------------KEYS--------------------------
*/

int			key_main(int key, t_ptr *pgm);
int			key_release(int key, t_ptr *pgm);
void		key_mv_left(t_ptr *pgm);
void		key_mv_right(t_ptr *pgm);
int			key_main(int key, t_ptr *pgm);
int			key_release(int key, t_ptr *pgm);
int			key_manager(int key, t_ptr *pgm);
void		key_up(t_ptr *pgm);
void		key_left(t_ptr *pgm);
void		key_right(t_ptr *pgm);
void		key_down(t_ptr *pgm);

/*
------------------COLOR--------------------------
*/

char		*convert_color_take(char *str);

/*
------------------SECURE MAP-------------------------
*/

int			secure_map(t_ptr *pgm);

/*
------------------DRAW------------------------------
*/
void		draw_buffer(t_ptr *pgm);
void		define_walls(t_ptr *pgm);
void		find_texture_x(t_ptr *pgm, int cardinal_wall);

/* 
------------------MLX-------------------------------
*/

void		__mlx_loop_hook(t_ptr *ptr);

/*
------------------PAINT WORLD------------------------
*/

void		paint_world(t_ptr *pgm, double i);

#endif