/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:55:07 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/20 13:20:43 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	get_sizes_xy(char *file, t_map *map)
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
	map->size_x = len - 1;
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
		i++;
	}
	close (fd);
	return (map_copy);
}
