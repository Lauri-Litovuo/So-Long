/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:47:45 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/25 15:26:53 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

static int		validate_input(int ac, char **av);
static t_data	*init_data(void);
void			create_game_window(t_data *data);

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data();
	if (validate_input(ac, av) != 0 || validate_map(av[1], data->map) != 0)
		exit (1);
	create_game_window(data);
	free_data(data);
	return (0);
}

static t_data	*init_data(void)
{
	t_data	*data;

	data = malloc (sizeof(t_data));
	if (!data)
		exit (1);
	data->map = malloc (sizeof(t_map));
	if (!data)
		exit (1);
	data->map->collectibles = 0;
	data->map->collectibles_fill = 0;
	data->map->exit = 0;
	data->map->exit_fill = 0;
	data->map->player = 0;
	data->map->size_x = 0;
	data->map->size_y = 0;
	data->map->x_pos = 0;
	data->map->x_pos = 0;
	data->map->map_copy = NULL;
	return (data);
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
		ft_error(BER);
		return (3);
	}
	if (access(av[1], F_OK) != 0 || access(av[1], R_OK) != 0)
	{
		perror(av[1]);
		return (4);
	}
	return (0);
}

void	create_game_window(t_data *data)
{
	data->mlx = mlx_init(data->map->size_x * TXT_SIZE, \
	(data->map->size_y + 1) * TXT_SIZE, "The moving day", false);
	if (data->mlx == NULL)
		exit (1);
	mlx_get_monitor_size(0, &data->map->max_x, &data->map->max_y);
	if (data->map->size_x * TXT_SIZE > data->map->max_x
		|| (data->map->size_y + 1) * TXT_SIZE > data->map->max_y)
	{
		ft_error(OS_MAP);
		free_and_exit(data);
	}
	data->win = \
	mlx_new_image(data->mlx, data->map->size_x, data->map->size_y);
	if (!data->win)
		free_and_exit(data);
	init_textures(data);
	init_images(data);
	create_floor(data);
	create_objects(data);
	create_player(data);
	mlx_key_hook(data->mlx, &key_hooking, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
