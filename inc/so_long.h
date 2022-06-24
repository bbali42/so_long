/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:22:45 by bbali             #+#    #+#             */
/*   Updated: 2022/06/23 22:53:09 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_skin
{
	t_img			*mlx;
	t_img			*player;
	t_img			*exit;
	t_img			*item;
	t_img			*wall;
	t_img			*ground;
}				t_skin;

typedef struct s_game
{
	int				**map;
	int				height;
	int				width;
	int				count_items;
	int				count_exit;
	int				count_player;
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	int				move_counter;
	int				items_collected;
	t_coord			player_coord;
	t_coord			exit_coord;
	t_coord			*item_coord;
	t_skin			*skin;
}				t_game;

typedef struct s_root
{
	void			*mlx;
	void			*win;
	t_game			*game;
}				t_root;

//init_root.c
t_root			*init_root(char *filename);
//end_game.c
void			end(char *errmsg, int errnum);
void			end_game(t_root *root, char *errmsg, int errnum);
//init_map.c
void			init_map(t_root *specs, char *filename);
void			read_map(t_root *root, char *file);
//format_map.c | check_map_utils.c
void			map_width(t_root *root, char *file);
void			map_height(t_root *root, char *file);
void			is_valid_elem(t_root *root, char *file, int i);
int				is_border(t_root *root, int i);
void			is_valid_map(t_root *root, char *file);
void			parse_map(t_root *root, char *file);
void			format_map(t_root *root, char *file);
//render.c
void			render(t_root *root);
//mlx_utils.c
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void			mlx_render_pixel(t_img *mlx_img, int x, int y, int color);
//input_event.c
int				key_press(int keycode, t_root *root);
int				key_release(int keycode, t_root *root);
int				destroy_hook(int keycode, t_root *root);
//player_action.c
void			move_up(t_root *root);
void			move_down(t_root *root);
void			move_left(t_root *root);
void			move_right(t_root *root);
//update.c
void			update(t_root *root);
void			display_counter(t_root *root);

#endif
