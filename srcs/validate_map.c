/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:31:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/08 16:20:12 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"
#include <stdio.h>

static int		get_sizes_xy(char *file, t_map *map);
static char		**get_map_copy(char *file, t_map *map);
static int		check_borders(char **map_copy, t_map *map);
static int		check_requirements(char **map_copy, t_map *map);
void			add_stats(t_map *map, int stat);

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
	if (check_borders(map_copy, map) != 0)
		return (3);
	return (check_requirements(map_copy, map));
	return (0);
}

static int	get_sizes_xy(char *file, t_map *map)
{
	int			i;
	int			fd;
	char		*buffer;
	size_t		len;

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

static char	**get_map_copy(char *file, t_map *map)
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
		i++;
	}
	close (fd);
	return (map_copy);
}

static int	check_borders(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		if (i == 0 || (i == map->size_y - 1 && i != 0))
		{
			while (j < map->size_x && map_copy[i][j] == WALL)
				j++;
			if (j != map->size_x - 1)
				return (ft_error(WALLS), 1);
		}
		else
		{
			while (j < map->size_x - 1)
			{
				if ((j == 0 || j == map->size_x - 2) && map_copy[i][j] != WALL)
					return (ft_error(WALLS), 1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

static int	check_requirements(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (map_copy[i][j] != '\n')
		{
			if (map_copy[i][j] == WALL || map_copy[i][j] == SPACE)
				j++;
			else if (map_copy[i][j] == COLL || map_copy[i][j] == EXITS || \
			map_copy[i][j] == PLAYERS)
			{
				add_stats(map, map_copy[i][j]);
				j++;
			}
			else
				break ;
		}
		i++;
	}
	if (map->collectibles < 1 || map->exit != 1 || map->player != 1)
		return (4);
	return (0);
}

void	add_stats(t_map *map, int stat)
{
	if (stat == COLL)
		map->collectibles++;
	else if (stat == EXITS)
		map->exit++;
	else if (stat == PLAYERS)
		map->player++;
}



