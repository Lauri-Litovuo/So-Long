/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:01:18 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/07 17:52:26 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	validate_input(int ac, char **av);

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit (1);
	mlx_get_screen_size(data.mlx_ptr, map.max_x, map.max_y);
	if (validate_input(ac, av) != 0 || validate_map(av[1], &map) != 0)
		exit (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, map.size_x, map.size_y, "so_long");
	if (data.win_ptr)
	{
		free_data(data);
		free_map(map);
		exit(1);
	}
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free_data(data);
	free_map(map);
	return (0);
}

static int	validate_input(int ac, char **av)
{
	char	*temp;

	if (ac != 2)
	{
		write (2, "Invalid amount of arguments\n", 28);
		return (1);
	}
	if (av[1][0] == '\0')
	{
		write(2, "Error: empty argument\n", 22);
		return (2);
	}
	temp = ft_strnstr(av[1], ".ber", ft_strlen(av[1]));
	if (temp == NULL || ft_strlen(temp) != 4)
	{
		write(2, "Error: argument is not .ber\n", 28);
		return (3);
	}
	if (access(av[1], F_OK) != 0 || access(av[1], R_OK) != 0)
	{
		perror(av[1]);
		return (4);
	}
	return (0);
}

