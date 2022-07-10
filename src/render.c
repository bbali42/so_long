/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:14:27 by bbali             #+#    #+#             */
/*   Updated: 2022/06/27 19:49:42 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_img(t_root *root, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			mlx_render_pixel(root->game->skin->mlx, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	render_env(t_root *root, int i, int j)
{
	int				n;

	if (root->game->exit_coord.x == i && root->game->exit_coord.y == j)
		render_img(root, root->game->skin->exit, i * 40, j * 40);
	n = -1;
	while (++n < root->game->count_items)
		if (root->game->item_coord[n].x == i
			&& root->game->item_coord[n].y == j)
			render_img(root, root->game->skin->item, i * 40, j * 40);
	if (root->game->player_coord.x == i && root->game->player_coord.y == j)
		render_img(root, root->game->skin->player, i * 40, j * 40);
}

void	render(t_root *root)
{
	int				i;
	int				j;

	j = 0;
	while (j < root->game->height)
	{
		i = 0;
		while (i < root->game->width)
		{
			if (root->game->map[j][i] == 1)
				render_img(root, root->game->skin->wall, i * 40, j * 40);
			else
				render_img(root, root->game->skin->ground, i * 40, j * 40);
			render_env(root, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(root->mlx, root->win, root->game->skin->mlx, 0, 0);
	display_counter(root);
}
