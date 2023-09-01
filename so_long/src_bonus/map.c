/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:41:09 by vicrodri          #+#    #+#             */
/*   Updated: 2023/09/01 14:10:03 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_img(t_map *map, mlx_image_t	*mlx_i, int j, int i)
{
	mlx_image_to_window(map->mlx, mlx_i, j * 64, i * 64);
}

static void	ft_fillpath(t_map *map, int x, int y)
{
	if (map->map_copy[y][x] == 'E')
	{
		map->map_copy[y][x] = '1';
		return ;
	}
	map->map_copy[y][x] = '1';
	if (map->map_copy[y + 1][x] != '1' && map->map_copy[y + 1][x] != 'L')
		ft_fillpath(map, x, y + 1);
	if (map->map_copy[y - 1][x] != '1' && map->map_copy[y - 1][x] != 'L')
		ft_fillpath(map, x, y - 1);
	if (map->map_copy[y][x + 1] != '1' && map->map_copy[y][x + 1] != 'L')
		ft_fillpath(map, x + 1, y);
	if (map->map_copy[y][x - 1] != '1' && map->map_copy[y][x - 1] != 'L')
		ft_fillpath(map, x - 1, y);
}

void	ft_checkpath(t_map *map)
{
	int	i;

	i = 0;
	ft_fillpath(map, map->xplayer, map->yplayer);
	while (map->map_copy[i])
	{
		if (ft_strchr(map->map_copy[i], 'E')
			|| ft_strchr(map->map_copy[i], 'C'))
			ft_error(ERROR_MAP_NOT_PATH);
		i++;
	}
	i = 0;
	while (map->map_copy[i])
	{
		free(map->map_copy[i]);
		i++;
	}
	free(map->map_copy);
}

void	ft_fillmap(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			ft_fillmap3(map, i, j);
	}
}

void	ft_fillmap2(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if ((map->map[i][j] == 'P' && map->direction == 1)
				|| (map->map[i][j] == 'P' && map->map[i][j + 1] == '1'
					&& map->movements == 0))
				ft_img(map, map->player_i, map->xplayer, map->yplayer);
			else if (map->map[i][j] == '0')
				ft_img(map, map->floor_i, j, i);
			else if (map->map[i][j] == 'P' && map->direction == 0)
				ft_img(map, map->playerizq_i, map->xplayer, map->yplayer);
		}
	}
}
