/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:19:25 by bbali             #+#    #+#             */
/*   Updated: 2022/06/23 17:07:01 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_width(t_root *root, char *file)
{
	root->game->width = 0;
	while (file[root->game->width] && file[root->game->width] != '\n')
		root->game->width++;
	if (!root->game->width || !file[root->game->width])
	{
		free(file);
		end_game(root, "map file is invalid", 0);
	}
}

void	map_height(t_root *root, char *file)
{
	int				i;
	int				j;

	root->game->height = 1;
	i = root->game->width + 1;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i + j] && file[i + j] != '\n')
			j++;
		if (root->game->width != j)
		{
			free(file);
			end_game(root, "map format is invalid", 0);
		}
		i += root->game->width + 1;
		root->game->height++;
	}
}

void	is_valid_elem(t_root *root, char *file, int i)
{
	if (file[i] == 'P')
		root->game->count_player++;
	else if (file[i] == 'E')
		root->game->count_exit++;
	else if (file[i] == 'C')
		root->game->count_items++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		end_game(root, "map content is invalid", 0);
	}
}

int	is_border(t_root *root, int i)
{
	if (i < root->game->width
		|| i > (root->game->width + 1) * (root->game->height - 1)
		|| i % (root->game->width + 1) == 0
		|| i % (root->game->width + 1) == root->game->width - 1)
		return (1);
	return (0);
}

void	is_valid_map(t_root *root, char *file)
{
	int				i;

	i = -1;
	while (file[++i])
	{
		if (file[i] == '\n')
			continue ;
		if (is_border(root, i))
		{
			if (file[i] != '1')
			{
				free(file);
				end_game(root, "map isn't surrounded by walls", 0);
			}
		}
		else
			is_valid_elem(root, file, i);
	}
	if (root->game->count_player != 1
		|| root->game->count_exit != 1
		|| root->game->count_items < 1)
	{
		free(file);
		end_game(root, "map configuration is invalid", 0);
	}
}
