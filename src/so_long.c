/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:08:34 by bbali             #+#    #+#             */
/*   Updated: 2022/07/03 21:53:42 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_imgs(void)
{
	int		fd[5];
	int		i;

	i = -1;
	fd[0] = open("./imgs/L_teemo.xpm", O_RDONLY);
	fd[1] = open("./imgs/portal_open.xpm", O_RDONLY);
	fd[2] = open("./imgs/mushroom.xpm", O_RDONLY);
	fd[3] = open("./imgs/wall.xpm", O_RDONLY);
	fd[4] = open("./imgs/grass.xpm", O_RDONLY);
	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1 || fd[3] == -1 || fd[4] == -1)
	{
		while (++i < 5)
			if (fd[i] != -1)
				close (fd[i]);
		end("Image(s) not found", 0);
	}
	else
	{
		while (++i < 5)
			close (fd[i]);
	}
}

static void	check_args(int ac, char *file)
{
	int				len;

	if (ac != 2)
		end("Need two arguments", 0);
	len = ft_strlen(file);
	if (file == 0 || len < 5 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
		end("Incorrect file", 0);
}

int	main(int ac, char *av[])
{
	t_root	*root;

	check_args(ac, av[1]);
	check_imgs();
	root = init_root(av[1]);
	render(root);
	mlx_hook(root->win, 2, 1L << 0, key_press, root);
	mlx_hook(root->win, 3, 1L << 1, key_release, root);
	mlx_hook(root->win, 17, 1L << 17, destroy_hook, root);
	mlx_loop(root->mlx);
	return (0);
}
