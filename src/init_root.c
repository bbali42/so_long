/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:28:09 by bbali             #+#    #+#             */
/*   Updated: 2022/06/27 21:14:39 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_root *root, char *filename)
{
	root->game = (t_game *)malloc(sizeof(t_game));
	if (!root->game)
		end_game(root, "init_game(): malloc()", errno);
	root->game->map = NULL;
	root->game->height = 0;
	root->game->width = 0;
	root->game->count_items = 0;
	root->game->count_exit = 0;
	root->game->count_player = 0;
	root->game->move_up = 0;
	root->game->move_down = 0;
	root->game->move_left = 0;
	root->game->move_right = 0;
	root->game->move_counter = 0;
	root->game->items_collected = 0;
	root->game->item_coord = NULL;
	root->game->skin = NULL;
	init_map(root, filename);
}

static void	init_win(t_root *root)
{
	root->mlx = mlx_init();
	if (!root->mlx)
		end_game(root, "mlx_init(): can't load mlx", 0);
	root->win = mlx_new_window(root->mlx, root->game->width * 40,
			root->game->height * 40, "so_long");
	if (!root->win)
		end_game(root, "mlx_new_window(): can't create a window", 0);
}

static void	load_xpm(t_root *root, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	if (!*img)
		end_game(root, "init_skin(): can't load image", 0);
	(*img)->width = width;
	(*img)->height = height;
}

static void	init_skin(t_root *root)
{
	root->game->skin = (t_skin *)malloc(sizeof(t_skin));
	if (!root->game->skin)
		end_game(root, "init_skin(): malloc()", errno);
	root->game->skin->mlx = mlx_new_image(root->mlx, root->game->width * 40,
			root->game->height * 40);
	if (!root->game->skin->mlx)
		end_game(root, "mlx_new_image(): can't create an image", 0);
	load_xpm(root, &root->game->skin->player, "./imgs/L_teemo.xpm");
	load_xpm(root, &root->game->skin->exit, "./imgs/portal_open.xpm");
	load_xpm(root, &root->game->skin->item, "./imgs/mushroom.xpm");
	load_xpm(root, &root->game->skin->wall, "./imgs/wall.xpm");
	load_xpm(root, &root->game->skin->ground, "./imgs/grass.xpm");
}

t_root	*init_root(char *filename)
{
	t_root			*root;

	root = (t_root *)malloc(sizeof(t_root));
	if (!root)
		end_game(0, "init_root(): malloc()", errno);
	root->mlx = NULL;
	root->win = NULL;
	root->game = NULL;
	init_game(root, filename);
	init_win(root);
	init_skin(root);
	return (root);
}
