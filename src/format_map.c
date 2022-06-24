/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:13:44 by bbali             #+#    #+#             */
/*   Updated: 2022/06/23 17:13:24 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_matrix(t_root *root, char *file, int **m, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	root->game->map = 0;
	free(file);
	end_game(root, "format_map(): malloc()", errno);
}

static void	get_coord(t_root *root, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		root->game->player_coord.x = k % (root->game->width + 1);
		root->game->player_coord.y = k / (root->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'E')
	{
		root->game->exit_coord.x = k % (root->game->width + 1);
		root->game->exit_coord.y = k / (root->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'C')
	{
		root->game->item_coord[*obj].x = k % (root->game->width + 1);
		root->game->item_coord[*obj].y = k / (root->game->width + 1);
		file[k] = '0';
		(*obj)++;
	}
}

void	parse_map(t_root *root, char *file)
{
	map_width(root, file);
	map_height(root, file);
	is_valid_map(root, file);
	root->game->item_coord
		= (t_coord *)malloc(sizeof(t_coord) * root->game->count_items);
	if (root->game->item_coord == 0)
	{
		free(file);
		end_game(root, "parse_map(): malloc()", errno);
	}
	root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
	if (!root->game->map)
	{
		free(file);
		end_game(root, "parse_map(): malloc()", errno);
	}
	format_map(root, file);
}

void	format_map(t_root *root, char *file)
{
	int				i;
	int				j;
	int				k;
	int				obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < root->game->height)
	{
		root->game->map[j] = (int *)malloc(sizeof(int) * root->game->width);
		if (!root->game->map[j])
			free_matrix(root, file, root->game->map, j);
		i = 0;
		while (i < root->game->width)
		{
			get_coord(root, file, k, &obj);
			root->game->map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}
