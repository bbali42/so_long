/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:10:55 by bbali             #+#    #+#             */
/*   Updated: 2022/07/03 22:30:43 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_counter(t_root *root)
{
	char	*move_counter;

	if (BONUS)
	{
		move_counter = ft_itoa(root->game->move_counter);
		mlx_string_put(root->mlx, root->win, 15, 20, 16731469, "Counter:");
		mlx_string_put(root->mlx, root->win, 80, 20, 16731469, move_counter);
		if (move_counter)
			free(move_counter);
	}
	else
	{
		ft_putnbr_fd(root->game->move_counter, 1);
		ft_putendl_fd("", 1);
	}
}

static void	is_collectable(t_root *root)
{
	int				n;

	n = 0;
	while (n < root->game->count_items)
	{
		if (root->game->item_coord[n].x == root->game->player_coord.x
			&& root->game->item_coord[n].y == root->game->player_coord.y)
		{
			root->game->item_coord[n].x = -1;
			root->game->item_coord[n].y = -1;
			root->game->items_collected++;
		}
		n++;
	}
}

void	update(t_root *root)
{
	if (root->game->move_up)
		move_up(root);
	else if (root->game->move_down)
		move_down(root);
	else if (root->game->move_left)
		move_left(root);
	else if (root->game->move_right)
		move_right(root);
	is_collectable(root);
	render(root);
	if (root->game->exit_coord.x == root->game->player_coord.x
		&& root->game->exit_coord.y == root->game->player_coord.y)
		if (root->game->count_items == root->game->items_collected)
			end_game(root, 0, 0);
}
