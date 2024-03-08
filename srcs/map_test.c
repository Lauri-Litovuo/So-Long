/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:06:57 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/08 14:19:55 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	validate_input(int ac, char **av);

int	main(int ac, char **av)
{
	t_map	map;
	int		exitc;

	map.max_x = 1980;
	map.max_y = 1080;
	if (validate_input(ac, av) != 0)
		exit (1);
	exitc = validate_map(av[1], &map);
	return (exitc);
}

static int	validate_input(int ac, char **av)
{
	char	*temp;

	if (ac != 2)
	{
		write (2, "Invalid amount of arguments\n", 28);
		return (1);
	}
	/*if (av[1][0] == '\0')
	{
		write(2, "Error: File argument empty\n", 22);
		return (2);
	}*/
	temp = ft_strnstr(av[1], ".ber", ft_strlen(av[1]));
	if (temp == NULL || ft_strlen(temp) != 4)
	{
		write(2, "Error\nMap file extension must be .ber\n", 38);
		return (3);
	}
	if (access(av[1], F_OK) != 0)
	{
		write(2, "Error\nFile not found.\n", 22);
		return (4);
	}
	if (access(av[1], R_OK) != 0)
	{
		write(2, "Error\nFile permission.\n", 23);
		return (4);
	}
	return (0);
}
