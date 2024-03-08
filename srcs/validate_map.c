/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:31:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/08 11:05:00 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int		get_sizes_xy(char *file, t_map *map);
char	**get_map_copy(char *file, t_map *map);
int		check_borders(char **map_copy, t_map *map);

int	validate_map(char *file, t_map *map)
{
	char	**map_copy;

	if (get_sizes_xy(file, map) != 0)
		return (1);
	if (map->size_x * TEXTURE_SIZE > map->max_x || \
	map->size_y * TEXTURE_SIZE > map->max_y)
		return (ft_error(OS_MAP), 1);
	map_copy = get_map_copy(file, map);
	if (map_copy == NULL)
		return (2);
	check_walls(map_copy, map);
	check_requirements(map_copy, map);
	return (0);
}

int	get_sizes_xy(char *file, t_map *map)
{
	int		i;
	int		fd;
	char	*buffer;
	int		len;

	len = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error(FIL), 1);
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		if (ft_strlen(buffer) > len)
			len = ft_strlen(buffer);
		i++;
		free(buffer);
	}
	close (fd);
	map->size_y = i;
	map->size_x = len;
	return (0);
}

char	**get_map_copy(char *file, t_map *map)
{
	char	*buffer;
	char	**map_copy;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error(FIL), NULL);
	map_copy = (char **) malloc (map->size_y * sizeof(char *));
	if (!map_copy)
		return (ft_error(MLC), NULL);
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		map_copy[i] = ft_strdup(buffer);
		free(buffer);
	}
	close (fd);
	return (map_copy);
}

int	check_borders(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		if (i == 0 || i == map->size_y - 1)
		{
			while (j < map->size_x && map_copy[i][j] == "\n")
				j++;
			if (j != map->size_x)
				return (ft_error(WALLS), 1);
		}
		else
		{
			if ((j == 0 || j == map->size_x - 1) && map_copy[i][j] != WALL)
				return (ft_error(WALLS), 1);
		}
		i++;
	}
	return (0);
}

int	check_requirements(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!map_copy[i])
	{
		while (map_copy[i][j] != '\0')
		{
			if (map_copy[i][j] == WALL || map_copy[i][j] == SPACE)
				j++;
			else if ((map_copy[i][j] == COLL && ++map->collectibles) || \
			(map_copy[i][j] == EXITS && ++map->exit) || \
			(map_copy[i][j] == PLAYERS && ++map->player))
				j++;
			else
				return (ft_error(OS_MAP), 3);
		}
		i++;
	}
	if (map->collectibles < 1 || map->exit != 1 || map->player != 1)
		return (4);
	return (0);
}



