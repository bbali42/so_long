/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:08:34 by bbali             #+#    #+#             */
/*   Updated: 2022/06/21 19:50:44 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int ac, char *file)
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
	root = init_root(av[1]);
	render(root);
	mlx_hook(root->win, 2, 1L << 0, key_press, root);
	mlx_hook(root->win, 3, 1L << 1, key_release, root);
	mlx_hook(root->win, 17, 1L << 17, destroy_hook, root);
	mlx_loop(root->mlx);
	return (0);
}
