/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:31:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/25 14:48:08 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

static int		check_borders(char **map_copy, t_map *map);
static int		check_requirements(char **map_copy, t_map *map);
void			add_stats(t_map *map, int stat, int i, int j);

int	validate_map(char *file, t_map *map)
{
	if (get_sizes_xy(file, map) != 0)
		return (1);
	map->map_copy = get_map_copy(file, map);
	if (map->map_copy == NULL)
		return (1);
	if (check_borders(map->map_copy, map) != 0)
		return (free_2d_array_of_size(map->map_copy, map->size_y), 3);
	if (check_requirements(map->map_copy, map) != 0)
	{
		free_2d_array_of_size(map->map_copy, map->size_y);
		return (ft_error(REQ), 4);
	}
	if (check_path(map->map_copy, map) != 0)
	{
		free_2d_array_of_size(map->map_copy, map->size_y);
		return (ft_error(PATH), 1);
	}
	return (0);
}

static int	check_borders(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->size_y)
	{
		j = 0;
		if (i == 0 || (i == map->size_y - 1 && i != 0))
		{
			while (j < map->size_x && map_copy[i][j] == WALL)
				j++;
			if (j != map->size_x)
				return (ft_error(WALLS), 1);
		}
		else
		{
			while (j < map->size_x)
			{
				if ((j == 0 || j == map->size_x - 1) && map_copy[i][j] != WALL)
					return (ft_error(RECT), 1);
				j++;
			}
		}
	}
	return (0);
}

static int	check_requirements(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->size_y)
	{
		j = 0;
		while (map_copy[i][j] != '\0')
		{
			if (map_copy[i][j] == COLL || map_copy[i][j] == EXITS || \
			map_copy[i][j] == PLAYER)
				add_stats(map, map_copy[i][j], i, j);
			else if (ft_strchr(SET, map_copy[i][j]) == NULL &&
			map_copy[i][j] != '\0' && map_copy[i][j] != '\n')
				return (1);
			else if (map_copy[i][j] == '\0')
				break ;
			j++;
		}
	}
	if (map->collectibles < 1 || map->exit != 1 || map->player != 1)
		return (2);
	return (0);
}

void	add_stats(t_map *map, int stat, int i, int j)
{
	if (stat == COLL)
		map->collectibles++;
	else if (stat == EXITS)
		map->exit++;
	else if (stat == PLAYER)
	{
		map->player++;
		map->y_pos = i;
		map->x_pos = j;
	}
}
