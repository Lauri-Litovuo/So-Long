/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:01:18 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/18 10:32:28 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int		validate_input(int ac, char **av);
static t_data	*init_data(void);
void			create_game_window(t_data *data);

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data();
	if (validate_input(ac, av) != 0 || validate_map(av[1], data->map_ptr) != 0)
		exit (1);
	create_game_window(data);
	return (0);
}

static t_data	*init_data(void)
{
	t_data	*data;

	data = malloc (sizeof(t_data));
	if (!data)
		exit (1);
	data->map_ptr = malloc (sizeof(t_map));
	if (!data)
		exit (1);
	data->map_ptr->collectibles = 0;
	data->map_ptr->collectibles_fill = 0;
	data->map_ptr->exit = 0;
	data->map_ptr->exit_fill = 0;
	data->map_ptr->player = 0;
	data->map_ptr->size_x = 0;
	data->map_ptr->size_y = 0;
	data->map_ptr->start.x_pos = 0;
	data->map_ptr->start.x_pos = 0;
	data->map_ptr->map_copy = NULL;
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

void	create_game_window(t_data *data)
{
	data->mlx_ptr = mlx_init(data->map_ptr->size_x * TEXTURE_SIZE, \
	data->map_ptr->size_y * TEXTURE_SIZE, "The moving day", false);
	if (data->mlx_ptr == NULL)
		exit (1);
	mlx_get_monitor_size(0, data->map_ptr->max_x, data->map_ptr->max_y);
	if (data->map_ptr->size_x * TEXTURE_SIZE > data->map_ptr->max_x
		|| data->map_ptr->size_y * TEXTURE_SIZE > data->map_ptr->max_y)
	{
		ft_error(OS_MAP);
		free_and_exit(data);
	}
	data->win_ptr = \
	mlx_new_image(data->mlx_ptr, data->map_ptr->size_x, data->map_ptr->size_y);
	if (!data->win_ptr)
		free_and_exit(data);
	init_textures();
	init_image();
	map_setup();
	mlx_key_hook(data->mlx_ptr, &key_setup, data);
	mlx_loop(data->mlx_ptr);
	mlx_close_window(data->mlx_ptr);
	free_data(data);
	mlx_terminate(data->mlx_ptr);
}



