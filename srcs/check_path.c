/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:28:01 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/14 10:33:04 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	flood_fill(int x_pos, int y_pos, char **map_copy, t_map *map);
static char	**copy_map(char **map_to_copy, t_map *map);

int	check_path(char **map_copy, t_map *map)
{
	char	**fill_map;

	fill_map = copy_map(map_copy, map);
	if (!fill_map)
		return (1);
	map->collectibles_fill = map->collectibles;
	map->exit_fill = map->exit;
	if (flood_fill(map->start.x_pos, map->start.y_pos, fill_map, map) != 0)
	{
		free_2d_array_of_size(fill_map, map->size_y);
		return (1);
	}
	free_2d_array_of_size(fill_map, map->size_y);
	return (0);
}

static char	**copy_map(char **map_to_copy, t_map *map)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = (char **) malloc ((map->size_y) * sizeof(char *));
	if (!map_copy)
		return (ft_error(MLC), NULL);
	while (i < map->size_y)
	{
		map_copy[i] = ft_strdup(map_to_copy[i]);
		i++;
	}
	return (map_copy);
}

static int	flood_fill(int x_pos, int y_pos, char **map_copy, t_map *map)
{
	if (map->collectibles_fill == 0 && map->exit_fill == 0)
		return (0);
	if (map_copy[y_pos][x_pos] == WALLS || map_copy[y_pos][x_pos] == FILL)
		return (1);
	if (map_copy[y_pos][x_pos] == COLL)
		map->collectibles_fill--;
	if (map_copy[y_pos][x_pos] == EXITS)
		map->exit_fill--;
	map_copy[y_pos][x_pos] = FILL;
	if (flood_fill(x_pos - 1, y_pos, map_copy, map) == 0
		|| flood_fill(x_pos, y_pos - 1, map_copy, map) == 0
		|| flood_fill(x_pos + 1, y_pos, map_copy, map) == 0
		|| flood_fill(x_pos, y_pos + 1, map_copy, map) == 0)
		return (0);
	return (1);
}
