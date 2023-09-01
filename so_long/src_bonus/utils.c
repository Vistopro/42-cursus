/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:25:06 by vicrodri          #+#    #+#             */
/*   Updated: 2023/07/26 11:48:40 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_error(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	ft_free(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	hook(mlx_key_data_t key_data, void *param)
{
	t_map	*map;

	map = param;
	map->newxplayer = map->xplayer;
	map->newyplayer = map->yplayer;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_RELEASE)
		exit(0);
	else if (key_data.key == MLX_KEY_UP && key_data.action == MLX_RELEASE)
		map->newyplayer --;
	else if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_RELEASE)
		map->newyplayer ++;
	else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_RELEASE)
	{
		map->newxplayer --;
		if (map->direction == 0)
			map->direction = 1;
	}
	else if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_RELEASE)
	{
		map->newxplayer ++;
		if (map->direction == 1)
			map->direction = 0;
	}
	ft_move(map);
	return ;
}
