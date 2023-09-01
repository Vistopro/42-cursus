/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:25:06 by vicrodri          #+#    #+#             */
/*   Updated: 2023/07/26 12:42:10 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	ft_play(t_map *map)
{
	map->mlx = mlx_init(map->width * 64, map->height * 64, "so_long", false);
	map->player_t = mlx_load_png("./images/piggy.png");
	map->player_i = mlx_texture_to_image(map->mlx, map->player_t);
	map->playerizq_t = mlx_load_png("./images/piggyizq.png");
	map->playerizq_i = mlx_texture_to_image(map->mlx, map->playerizq_t);
	map->wall_t = mlx_load_png("./images/wall.png");
	map->wall_i = mlx_texture_to_image(map->mlx, map->wall_t);
	map->exit_t = mlx_load_png("./images/bank.png");
	map->exit_i = mlx_texture_to_image(map->mlx, map->exit_t);
	map->floor_t = mlx_load_png("./images/floor.png");
	map->floor_i = mlx_texture_to_image(map->mlx, map->floor_t);
	map->collectible_t = mlx_load_png("./images/cash.png");
	map->collectible_i = mlx_texture_to_image(map->mlx, map->collectible_t);
	mlx_delete_texture(map->player_t);
	mlx_delete_texture(map->playerizq_t);
	mlx_delete_texture(map->wall_t);
	mlx_delete_texture(map->exit_t);
	mlx_delete_texture(map->floor_t);
	mlx_delete_texture(map->collectible_t);
	ft_checkpath(map);
	ft_fillmap(map);
	mlx_key_hook(map->mlx, &hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
}

void	ft_move(t_map *map)
{
	if (map->map[map->newyplayer][map->newxplayer] == 'C')
		map->collectible--;
	if (map->map[map->newyplayer][map->newxplayer] == 'C'
		|| map->map[map->newyplayer][map->newxplayer] == '0')
	{
		map->movements++;
		ft_printf("Moves: %d\n", map->movements);
		map->map[map->yplayer][map->xplayer] = '0';
		map->xplayer = map->newxplayer;
		map->yplayer = map->newyplayer;
		map->map[map->yplayer][map->xplayer] = 'P';
	}
	if (map->map[map->newyplayer][map->newxplayer] == 'E'
		&& map->collectible == 0)
	{
		ft_putstr_fd("You win!\n", 1);
		ft_free(map);
		exit(0);
	}
	mlx_image_to_window(map->mlx, map->floor_i, map->xplayer * 64,
		map->yplayer * 64);
	mlx_image_to_window(map->mlx, map->floor_i, map->xplayer * 64,
		map->yplayer * 64);
	ft_fillmap2(map);
}
