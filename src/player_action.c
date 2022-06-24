/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:09:10 by bbali             #+#    #+#             */
/*   Updated: 2022/06/23 17:08:36 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_root *root)
{
	if (!root->game->\
	map[root->game->player_coord.y - 1][root->game->player_coord.x])
		root->game->player_coord.y -= 1;
}

void	move_down(t_root *root)
{
	if (!root->game->\
	map[root->game->player_coord.y + 1][root->game->player_coord.x])
		root->game->player_coord.y += 1;
}

void	move_left(t_root *root)
{
	if (!root->game->\
	map[root->game->player_coord.y][root->game->player_coord.x - 1])
		root->game->player_coord.x -= 1;
}

void	move_right(t_root *root)
{
	if (!root->game->\
	map[root->game->player_coord.y][root->game->player_coord.x + 1])
		root->game->player_coord.x += 1;
}
