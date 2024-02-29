/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:01:18 by llitovuo          #+#    #+#             */
/*   Updated: 2024/02/23 11:39:46 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int validate_input(int ac, char **av);

int	main(int ac, char **av)
{
	t_data	d;
	t_map	m;

	init_structs(d, m);
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		exit (1);
	validate_input(ac, av);
	validate_map(av);
	d->win_ptr = mlx_new_window(d->mlx_ptr, m->size_x, m->size_y, "so_long");
	if (d->win_ptr)
	{
		free_data(d);
		free_map(m);
		exit(1);
	}
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	mlx_destroy_display(d->mlx_ptr);
	free_data(d);
	return (0);
}

int validate_input(int ac, char **av)
{
	if (ac != 2)
	{
		write (2, "Error\n" 6);
		return (1);
	}
	if (access(av[1], X_OK) != -1)
	{
		perror(av[1]);
		return (2);	
	}
	
}