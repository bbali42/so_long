/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:36:57 by bbali             #+#    #+#             */
/*   Updated: 2022/06/23 17:03:23 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_game(t_game *game)
{
	int				i;

	if (game)
	{
		if (game->item_coord)
			free(game->item_coord);
		if (game->map)
		{
			i = -1;
			while (++i < game->height)
				free(game->map[i]);
			free(game->map);
		}
		free(game);
	}
}

static void	destroy_skin(t_root *root)
{
	if (root->game->skin)
	{
		if (root->game->skin->player)
			mlx_destroy_image(root->mlx, root->game->skin->player);
		if (root->game->skin->exit)
			mlx_destroy_image(root->mlx, root->game->skin->exit);
		if (root->game->skin->item)
			mlx_destroy_image(root->mlx, root->game->skin->item);
		if (root->game->skin->wall)
			mlx_destroy_image(root->mlx, root->game->skin->wall);
		if (root->game->skin->ground)
			mlx_destroy_image(root->mlx, root->game->skin->ground);
		if (root->game->skin->mlx)
			mlx_destroy_image(root->mlx, root->game->skin->mlx);
		free(root->game->skin);
	}
}

void	end_game(t_root *root, char *errmsg, int errnum)
{
	if (root)
	{
		destroy_skin(root);
		if (root->win)
			mlx_destroy_window(root->mlx, root->win);
		if (root->mlx)
		{	
			mlx_destroy_display(root->mlx);
			free(root->mlx);
		}
		if (root->game)
			destroy_game(root->game);
		free(root);
	}
	end(errmsg, errnum);
}

void	end(char *errmsg, int errnum)
{
	if (errmsg || errnum)
		ft_putendl_fd("Error", 2);
	if (errmsg)
		ft_putstr_fd(errmsg, 2);
	if (errmsg && errnum)
		ft_putstr_fd(": ", 2);
	if (errnum)
		ft_putstr_fd(strerror(errnum), 2);
	if (errmsg || errnum)
	{
		ft_putendl_fd("", 2);
		exit(1);
	}
	exit(0);
}
