/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:00:01 by bbali             #+#    #+#             */
/*   Updated: 2022/06/27 19:50:12 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_root *root)
{
	if (keycode == 65307)
		end_game(root, 0, 0);
	if (keycode == 119)
		root->game->move_up = 1;
	if (keycode == 115)
		root->game->move_down = 1;
	if (keycode == 97)
		root->game->move_left = 1;
	if (keycode == 100)
		root->game->move_right = 1;
	update(root);
	return (0);
}

int	key_release(int keycode, t_root *root)
{
	if (keycode == 119)
		root->game->move_up = 0;
	if (keycode == 115)
		root->game->move_down = 0;
	if (keycode == 97)
		root->game->move_left = 0;
	if (keycode == 100)
		root->game->move_right = 0;
	return (0);
}

int	destroy_hook(t_root *root)
{
	end_game(root, 0, 0);
	return (0);
}
