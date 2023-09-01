/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:42:17 by vicrodri          #+#    #+#             */
/*   Updated: 2023/07/26 11:21:30 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_check_cr(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_files(char **argv, t_map *map)
{
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		return (ft_error(ERROR_MAP), 0);
	else if (map->fd == -1)
		return (close(map->fd),
			ft_error(ERROR_MAP_NOT_ACCESSIBLE), 0);
	return (1);
}

int	ft_checkmap_rectangle(char **argv, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j])
		{	
			if (i == 0 || j == 0 || i == map->height - 1
				|| j == map->width - 1)
				if (map->map[i][j] != '1')
					return (ft_free(map), ft_error(ERROR_MAP_NOT_CLOSED), 0);
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'C' && map->map[i][j] != 'E'
				&& map->map[i][j] != 'P' && map->map[i][j] != 'L')
				return (ft_free(map), ft_error(ERROR_MAP), 0);
			j++;
		}
		if (j != map->width)
			return (ft_free(map), ft_error(ERROR_MAP_NOT_RECTANGULAR), 0);
	}
	return (1);
}

int	ft_check_map(char **argv, t_map *map)
{
	ft_calc_rectangle(map);
	if (ft_checkmap_rectangle(argv, map) == 0)
		return (ft_free(map), 0);
	if (map->player != 1 || map->exit != 1 || map->collectible == 0)
		return (ft_free(map), ft_error(ERROR_MAP), 0);
	return (1);
}

int	ft_map(char **argv, t_map *map)
{
	char	*buf;
	char	*line;

	buf = 0;
	line = 0;
	map->fd = open(argv[1], O_RDONLY);
	if (ft_check_files(argv, map) == 0)
		return (0);
	while (1)
	{
		buf = get_next_line(map->fd);
		if (buf == NULL)
			break ;
		line = ft_strjoin(line, buf);
		free(buf);
	}
	if (ft_strlen(line) == 0 || ft_check_cr(line) == 0)
		return (free(line), ft_error(ERROR_MAP), 0);
	map->map = ft_split(line, '\n');
	map->map_copy = ft_split(line, '\n');
	close(map->fd);
	free(line);
	free(buf);
	return (1);
}
