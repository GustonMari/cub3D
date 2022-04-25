#ifndef FUNCTION_H
# define FUNCTION_H

//for mac_os
# include "minilibx/mlx.h"
//for Linux
//# include "minilibx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// check dans le makefile
# include <X11/keysym.h>
# include <unistd.h>
# define HT 1000
# define WT 1000

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
}				t_ptr;

int		key_esc(int key, t_ptr *pgm);
int		ft_close(t_ptr *pgm);
int		mouse_scroll_3(int mse, int x, int y, t_ptr *pgm);
int		key_manager(int key, t_ptr *pgm);
int		mouse_scroll_2(int mse, int x, int y, t_ptr *pgm);
int		ft_black(t_ptr *pgm);
void	ft_zoom_in(t_ptr *pgm, double zoom_f);
int		create_color(int t, int r, int g, int b);
int		mouse_scroll(int mse, int x, int y, t_ptr *pgm);
int		palette(int i);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif