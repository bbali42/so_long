/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:17:43 by bbali             #+#    #+#             */
/*   Updated: 2022/06/23 17:13:10 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_file(t_root *root, char **file, char buf[], int fd)
{
	char			*tmp;

	tmp = ft_strjoin(*file, buf);
	free(*file);
	*file = tmp;
	if (!*file)
	{
		close(fd);
		end_game(root, "init_map(): parse_file()", errno);
	}
}

static void	read_file(t_root *root, char **file, char buf[], int fd)
{
	int				res;

	res = 1;
	while (res != 0)
	{
		res = read(fd, buf, 1024);
		if (res == -1)
		{
			free(*file);
			close(fd);
			end_game(root, "init_map(): read_file()", errno);
		}
		else
		{
			buf[res] = 0;
			parse_file(root, file, buf, fd);
		}
	}
}

static char	*init_file(t_root *root, int fd)
{
	char			*file;

	file = ft_calloc(1, 1);
	if (!file)
	{
		close(fd);
		end_game(root, "init_map(): init_file()", errno);
	}
	return (file);
}

void	init_map(t_root *root, char *filename)
{
	int				fd;
	char			*file;
	char			buf[1024 + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		end_game(root, filename, errno);
	file = init_file(root, fd);
	read_file(root, &file, buf, fd);
	close(fd);
	parse_map(root, file);
	free(file);
}
