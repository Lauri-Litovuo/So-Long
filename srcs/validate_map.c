/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:31:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/13 13:59:29 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int		check_borders(char **map_copy, t_map *map);
static int		check_requirements(char **map_copy, t_map *map);
void			add_stats(t_map *map, int stat, int i, int j);

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
	if (check_requirements(map_copy, map) != 0)
		return (ft_error(REQ), 1);
	if (check_paths(map_copy, map) != 0)
		return (ft_error(PATH), 1);
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
			if (j != map->size_x - 1)
				return (ft_error(WALLS), 1);
		}
		else
		{
			while (j < map->size_x - 1)
			{
				if ((j == 0 || j == map->size_x - 2) && map_copy[i][j] != WALL)
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
				add_stats(map, map_copy[i][j], i, j);
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

void	add_stats(t_map *map, int stat, int i, int j)
{
	if (stat == COLL)
		map->collectibles++;
	else if (stat == EXITS)
		map->exit++;
	else if (stat == PLAYERS)
	{
		map->player++;
		map->start.y_pos = i;
		map->start.x_pos = j;
	}
}



